#ifndef __SNAKE_H__
#define __SNAKE_H__

#define MAX_SNAKE_LENGTH 100

#include "motion.h"

struct Snake {
    struct Position body[MAX_SNAKE_LENGTH];
    int ticksPerMove;
    int length;
    int ticksElapsed;
};

struct Snake constructSnake(int x, int y, double speed, int length) {
    struct Snake snake;
    snake.body[0].x = x;
    snake.body[0].y = y;
    snake.length = 1;
    snake.ticksElapsed = 0;
    setSnakeSpeed(&snake, speed);

    int i;
    for (i = 0; i < length - 1; i++) {
        growSnake(&snake);
    }

    return snake;
}

void growSnake(struct Snake *s) {
    if (s->length >= MAX_SNAKE_LENGTH) {
        return;
    }

    s->body[s->length] = s->body[s->length - 1];
    s->length++;
}

void moveSnake(struct Snake *s, struct Position playerPos) {
    if (s->ticksElapsed < s->ticksPerMove) {
        s->ticksElapsed++;
        return;
    }

    s->ticksElapsed = 0;

    struct Position nextPos;
    nextPos.x = s->body[0].x;
    nextPos.y = s->body[0].y;

    int diffX = s->body[0].x - playerPos.x;
    int diffY = s->body[0].y - playerPos.y;

    if ((abs(diffX) >= abs(diffY))) {
        if (diffX > 0) {
            nextPos.x -= 1;
        } else if (diffX < 0) {
            nextPos.x += 1;
        }
    } else if (abs(diffX) < abs(diffY)) {
        if (diffY > 0) {
            nextPos.y -= 1;
        } else if (diffY < 0) {
            nextPos.y += 1;
        }
    }

    updateSnakeBody(s, nextPos);
}

void updateSnakeBody(struct Snake *s, struct Position newPos) {
    int i;

    for (i = s->length - 1; i > 0; i--) {
        s->body[i] = s->body[i - 1];
    }

    s->body[0] = newPos;
}

void setSnakeSpeed(struct Snake *s, double speed) {
    s->ticksPerMove = (1 / speed) * GAME_UPDATE_HZ;
}

#endif  // __SNAKE_H__