#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "motion.h"

struct Player constructPlayer(int x, int y, double speed);
void movePlayer(struct Player* p, enum DIRECTION dir);
void setPlayerSpeed(struct Player* p, double speed);
struct Position getPlayerPosition(struct Player p);

struct Player {
    struct Position position;
    int ticksElapsed;
    int ticksPerMove;
};

struct Player constructPlayer(int x, int y, double speed) {

    if (x > GRID_MAX_X) {
        x = GRID_MAX_X;
    } else if (x < GRID_MIN_X) {
        x = GRID_MIN_X;
    }

    if (y > GRID_MAX_Y) {
        y = GRID_MAX_Y;
    } else if (y < GRID_MIN_Y) {
        y = GRID_MIN_Y;
    }

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
            p->position.y = (p->position.y == GRID_MIN_Y) ? GRID_MIN_Y : p->position.y - 1;
            break;
        case DOWN:
            p->position.y = (p->position.y == GRID_MAX_Y) ? GRID_MAX_Y : p->position.y + 1;
            break;
        case LEFT:
            p->position.x = (p->position.x == GRID_MIN_X) ? GRID_MIN_X : p->position.x - 1;
            break;
        case RIGHT:
            p->position.x = (p->position.x == GRID_MAX_X) ? GRID_MAX_X : p->position.x + 1;
            break;
        default:
            break;
    }
}

void setPlayerSpeed(struct Player* p, double speed) {
    p->ticksPerMove = (1 / speed) * GAME_UPDATE_HZ;
}

struct Position getPlayerPosition(struct Player p) {
    return p.position;
}
#endif  // __PLAYER_H__
