//=========================================================
// Kernel header

#ifndef KERNEL
#define KERNEL

#include "kernel_types.h"

/*
struct flags {
    char LINE_FULL          : 1;
    char PARTICLE_STABLE    : 1;
    char TEMP_FLAG_1        : 1;
    char TEMP_FLAG_2        : 1;
} flag;
*/


// Move falling particle
extern err_move move (direction d);
/* Usage:
 *      Will try to move particle according
 *      to the direction and repace if success.
 *      Possible directions: up, down, left, right.
 *
 *      If 'down' direction used and moving isn't
 *      possible, flag PARTICLE_STABLE switchs on.
 *
 * Example:
 *      move (left);
 *      move (up);    // lol
 */

// Create new tetrimino on the top
extern void create (tet_num type, direction angle);
/* Usage:
 *      Placeing new particle at the service
 *      zone and changes cintrol to the new one
 * Example:
 *      create (tet_I, left);
 *      create (rand() % 4, rand() % 4); // not recommended
 */

// Rotate the particle
extern err_move rotate (int side);

// Global matrix
extern matrix glob_map;
/* global matrix 24x10 pixels
 * plus 4 rows on the top
 * plus two rows and colums on the bottom-right
 * plus one row and column on the top-left
 *
 * active zone:   [height_T]  [width_L] .. [height_B][width_R]
 * sevice zone:   [height_T]  [width_L] ..    [4]    [width_R]
 * visible:     [height_T + 4][width_L] .. [height_B][width_R]
 */

extern const int width_L;
extern const int width_R;
extern const int height_T;
extern const int height_B;

/// DBG
extern particle curr;

extern void dbg_dump ();

#endif // KERNEL

