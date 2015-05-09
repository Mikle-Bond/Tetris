#ifndef TETRIS_GRAPH
#define TETRIS_GRAPH

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
extern inline void KeyBoard( void keyboard(unsigned char key, int a, int b) );
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
extern void DrawSpace (matrix space);

extern void Tsquare(float x, float y);


#endif // TETRIS_GRAPH

