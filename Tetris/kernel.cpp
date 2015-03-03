//=========================================================
// Tetris engine by Mikle_Bond
//
// Here is basics functions, which would be called for
// each frame.
// Result at the end of working is an array of the current
// state.
//

#include "tetriminos_maps.h"

atom_pixel glob_map[32][10] = { 0 };

particle current = {0};

// checking avaliability of moveing
int check (direction d) {
    int x = current.position.x;
    int y = current.position.y;
    int i = 0, j = 0;
    int ox = offsets[d].x, oy = offsets[d].y;

    atom_pixel part_map[4][4] = particles[current.type].rotation[current.angle];

    int result = 1;

    while (result && i < 4) {
        while (result && j < 4) {
            // placeing pixel from [i][j]
            if (map[i][j]) {
                // is this avaliable
                if (glob_map[x + i + ox][y + j + oy]) {
                    // is this part of current
                    i -= ox; j -= oy;       // offseting backward
                    if (i >= 0 && j >= 0 && i < 4 && j < 4 && !part_map[i][j]) {
                        // movement is anavaliable
                        result = 0;
                    }
                    i += ox; j += oy;       // offseting forward
                }
            }
            i += 1; j += 1;
        }
    }

    return result;
}

// Moveing according the direction
// [ WARN ] Chacking first!
void Move (direction d)
{
    int x = current.position.x;
    int y = current.position.y;
    int i = 0, j = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            glob_map[x + i][y + j] = 0;
        }
    }

    x += offsets[d].x;
    y += offsets[d].y;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            glob_map[x + i][y + j] = 1;
        }
    }
}
