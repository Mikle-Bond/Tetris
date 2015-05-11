#ifndef KERNEL_TYPES
#define KERNEL_TYPES

#include <inttypes.h>

// type of single element on map
typedef unsigned char atom_pixel;

// type of global matrix
typedef atom_pixel matrix[35][12];

// directions
typedef enum direction_t { down, left, up, right } direction;

// list of the particles
typedef enum tet_num_t {
    tet_B = 1,
    tet_L,
    tet_J,
    tet_S,
    tet_Z,
    tet_I,
    tet_T
} tet_num;

// current falling particle
typedef struct {
    int PID;
    unsigned char angle;
    struct {
        int x;
        int y;
    } pos;
    tet_num type;
} particle;

// offset by x and y axes
typedef struct {
    char x;
    char y;
} offset;

// list of the particles
typedef enum err_move_t {
    tea_cup = 0,        // can move
    ovflw_B,            // out of matrix borders
    ovflw_R,            // out of matrix borders
    ovflw_L,            // out of matrix borders
    ovflw_T,            // out of matrix borders
    flood_anoter,       // meeting others
} err_move;

// struct of states of each line
typedef uint64_t row_filler;


#endif // KERNEL_TYPES

