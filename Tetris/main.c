
// #include <QCoreApplication>
#include "kernel.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    // QCoreApplication a(argc, argv);

    // FILE *in_f = fopen("C:\\intsruct.txt", "r");

//    if (NULL == in_f) {
//        printf("File not found\n");
//        return a.exec();
//    }

    glob_map[15][6] = 3;
    glob_map[15][7] = 3;
    glob_map[15][8] = 3;
    glob_map[15][9] = 3;


    create(tet_L, right);

    int frame = 0;

    err_move res = tea_cup;

    while (1) {

        int t = getch();

        switch (t) {
        case 'w':
            res = move(up);
            break;
        case 's':
            res = move(down);
            break;
        case 'a':
            res = move(left);
            break;
        case 'd':
            res = move(right);
            break;
        case 'e':
            res = rotate(1);
            break;
        case 'q':
            res = rotate(-1);
            break;
        case 'm':
            create(rand() % 7, rand() % 4);
            break;
        case '\x1B':
            exit(0);
            break;
        default:
            printf("Nomore\n");
            break;
        }
        dbg_dump();
        frame += 1;
        printf("%3d: pos: %d, %d moveing result: %d\n", frame, curr.pos.x, curr.pos.y ,res);
    }

    // return a.exec();
    return 0;
}
