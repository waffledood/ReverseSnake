#ifndef __MOTION_H__
#define __MOTION_H__

#define GRID_CELL_SIZE 10
#define GRID_MAX_X 23
#define GRID_MAX_Y 15

struct Position {
    int x;
    int y;
};

enum DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};
#endif  // __MOTION_H__
