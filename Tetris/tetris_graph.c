#include <stdlib.h>
#include <GL/glut.h>
#include "kernel.h"

//#include <GL/glu.h>



#define DefoultWindowOptions GLUT_RGB|GLUT_DOUBLE
#define DEFAULT_WINDOW_XSIZE  360
#define DEFAULT_WINDOW_YSIZE  480

//void (*Timer)();

typedef struct My_Color
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;

}Tcolor;

int Win_SizeX = DEFAULT_WINDOW_XSIZE;
int Win_SizeY = DEFAULT_WINDOW_YSIZE;

const Tcolor COLOR[] = {
  {249, 249, 11},
  {244, 139, 11},
  {32,  126, 232},
  {48,  232, 9},
  {250, 28,  10},
  {30,  238, 213},
  {175, 18,  203}
};


int TsquareSize = 50;
//some fun
    int x = 2;
    int y = 0;
//
Tcolor tcolors[8] = {};
//======================================================================
void TsetWinSize(unsigned int x, unsigned int y)
{
    Win_SizeX = x;
    Win_SizeY = y;

}
//======================================================================
void TsetSquareSize(int x, int y)
{
    double Ysize = y / (height_B / 2. + .5);
    double Xsize = x / (width_R / 2. + .5);

    if( Ysize >= Xsize )
        TsquareSize = Xsize;
    else TsquareSize = Ysize;
}
//==============Draw square=============================================
void Tsquare(int y, int x)
{

    glRectf(-1 + (float)((float)x * TsquareSize) / ( Win_SizeX),
            1 - (float)((float)y * TsquareSize) / ( Win_SizeY),
            -1 + (float)((float)x * TsquareSize + TsquareSize) / ( Win_SizeX),
            1 - (float)((float)y * TsquareSize + TsquareSize) / ( Win_SizeY));
    //glRectf(x, y, x + TsquareSize, y + TsquareSize);
}
//======================================================================
void DrawSpace (matrix space)
{
    int i = 0, j = 0;
    glClear(GL_COLOR_BUFFER_BIT);

    for (i = height_T ; i <= height_B; i++)
        for (j = width_L; j <= width_R; j++)
        {
            if (space[i][j])
            {
            glColor3f(COLOR[space[i][j] - 1].red / 255.,
                      COLOR[space[i][j] - 1].green / 255.,
                      COLOR[space[i][j] - 1].blue / 255.);
            Tsquare(i,j);
            }
        }

}
//===========what we need do, if window was resize======================
void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    TsetWinSize(w, h);
    glLoadIdentity();
    glOrtho(0., 0.,(GLdouble)w, (GLdouble)h, 0., 0.);
    TsetSquareSize(w, h);
   // display();
}

//===========what we need draw==========================================
void DrawFrame(void)
{
    //printf("%i %i \n", x, y);
    glClear(GL_COLOR_BUFFER_BIT);
    /*
    glColor3f(1.0f, 0.0f, 0.0f);
    Tsquare(x, y);
    */

    DrawSpace(glob_map);
    glFlush();
}

//===========get interrupt from keyboard================================
/*void keyboard(unsigned char key, int a, int b)
{
    switch (key)
    {
    case '\x1B':
        exit(EXIT_SUCCESS);
        break;
    case 'w':
        move ( up );
        break;
    case 's':
        move( down );
        break;
    case 'd':
        move( right );
        break;
    case 'a':
        move( left );
        break;
    case ' ':
        create(tet_T, down);
        break;
    default: break;

    }
    dbg_dump();
    printf("pos: %2d %2d, type: %d", curr.pos.x, curr.pos.y, curr.type);
    printf("\n\n");
    DrawFrame();
}
*/
//======================================================================
inline void TCreateWindow()
{

    glutCreateWindow("Tetris");
    glutReshapeFunc(&reshape);

}

//===========inicialize glut and functions===============================
void TInit()
{
    int argc = 0;
    char argv[] = "";

    glutInit(&argc,&argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(Win_SizeX, Win_SizeY);
    glutInitWindowPosition(100,100);

    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    TsetSquareSize(DEFAULT_WINDOW_XSIZE, DEFAULT_WINDOW_YSIZE);

    TCreateWindow();

}

inline void TMainLoop()
{
    gluOrtho2D(0., 0.,(GLdouble)Win_SizeX, (GLdouble)Win_SizeY);
    glutMainLoop();

}

inline void TDisplay(void (*display)(void))
{
    glutDisplayFunc(DrawFrame);
}

inline void TKeyBoard( void (*kbrd)(unsigned char key, int a, int b) )
{
    glutKeyboardFunc(kbrd);
}

inline void TSpecial(void (*special)(unsigned char key, int a, int b))
{
    glutSpecialFunc(special);
}

inline void TTimer( void (*timer)(int value))
{
    glutTimerFunc(TFrameInterval, timer, 0);
}

