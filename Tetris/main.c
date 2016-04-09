/// допилить уровни
/// void special_key
/// glutSpecialFunc
/// glut specia keyboard
#include "kernel.h"
#include "tetris_graph.h"
#include <GL/glut.h>
#include <stdio.h>

#define key_left 75
#define key_up 72
#define key_right 77
#define key_down 80
#define esc 27

extern inline void TTimer( void (*timer)(int value));
extern void DrawFigure(unsigned int xPos, unsigned int yPos, tet_num numFigure, direction angle);

void display(void);
void next_tetrimino();
void keyboard(unsigned char key, int x, int y);
void specKeys (unsigned char key, int x, int y);
void frame_function(int);

int LVL = 0;
const int start_interval = 42;
unsigned interval = 42;
int lines_counter = 0;
unsigned int counter_frame = -1;

int exit_stste = -1;
int queue_frame[4][2] = {};

// placeing flags
int deadline = 0;
int rabbit_user = 0;

//// holding flars
//int is_hold_avaliable = 1;
//int hold_num = 0;
//int hold_angle = 0;


void exit_game ()
{
    exit_stste = 0;
}

int main(void)
{
    TChangeColor(rand() % 7 +1, rand() % 14 +7);

    srand( time(NULL) );

    TInit();
    TKeyBoard(&keyboard);
    TSpecial(&specKeys);
    TDisplay(&display);
    //Ttet_createWindow();

    tet_create( ( rand() % 7 +1 ), ( rand() % 4 ) );
    int j_frame = 0;
    for (j_frame = 0; j_frame < 4; j_frame++)
    {
        queue_frame[j_frame][0] = ( rand() % 7 + 1 );
        queue_frame[j_frame][1] = ( rand() % 4 );
    }
    TTimer(frame_function);
    TMainLoop();

    return 0;
}

void frame_function(int val)
{
    int j_frame = 0;
    int t = 0;

    // clear the screen
    DrawScreen();

    // draw the queue
    for (j_frame = 0; j_frame < 4; j_frame++)
    {
        DrawFigure(1, 4 + j_frame * 5, queue_frame[j_frame][0], queue_frame[j_frame][1]);
    }

    // if it is time of the deadline
    if (counter_frame % start_interval == 0)
    {
        deadline += 1;
        rabbit_user += 1;
    }

    // if it is time to move tetrimino down
    if (counter_frame % interval == 0)
    {
        t = tet_move(down);
        // if succed
        if (t == tea_cup)
        {
            deadline = 0;
            rabbit_user = 0;
        }
        else if (deadline > 1)
        {
            next_tetrimino();
        }
    }

    if (counter_frame % 30240 == 0) // magic number, = 7! * 6;
        counter_frame = 0;

    // draw evrything
    display();
    // add one frame
    counter_frame++;
    // start the timer again
    if (exit_stste)
        TTimer(frame_function);
}

void display(void)
{
    //printf("%i %i \n", x, y);
   // glClear(GL_COLOR_BUFFER_BIT);
    /*
    glColor3f(1.0f, 0.0f, 0.0f);
    Tsquare(x, y);
    */

    DrawSpace(glob_map, LEFTBOARD, 0, width_L, height_T + 3, width_R, height_B);
    TPrintNUMBER(LEFTBOARD + width_R + 1, 12, get_lines());
    TPrintNUMBER(LEFTBOARD + width_R + 1, 14, LVL);
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    static err_move check = 0;
    switch(key)
    {
    case esc:
    // case '\x1B':
        exit(EXIT_SUCCESS);
        /// safe();
        /// menu();
        break;
    case ' ':
        while (tet_move(down) == 0);
        send_event(hard_drop);
        next_tetrimino();
        break;
    case 'w':
        check = tet_rotate(1);
        break;
    case 'e':
        check = tet_rotate(1);
        break;
    case 'q':
        check = tet_rotate(-1);
        break;
    case 's':
        check = tet_move(down);
        break;
    case 'd':
        check = tet_move(right);
        break;
    case 'a':
        check = tet_move(left);
        break;
    default:
        //printf("Nomore\n");
        break;
    }
    if (rabbit_user < 7)
        if (check == 0)
            deadline = 0;
    ///display();
}

void specKeys (unsigned char key, int x, int y)
{
    static err_move check = 0;
    switch(key)
    {
    case GLUT_KEY_UP:
        check = tet_rotate(1);
        break;
    case GLUT_KEY_DOWN:
        check = tet_move(down);
        break;
    case GLUT_KEY_RIGHT:
        check = tet_move(right);
        break;
    case GLUT_KEY_LEFT:
        check = tet_move(left);
        break;
    default:
        //printf("Nomore\n");
        break;
    }
    if (rabbit_user < 7)
        if (check == 0)
            deadline = 0;
    ///display();
}

void next_tetrimino ()
{
    if (!exit_stste)
        return;
    tet_stop();
    send_event(placing);
    clear_full_rows();
    apply_score();
    if
            (
            glob_map[height_T+2][width_L+3] != 0 ||
            glob_map[height_T+2][width_L+4] != 0 ||
            glob_map[height_T+2][width_L+5] != 0 ||
            glob_map[height_T+2][width_L+6] != 0
            )
    {
        printf("You lose :(\n");
        exit_game();
        return;
    }
    tet_create( queue_frame[0][0], queue_frame[0][1] );

    int j_frame = 0;
    for (j_frame = 0; j_frame < 3; j_frame++)
    {
        queue_frame[j_frame][0] = queue_frame[j_frame+1][0];
        queue_frame[j_frame][1] = queue_frame[j_frame+1][1];
        DrawFigure(1, 4+j_frame*5, queue_frame[j_frame][0], queue_frame[j_frame][1]);
    }
    queue_frame[3][0] = ( rand() % 7 +1 );
    queue_frame[3][1] = ( rand() % 4 );
    DrawFigure(1, 16, queue_frame[j_frame][0], queue_frame[j_frame][1]);

    if (get_lines() >= (LVL+1)*10 && get_lines() != lines_counter)
    {
        if (interval != 6)
            interval -= 6;
        TChangeColor(rand() %7 + 1, rand() %7 + 1);
        lines_counter = get_lines();
        LVL = get_lines() / 10;
        //set_lines(1); to save()
    }
    rabbit_user = 0;
    //printf("%d\n", get_score());
}
