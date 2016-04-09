#include <stdlib.h>
#include <GL/glut.h>
#include "kernel.h"

unsigned int TFrameInterval = 10;


#define DefoultWindowOptions GLUT_RGB|GLUT_DOUBLE
#define DEFAULT_WINDOW_XSIZE  540
#define DEFAULT_WINDOW_YSIZE  480

#define LEFTBOARD 6
unsigned long currColor = 0;
unsigned char ONESPECIALCOLORFORFONT = 0;
unsigned char ONESPECIALCOLORFORSCREEN = 0;

typedef struct My_Color
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;

}Tcolor;

int Win_SizeX = DEFAULT_WINDOW_XSIZE;
int Win_SizeY = DEFAULT_WINDOW_YSIZE;

const Tcolor COLOR[] = {
    {25,  25,  25},     //color of back ground

    {249, 249, 11},     //figure color
    {244, 139, 11},
    {32,  126, 232},
    {48,  232, 9},
    {250, 28,  10},
    {30,  238, 213},
    {175, 18,  203},

    {120, 125, 6},      //color of ghost
    {122, 70,  5},
    {16,  63,  116},
    {24,  116, 4},
    {125, 14,  5},
    {15,  119, 106},
    {88,  9,   101}
};
Tcolor FontColor = {200,  200,  200};


int TsquareSize = 50;
//some fun
int x = 2;
int y = 0;
//

#include "Tfont.h"

Tcolor tcolors[8] = {};
//======================================================================
void TChangeColor(int FontColor, int ScreenColor)
{
    ONESPECIALCOLORFORFONT = FontColor;
    ONESPECIALCOLORFORSCREEN = ScreenColor;
    if (ONESPECIALCOLORFORSCREEN == ONESPECIALCOLORFORFONT)
        ONESPECIALCOLORFORSCREEN = (2 * ONESPECIALCOLORFORSCREEN) % 9;
}

//======================================================================
void TsetWinSize(unsigned int x, unsigned int y)
{
    Win_SizeX = x;
    Win_SizeY = y;

}
//==========================================================================
void TsetSquareSize(int x, int y)
{
    double Ysize = y / (height_B / 2. + .5);
    double Xsize = x / (width_R / 2. + .5);

    if( Ysize >= Xsize )
        TsquareSize = Xsize;
    else TsquareSize = Ysize;
}
//==============Draw square==================================================
void Tsquare(int y, int x)
{

    glRectf(-1 + (float)((float)x * TsquareSize) / ( Win_SizeX),
            1 - (float)((float)y * TsquareSize) / ( Win_SizeY),
            -1 + (float)((float)x * TsquareSize + TsquareSize) / ( Win_SizeX),
            1 - (float)((float)y * TsquareSize + TsquareSize) / ( Win_SizeY));
    //glRectf(x, y, x + TsquareSize, y + TsquareSize);
}
//-----------------------------------------------------------------------------
void TGradSquare(int x, int y, int color)
{
    glBegin(GL_TRIANGLES);
    glColor3f(( COLOR[color].red / 2.  ) / 255.,
              ( COLOR[color].green / 2.) / 255.,
              ( COLOR[color].blue / 2. ) / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize) / ( Win_SizeY));
    glVertex2f(-1 + (float)((float)x * TsquareSize + TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize) / ( Win_SizeY));

    glColor3f(COLOR[color].red / 255.,
              COLOR[color].green / 255.,
              COLOR[color].blue / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize + TsquareSize / 2.) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize + TsquareSize / 2.) / ( Win_SizeY));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(( COLOR[color].red / 2.  ) / 255.,
              ( COLOR[color].green / 2.) / 255.,
              ( COLOR[color].blue / 2. ) / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize + TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize) / ( Win_SizeY));
    glVertex2f(-1 + (float)((float)x * TsquareSize  + TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize  + TsquareSize) / ( Win_SizeY));

    glColor3f(COLOR[color].red / 255.,
              COLOR[color].green / 255.,
              COLOR[color].blue / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize + TsquareSize / 2.) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize + TsquareSize / 2.) / ( Win_SizeY));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(( COLOR[color].red / 2.  ) / 255.,
              ( COLOR[color].green / 2.) / 255.,
              ( COLOR[color].blue / 2. ) / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize + TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize + TsquareSize) / ( Win_SizeY));
    glVertex2f(-1 + (float)((float)x * TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize + TsquareSize) / ( Win_SizeY));

    glColor3f(COLOR[color].red / 255.,
              COLOR[color].green / 255.,
              COLOR[color].blue / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize + TsquareSize / 2.) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize + TsquareSize / 2.) / ( Win_SizeY));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(( COLOR[color].red / 2.  ) / 255.,
              ( COLOR[color].green / 2.) / 255.,
              ( COLOR[color].blue / 2. ) / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize + TsquareSize) / ( Win_SizeY));
    glVertex2f(-1 + (float)((float)x * TsquareSize) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize) / ( Win_SizeY));

    glColor3f(COLOR[color].red / 255.,
              COLOR[color].green / 255.,
              COLOR[color].blue / 255.);
    glVertex2f(-1 + (float)((float)x * TsquareSize + TsquareSize / 2.) / ( Win_SizeX),
               1 - (float)((float)y * TsquareSize + TsquareSize / 2.) / ( Win_SizeY));
    glEnd();


}

