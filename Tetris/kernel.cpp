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

// Moveing according the direction
// [ WARN ] Chacking first!
void Move (direction d)
{
    int x = current.position.x;
    int y = current.position.y;

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
