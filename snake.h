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

struct Snake constructSnake(int x, int y, double speed) {
    struct Snake snake;
    snake.body[0].x = x;
    snake.body[0].y = y;
    snake.length = 1;
    snake.ticksElapsed = 0;
    setSnakeSpeed(&snake, speed);

    return snake;
}

void growSnake(struct Snake *s) {
    s->body[s->length] = s->body[s->length - 1];
    s->length++;
}

void moveSnake(struct Snake *s, struct Position playerPos) {
    if (s->ticksElapsed < s->ticksPerMove) {
        s->ticksElapsed++;
        return;
    }

    struct Position nextPos;

    //TODO: Get the next position of the snake's head and pass into updateSnakeBody()

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
    s->ticksPerMove = (1 / speed) * 1000;
}

#endif // __SNAKE_H__