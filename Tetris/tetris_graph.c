#include <stdlib.h>
#include <GL/glut.h>
#include "kernel.h"
//#include <GL/glu.h>


#define DefoultWindowOptions GLUT_RGB|GLUT_DOUBLE
#define DEFAULT_WINDOW_XSIZE  360
#define DEFAULT_WINDOW_YSIZE  480

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
    double Ysize = y / 12.;
    double Xsize = x / 5.;

    if( Ysize >= Xsize )
        TsquareSize = Xsize;
    else TsquareSize = Ysize;
}
//==============Draw square=============================================
void Tsquare(int x, int y)
{

    glRectf(-1 + (float)((float)x * TsquareSize) / ( Win_SizeX),
            1 - (float)((float)y * TsquareSize) / ( Win_SizeY),
            -1 + (float)((float)x * TsquareSize + TsquareSize) / ( Win_SizeX),
            1 - (float)((float)y * TsquareSize + TsquareSize) / ( Win_SizeY));
    //glRectf(x, y, x + TsquareSize, y + TsquareSize);
}
//======================================================================
void drawSpace (atom_pixel **space)
{
    int i = 0, j = 0;
    glClear(GL_COLOR_BUFFER_BIT);
   // for ( ; i < NumCol; i++)
     //   for (j = 0; j < NumLine; j++)
        {
            if (space[i][j])
            {
            glColor3f(COLOR[space[i][j]].red / 255.,
                      COLOR[space[i][j]].green / 255.,
                      COLOR[space[i][j]].blue / 255.);
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
void display(void)
{
    printf("%i %i \n", x, y);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    Tsquare(x, y);
    glFlush();
}

//===========get interrupt from keyboard================================
void keyboard(unsigned char key, int a, int b)
{
    switch (key)
    {
    case '\x1B':
        exit(EXIT_SUCCESS);
        break;
    case 'w':
        if ( y < 23)
            y+=1;
        break;
    case 's':
        if (y > 0)
            y-=1;
        break;
    case 'd':
        if ( x < 14)
            x+=1;
        break;
    case 'a':
        if (x > 2)
            x-=1;
        break;
    default: break;

    }
    display();
}

//======================================================================
void TCreateWindow()
{

    glutCreateWindow("Tetris");
    glutReshapeFunc(&reshape);
    glutDisplayFunc(&display);
    glutKeyboardFunc(&keyboard);
}

//===========inicialize glut and functions===============================
void TInit()
{
    int argc = 0;
    char argv[] = "";

    glutInit(&argc,&argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(Win_SizeX,Win_SizeY);
    glutInitWindowPosition(100,100);

    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    TsetSquareSize(DEFAULT_WINDOW_XSIZE, DEFAULT_WINDOW_YSIZE);

    TCreateWindow();


    gluOrtho2D(0., 0.,(GLdouble)Win_SizeX, (GLdouble)Win_SizeY);



    glutMainLoop();

}

