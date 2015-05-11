//=========================================================
// Tetris engine by Mikle_Bond
//
// Here is basics functions, which would be called for
// each frame.
// Result at the end of working is an array of the current
// state.
//

#include <stdlib.h>
#include <stdio.h>
#include "tetriminos_maps.h"
#include "kernel_types.h"
#include "score_system.h"

// offsets to the directions
offset offst[4] = {
    { .x =  1, .y =  0 },
    { .x =  0, .y = -1 },
    { .x = -1, .y =  0 },
    { .x =  0, .y =  1 }
};

// array of the particles' maps
const tetrimino *types[7] = {
    &tet_B_map,
    &tet_L_map,
    &tet_J_map,
    &tet_S_map,
    &tet_Z_map,
    &tet_I_map,
    &tet_T_map
};

/* global matrix 24x10 pixels
 * plus 4 rows on the top
 * plus two rows and colums on the bottom-right
 * plus one row and column on the top-left
 */
matrix glob_map = { };
// active zone:   [height_T]  [width_L] .. [height_B][width_R]
// sevice zone:   [height_T]  [width_L] ..    [4]    [width_R]
// visible:     [height_T + 4][width_L] .. [height_B][width_R]

const int width_L   =   1;
const int width_R   =   10;
const int height_T  =   1;
const int height_B  =   32;

/* global struct for currently avaluable
 * particle, with all its parameters
 */
particle curr;

/* Stuct of stases of each line in the (glob_map).
 */
row_filler row_index;

//====[ WITERS ]===========================================

// Read (row_index)
char get_row_state (char number)
{
    row_filler mask = 0x1 << (row_filler) number;
    mask &= row_index;
    return !!mask;
}

// Write (row_index)
void set_row_state (char number, char value)
{
    if (value)
        row_index |= 0x1 << (row_filler) number;
    else
        row_index &= ~(0x1 << (row_filler) number);
}

// Access (part_map)
inline atom_pixel part_map (const atom_pixel *map, int i, int j)
{
    return *((atom_pixel *)(map + i * 4 + j));
}

// Writing (val) in (glob_map) using (map)
void glob_write (const atom_pixel *map, int x, int y, atom_pixel val)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (part_map(map, i, j)) {
                glob_map[x + i][y + j] = val;
            }
        }
    }
}

// Deleting row in (glob_map)
void clear_row (int row)
{
    int i = row;
    int j;
    for (; i > height_T + 1; --i) {
        for (j = width_L; j <= width_R; ++j) {
            glob_map[i][j] = glob_map[i - 1][j];
        }
    }
    set_row_state(row, 0);
    send_event(line_clear);
}

// Deleting all full rows
void clear_all_rows ()
{
    int i = 0;
    for (i = height_T; i < height_B; ++i) {
        if (get_row_state(i))
            clear_row(i);
    }
}

//====[ CREATORS ]=========================================

// Creating new particle in the service zone
void tet_create (tet_num type, direction angle)
{
    const atom_pixel *map = &(types[type]->rotation[angle][0][0]);

    curr.pos.x = height_T;
    curr.pos.y = width_L + 3;
    curr.type = type;
    curr.angle = angle;
    curr.PID += 1;

    glob_write(map, curr.pos.x, curr.pos.y, curr.type);
}

//====[ CHECKERS ]=========================================

// The most powerful check
err_move duo_check (
        int type1, int x1, int y1, int angle1,
        int type2, int x2, int y2, int angle2)
{

    const atom_pixel *map1 = &(types[type1]->rotation[angle1][0][0]);
    const atom_pixel *map2 = &(types[type2]->rotation[angle2][0][0]);

    int i2 = 0, j2 = 0; // refer to (map2)
    int i1 = 0, j1 = 0; // refer to (map1)

    // boolean var - is movement possible
    err_move result = tea_cup;

    // for ( i1, j1 in (map1) ) do
    while (!result && i2 < 4) {

        j2 = 0;
        while (!result && j2 < 4) {


            // placeing pixel from (map2)
            if (part_map(map2,i2,j2)) {

                // is there owerflow from the [active zone]?
                if (x2 + i2 > height_B) {
                    // from the bottom
                    result = ovflw_B;
                } else if (y2 + j2 < width_L) {
                    // from the left
                    result = ovflw_L;
                } else if (y2 + j2 > width_R) {
                    // from the right
                    result = ovflw_R;
                } /*else if (x2 + i2 > height_T) {
                    // WILL BE DELETED, 'COS NOT POSSIBLE
                    // yet
                    result = ovflw_T;
                }*/ else {
                    // is there placed pixel already?
                    if (glob_map[x2 + i2][y2 + j2]) {
                        i1 = x2 + i2 - x1;
                        j1 = y2 + j2 - y1;
                        // is this part of (map1)?
                        if (i1 >= 0 && j1 >= 0 && i1 < 4 && j1 < 4
                                && part_map(map1,i1,j1)) {

                            // hothing to do here
                        } else {
                            // movement is anavaliable
                            result = flood_anoter;
                        }
                    }
                }
            }
            j2 += 1;
        }
        i2 += 1;
    }

    return result;

}

