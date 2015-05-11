#include <stdlib.h>
#include "tetris_graph.h"
#include "kernel.h"
#include <GL/glut.h>

void keyboard(unsigned char key, int a, int b);
void display(void);

int main()
{

    TInit();
    TKeyBoard(&keyboard);
    TDisplay(&display);
    //TCreateWindow();

    TMainLoop();

    return 0;
}


void keyboard(unsigned char key, int a, int b)
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
   /* dbg_dump();
    printf("pos: %2d %2d, type: %d", curr.pos.x, curr.pos.y, curr.type);
    printf("\n\n");*/
    display();
}

void display(void)
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
