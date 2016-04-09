#ifndef TETRIS_GRAPH
#define TETRIS_GRAPH
#include "kernel_types.h"
#define LEFTBOARD 6
extern unsigned long currColor;
/*
 * draw background
 * */
extern void TPrintNUMBER(int x, int y, int num);

extern void DrawScreen();
/*
 * draw one figure in position xPos, yPos
 * using index of fihure and anglefor orientation it
 * */
extern void DrawFigure(unsigned int xPos, unsigned int yPos, tet_num numFigure, direction angle);
/*
 * change screen and font color by index of TCOLOR
 * */
extern void TChangeColor(int FontColor, int ScreenColor);
/*
 * inicialize glut library and graph functions
 * */
extern void TInit();

extern inline void TMainLoop();
/*
 * draw one frame, while beside text end help
 * */
extern void DrawFrame();
/*
 * keyboard function,
 * get interrupt from keyboard with graph symbols
 * */
extern inline void TKeyBoard( void (*keyboard)(unsigned char key, int a, int b) );
/*
 * get interrupt from keyboard with unvisible symbols
 * */
inline void TSpecial(void (*special)(unsigned char key, int a, int b));
/*
 * inicialize display function> which will draw
 * */
extern inline void TDisplay(void (*display)(void));
/*
 * inicialize timer function value
 * parameter value need to know? what timer work now
 * in the end function timer you need recall this function
 * to  timer run not one time
 * */
extern inline void TTimer( void (*timer)(int value));
/*
 * draw square
 * position is x - horizontal
 *  y - vertical
 * */
/*
 * visualize tetris space
 * */
extern void DrawSpace (matrix space, int x, int y,int startX, int startY, int sizeX, int sizeY);
/*
 * clear all window
 * */
extern inline void TClear();
/*
 * finish process of drawing and show it on window
 * */
extern inline void EndDraw();
/*
 * draw square wthi x,y coordinate
 * square size equal TsqureSize
 * at the begining of prigram 50 pixels
 * */
extern void Tsquare(float x, float y);


#endif // TETRIS_GRAPH

