#include <stdlib.h>
#include "tetris_graph.h"
#include "kernel.h"
void keyboard(unsigned char key, int a, int b);

int main()
{

    TInit();
   // KeyBoard(&keyboard);
    //TCreateWindow();

    TMainLoop();

    return 0;
}

/*
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
    case 32:
        create(tet_B, 2);
    default: break;

    }
    DrawFrame();
}
*/