// Changing current particle
inline err_move single_check (
        int type2, int x2, int y2, int angle2)
{
    return duo_check(curr.type, curr.pos.x, curr.pos.y, curr.angle,
                     type2,     x2,         y2,         angle2);
}

// Try to move current particle to spcific direction
inline err_move ofst_check (direction d)
{
    return single_check (
                curr.type,
                curr.pos.x + offst[d].x,
                curr.pos.y + offst[d].y,
                curr.angle);
}

// Try to rotate current particle
inline err_move rtte_check (int angle)
{
    return single_check (
                curr.type,
                curr.pos.x,
                curr.pos.y,
                angle);
}

// Check line is full
void row_check (int row)
{
    int i = width_L;
    row += height_T;
    while (i <= width_R && glob_map[row][i] != 0) {
        i += 1;
    }
    if (i > width_R) {
        set_row_state(row - height_T, 1);
    } else {
        set_row_state(row - height_T, 0);
    }
}


//====[ MOVERS ]===========================================

// Moveing according the direction
err_move tet_move (direction d)
{
    int res = ofst_check(d);

    if (res != tea_cup) {
        // TODO: Changing flags.
        return res;
    }

    const atom_pixel *map = &(types[curr.type]->rotation[curr.angle][0][0]);

    int x = curr.pos.x;
    int y = curr.pos.y;

    // remove particle
    glob_write(map, x, y, 0);

    // move particle
    x += offst[d].x;
    y += offst[d].y;

    // place particle
    glob_write(map, x, y, curr.type);

    // write info to the particle
    curr.pos.x = x;
    curr.pos.y = y;

    return tea_cup;
}

// Rotating particle for 90 deg. right (+1) or left (-1)
err_move tet_rotate (int side)
{
    // angle += side
    int angle = curr.angle + side;
    if (angle == -1)
        angle = 3;
    else if (angle == 4)
        angle = 0;

    const atom_pixel *map1 = &(types[curr.type]->rotation[curr.angle][0][0]);
    const atom_pixel *map2 = &(types[curr.type]->rotation[angle][0][0]);

    err_move res = rtte_check(angle);

    if (res == tea_cup) {
        // the most often situation
        glob_write(map1, curr.pos.x, curr.pos.y, 0);
        glob_write(map2, curr.pos.x, curr.pos.y, curr.type);

        curr.angle = angle;

        /* Next, there are a few checks for situations,
         * when tetrimino is near the wall, and can'n
         * just been rotated as is, e.g. the 'I' stick
         * near the edge of screen.
         * To solve this situation, we trying to swap it
         * a little to the opposite side. It will make
         * gameplay clearlier, I hope...
         */
    } else if (res == ovflw_B) {
        if (tea_cup == single_check(
                    curr.type,
                    curr.pos.x - 1,
                    curr.pos.y,
                    angle)) {
            glob_write(map1, curr.pos.x, curr.pos.y, 0);
            curr.pos.x -= 1;
            curr.angle = angle;
            glob_write(map2, curr.pos.x, curr.pos.y, curr.type);
        } else {
            return res;
        }
    } else if (res == ovflw_L) {
        if (tea_cup == single_check(
                    curr.type,
                    curr.pos.x,
                    curr.pos.y + 1,
                    angle)) {
            glob_write(map1, curr.pos.x, curr.pos.y, 0);
            curr.pos.y += 1;
            curr.angle = angle;
            glob_write(map2, curr.pos.x, curr.pos.y, curr.type);
        } else {
            return res;
        }
    } else if (res == ovflw_R) {
        if (tea_cup == single_check(
                    curr.type,
                    curr.pos.x,
                    curr.pos.y - 1,
                    angle)) {
            glob_write(map1, curr.pos.x, curr.pos.y, 0);
            curr.pos.y -= 1;
            curr.angle = angle;
            glob_write(map2, curr.pos.x, curr.pos.y, curr.type);
        } else {
            return res;
        }
    }
    return res;
}

// Place and stabialize (curr)
void tet_stop ()
{
    int i = curr.pos.x - height_T;
    int p = (curr.pos.x + 3 > height_B ? height_B : curr.pos.x + 3);
    while (i <= p) {
        row_check(i);
    }
    curr.pos.x = 0;
    curr.pos.y = 0;
    send_event(placing);
}

//====[ DEBUG ]============================================

void dbg_dump ()
{
    int i, j;
    for (i = 0; i < 35; i++) {
        for (j = 0; j < 12; j++) {
             printf("%d", glob_map[i][j]);
        }
        printf("\r\n");
    }
}
