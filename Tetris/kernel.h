//=========================================================
// Kernel header

#ifndef KERNEL
#define KERNEL

#include "kernel_types.h"
#include "score_system.h"

/*
struct flags {
    char LINE_FULL          : 1;
    char PARTICLE_STABLE    : 1;
    char TEMP_FLAG_1        : 1;
    char TEMP_FLAG_2        : 1;
} flag;
*/

//---------------------------------------------------------
// Create new tetrimino on the top
extern void tet_create (tet_num type, direction angle);
/* Usage:
 *      Placeing new particle at the service
 *      zone and changes cintrol to the new one
 * Example:
 *      create (tet_I, left);
 *      create (rand() % 4, rand() % 4); // not recommended
 */

//---------------------------------------------------------
// Move falling particle
extern err_move tet_move (direction d);
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

//---------------------------------------------------------
// Rotate the particle
extern err_move tet_rotate (int side);
/* Usage:
 *      Will try to rotate current particle, and if it
 *      is possible - will rotate it. Else - non-zero
 *      value will be returned.
 *      Arguments is +1 to rotate right and -1 to left
 *
 * Example:
 *      rotate (1);
 */

//---------------------------------------------------------
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

// Constants to divide (glob_map)
extern const int width_L;
extern const int width_R;
extern const int height_T;
extern const int height_B;

//---------------------------------------------------------
// Place and stabialize (curr)
extern void tet_stop ();
/* Usage:
 *      Needs to be called at the end of falling.
 *      Normally, it should be called when move(down)
 *      returns non-zero value.
 *      After calling, controling current tetrimino would
 *      be not possible, until create(...) is called.
 *      Also, clear_all_lines() is avaluable only after
 *      this function.
 */

//---------------------------------------------------------
// Deleting all full rows
extern void clear_all_rows ();
/* Usage:
 *      Deleting all fulfiled rows from the global map.
 *      Should be called only after tet_stop().
 */

//---------------------------------------------------------
// Check the state of line 
extern char get_row_state (char number);
/* Usage:
 *      Returns state of line's fulfillness by its nmber.
 *      Here (number) is allowed oly from (height_T)
 *      to (height_B).
 * Example:
 *      get_row_state (height_T + row);
 */

//---------------------------------------------------------
// Sets state of the row to (value)
extern void set_row_state (char number, char value);
/* Usage:
 *      WARNING: Not recommended to use it.
 *
 *      Set the row state to 0, if it is not filled,
 *      and 1, in the other case.
 */


//---------------------------------------------------------
// Save section
//---------------------------------------------------------
extern particle curr;
extern row_filler row_index;

/// DBG
extern void dbg_dump ();

#endif // KERNEL

