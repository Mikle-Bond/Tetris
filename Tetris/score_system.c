//=========================================================
/* Score system by Mikle_Bond
 *
 * Here are some metods to recount current score
 * according to events, sended by engine, or user.
 * It don't care.
 *
 * To use it there are only metods avaliable.
 */

#include <ss_types.h>

int cleared_lines = 0;
int cleared_score = 0;
int temp_score = 0;
int temp_lines = 0;
int score_multiplier = 1;

// Avaluable types of scores
struct scores_{
    int line[5];
    int hard_drop;
    // to be continued;
} scores = { {10, 100, 200, 300, 400}, 20 };

// Set up scores
void set_values (int place, int one, int two, int three, int four, int drop)
{
#define replace(a, b) b = (a ? a : b)
    replace(place, scores.line[0]);
    replace(one,   scores.line[1]);
    replace(two,   scores.line[2]);
    replace(three, scores.line[3]);
    replace(four,  scores.line[4]);
    replace(drop,  scores.hard_drop);
#undef replace
}

// Listening for events
void send_event (event e)
{
    switch (e) {
    case line_clear:
        temp_lines += 1;
        break;
    case hard_drop:
        temp_score += scores.hard_drop;
        break;
    default:
        break;
    }
}

// Applying effects
void apply_score ()
{
    temp_score += scores.line[temp_lines];
    temp_score *= score_multiplier;
    if (temp_lines >= 1) {
        score_multiplier += 1;
	cleared_lines += temp_lines;    
    } else {
        score_multiplier = 1;
    }
    cleared_score += temp_score;
    temp_score = 0;
    temp_lines = 0;
}

// Set score manualy
void set_score (int value)
{
    cleared_score = value;
}

// Get current value of the score
int get_score ()
{
    return cleared_score;
}

// Set value of cleared manualy
void set_lines (int value)
{
    cleared_lines = value;
}

// Get current value of the cleared lines
int get_lines ()
{
    return cleared_lines;
}
