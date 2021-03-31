#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "motion.h"

struct Player {
    struct Position position;
    int ticksElapsed;
    int ticksPerMove;
};

struct Player constructPlayer(int x, int y, double speed) {
    struct Player p;
    p.position.x = x;
    p.position.y = y;
    p.ticksElapsed = 0;
    setPlayerSpeed(&p, speed);

    return p;
}

void movePlayer(struct Player* p, enum DIRECTION dir) {
    if (p->ticksElapsed < p->ticksPerMove) {
        p->ticksElapsed++;
        return;
    }

    p->ticksElapsed = 0;

    switch (dir) {
        case UP:
            p->position.y = (p->position.y == 0) ? 0 : p->position.y - 1;
            break;
        case DOWN:
            p->position.y = (p->position.y == 150) ? 150 : p->position.y + 1;
            break;
        case LEFT:
            p->position.x = (p->position.x == 0) ? 0 : p->position.x - 1;
            break;
        case RIGHT:
            p->position.x = (p->position.x == 230) ? 230 : p->position.x + 1;
            break;
        default:
            break;
    }
}

void setPlayerSpeed(struct Player* p, double speed) {
    p->ticksPerMove = (1 / speed) * 1000;
}

struct Position getPlayerPosition(struct Player p) {
    return p.position;
}
#endif  // __PLAYER_H__
