#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>


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
int TsquareSize = 50;
//some fun
    float x = 0;
    float y = 0;
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
//===========get interrupt from keyboard================================
void keyboard(unsigned char key, int a, int b)
{
    switch (key)
    {
    case '\x1B':
        exit(EXIT_SUCCESS);
        break;
    case 'w':
  //      if (y > -1. && y < 1.)
            y+=0.05;
        break;
    case 's':
   //     if (y > -1. && y < 1.)
            y-=0.05;
        break;
    case 'd':
   //     if (x > -1. && x < 1.)
            x+=0.05;
        break;
    case 'a':
   //     if (x > -1. && x < 1.)
            x-=0.05;
        break;
    default: break;

    }
    display();
}
//==============Draw square=============================================
void Trect(float x, float y)
{

    glRectf(x / ( Win_SizeX), y / ( Win_SizeY),
            (x + TsquareSize) / ( Win_SizeX), (y + TsquareSize) / ( Win_SizeY));

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
    display();
}

//===========what we need draw==========================================
void display(void)
{
    printf("%f %f \n", x, y);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
/*
    glBegin(GL_POLYGON);
    {
        glVertex2f( x, y);
        glVertex2f( x, y + TsquareSize / Win_SizeY);
        glVertex2f(x + TsquareSize /  Win_SizeX,  y + TsquareSize / Win_SizeY);
        glVertex2f( x + TsquareSize /  Win_SizeX,  y);
    } glEnd();
*/
    Trect(x, y);
    glFlush();
}
//======================================================================
void TCreateWindow()
{

    glutCreateWindow("Tetris");

    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(&display);
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
    gluOrtho2D(0., 0.,(GLdouble)Win_SizeX, (GLdouble)Win_SizeY);
    //glOrtho(0., 0.,(GLdouble)Win_SizeX, (GLdouble)Win_SizeY, 0., 0.);
    glOrtho(0., 1.,1.0, 0.0, 0., 0.);
    TsetSquareSize(DEFAULT_WINDOW_XSIZE, DEFAULT_WINDOW_YSIZE);
    //

    glutDisplayFunc(&display);
    glutKeyboardFunc(&keyboard);
    glutReshapeFunc(&reshape);



}


void TMainLoop()
{
    glutMainLoop();
}
