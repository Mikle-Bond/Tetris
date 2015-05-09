//=========================================================
/* Score system by Mikle_Bond
 *
 * Here are some metods to recount current score
 * according to events, sended by engine, or user.
 * It don't care.
 *
 * To use it there are only metods avaliable.
 */


// Avaluable types of scores
struct scores_{
    int one_line;
    int double_line;
    int triple_line;
    int tetris_line;
    int hard_drop;
    // to be continued;
} scores = { 100, 150, 200, 300, 20 };

// Set up scores
void set_scores (int one, int two, int three, int four, int drop)
{
#define replace(a, b) (a ? a : b)
    scores.one_line = replace(one,   scores.one_line);
    scores.one_line = replace(two,   scores.double_line);
    scores.one_line = replace(three, scores.triple_line);
    scores.one_line = replace(four,  scores.tetris_line);
    scores.one_line = replace(drop,  scores.hard_drop);
#undef replace(a, b)
}

//