//======================================================================
void DrawScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(COLOR[ONESPECIALCOLORFORSCREEN].red / 300.,
              COLOR[ONESPECIALCOLORFORSCREEN].green / 300.,
              COLOR[ONESPECIALCOLORFORSCREEN].blue / 300.);
    glRectf(-1., 1., 1., -1.);
}

//----------------------------------------------------------------------
void DrawSpace (matrix space, int x, int y,int startX, int startY, int sizeX, int sizeY)
{
    int i = 0, j = 0;
      //draw figures and game plce
    for (i = startY ; i <= sizeY; i++)
        for (j = startX; j <= sizeX; j++)
        {

           // glColor3f(COLOR[space[i][j]].red / 255.,
           //         COLOR[space[i][j]].green / 255.,
           //         COLOR[space[i][j]].blue / 255.);
           TGradSquare(j + x, i + y, space[i][j]);
        }
    /*
    if (currColor % 1000 == 0)
    {
        TChangeColor(rand() % 7, rand() % 7 + 7);
        currColor /=100;
        currColor+=1;
    }*/
    //print title and score
    PrintTitle();
    TPrintNUMBER(LEFTBOARD + width_R + 1, 10, get_score());

}
//----------------------------------------------------------------------
void DrawFigure(unsigned char xPos, unsigned char yPos, unsigned char numFigure, unsigned char angle)
{
    int i, j;
    tet_map_t Figure = tet_get_map(numFigure, angle);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (Figure[i][j])
                TGradSquare(j + xPos, i + yPos, Figure[i][j] * numFigure);
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

    DrawSpace(glob_map, LEFTBOARD, 0, 1, 4, width_R, height_B);
    PrintTitle();
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
//----------------------------------------------------------------------
void specialK (unsigned char key, int a, int b)
{
    if (key == '\x1B')exit(EXIT_SUCCESS);
}

//======================================================================
inline void TCreateWindow()
{

    glutCreateWindow("Tetris");
    glutReshapeFunc(&reshape);
    glutSpecialFunc(&specialK);

}

//===========inicialize glut and functions===============================
void TInit()
{
    int argc = 0;
    char argv[] = "";

    glutInit(&argc,&argv);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(Win_SizeX, Win_SizeY);
    glutInitWindowPosition(100,100);

    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    TsetSquareSize(DEFAULT_WINDOW_XSIZE, DEFAULT_WINDOW_YSIZE);
    glOrtho(0, Win_SizeX, 0, Win_SizeY, -1., 1.);

    TCreateWindow();

    TChangeColor(rand() % 7, rand() % 7 + 7);


}

void TMainLoop()
{
    gluOrtho2D(0., 0.,(GLdouble)Win_SizeX, (GLdouble)Win_SizeY);
    glutMainLoop();

}

void TDisplay(void (*display)(void))
{
    glutDisplayFunc(display);
}

void TKeyBoard( void (*kbrd)(unsigned char key, int a, int b) )
{
    glutKeyboardFunc(kbrd);
}

void TSpecial(void (*special)(unsigned char key, int a, int b))
{
    glutSpecialFunc(special);
}

void TTimer( void (*timer)(int value))
{
    glutTimerFunc(TFrameInterval, timer, 0);
}

inline void TClear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

inline void EndDraw()
{
    glFlush();
}
