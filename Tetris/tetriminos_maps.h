//=========================================================
// Pixel maps of tetriminos

#ifndef TETRIMINOS_MAPS
#define TETRIMINOS_MAPS

#endif // TETRIMINOS_MAPS

// type of single element on map
typedef unsigned char atom_pixel;

// map of single particle - "Tetrimino"
typedef struct {
    // rotation angle - vertical - horisontal
    atom_pixel rotation[4][4][4];
} tetrimino;

// Clear tetrimino
/*
const tetrimino clear = {
    rotation = {
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        }
    }
};
*/

const tetrimino tet_T_map = {
    rotation = {
        {
            { 0, 1, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }
        }
    }
};

const tetrimino tet_S_map = {
    rotation = {
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 1, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 1, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }
        }
    }
};

const tetrimino tet_Z_map = {
    rotation = {
        {
            { 0, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }
        }
    }
};

const tetrimino tet_I_map = {
    rotation = {
        {
            { 0, 0, 0, 0 },
            { 1, 1, 1, 1 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 1, 1, 1, 1 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 }
        }
    }
};

const tetrimino tet_B_map = {
    rotation = {
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 }
        }
    }
};

const tetrimino tet_L_map = {
    rotation = {
        {
            { 0, 0, 0, 0 },
            { 0, 0, 1, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 1, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 1, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 0 }
        }
    }
};

const tetrimino tet_J_map = {
    rotation = {
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 }
        }
    }
};

// directions
enum direction { down, left, up, right };

// offsets to the directions
struct {
    char x;
    char y;
} offsets[] = {
    { x =  1, y =  0 },
    { x =  0, y = -1 },
    { x = -1, y =  0 },
    { x =  0, y =  1 }
};

// list of the particles
enum tet_num { tet_B, tet_L, tet_J, tet_S, tet_Z, tet_I, tet_T };

// array of the particles' maps
tetrimino particles[] = { &tet_B_map, &tet_L_map, &tet_J_map, &tet_S_map, &tet_Z_map, &tet_I_map, &tet_T_map };

// current falling particle
typedef struct {
    int PID;
    unsigned char angle;
    struct position{
        int x;
        int y;
    };
    tet_num type;
} particle;
