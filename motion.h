#ifndef __MOTION_H__
#define __MOTION_H__

#define GAME_UPDATE_HZ 1000
#define GRID_CELL_SIZE 10
#define GRID_MAX_X 23
#define GRID_MAX_Y 15

struct Position {
    int x;
    int y;
};

isPositionEqual(struct Position p1, struct Position p2) {
    return (p1.x == p2.x && p1.y == p2.y) ? 1 : 0; 
}

enum DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};
#endif  // __MOTION_H__
