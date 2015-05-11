#ifndef SCORE_SYSTEM_H
#define SCORE_SYSTEM_H

#include <ss_types.h>

// Set start values for events
extern void set_values (
        int place,  // palce one tetrimino [10 b/d]
        int one,    // clear one line [100 b/d]
        int two,    // clear two lines [200 b/d]
        int three,  // clear three lines [300 b/d]
        int four,   // clear four lines [400 b/d]
        int drop    // place tetrimino with hard drop [20 b/d]
        );

// Send event to the SS
extern void send_event (event e);
/* Possible arguments:
 *      line_clear;
 *      hard_drop;
 *      placing;
 */

// Apply events after each step
extern void apply_score ();

// Set score value manualy
extern void set_score (int value);

// Get current score
extern int get_score ();

#endif // SCORE_SYSTEM_H

