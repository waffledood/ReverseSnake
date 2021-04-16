#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "player.h"
#include "snake.h"
#include "sprites.h"

#define SPRITE_END_GOAL_ID 0
#define SPRITE_PLAYER_ID 1
#define SPRITE_SNAKE_ID 2

void setMainMenu();
void setPauseMenu();
void displayLevelNumber(int levelNumb);
void blankScreen(void);
void initializeGraphics();
void drawSprite(int spriteId, int N, int x, int y);
void drawPlayer(struct Player player);
void drawSnake(struct Snake *snake);
void drawEndGoal(struct Position endGoal);
struct Position gridToPixelPos(struct Position gridPos);

/*
Note for devs on the order in which sprite numbers are assigned

Snake Title
A Select button 
START option
PAUSE title 
HARD MODE option 
LEVEL text 
Level Number 

*/

// Function to enable & set the Main Menu for players
void setMainMenu() {
    int i;

    // draw "Snake" title
    for (i = 0; i < 5; i++) {
        drawSprite(3 + i, 10 + i, 100 + (i * 10), 120 / 2);
    }

    // draw "A Select" button
    drawSprite(12, 15, 90, 120 / 2 + 20);

    // draw "START" option
    int start_menu[] = {8, 9, 10, 11, 9};
    for (i = 0; i < 5; i++) {
        drawSprite(start_menu[i], 16 + i, 100 + (i * 8), 120 / 2 + 20);
    }

    // draw "B Select" button
    drawSprite(19, 26, 90, 120 / 2 + 30);

    // draw "HARD MODE" option
    int hard_mode[] = {8, 9, 10, 11, 9, 22, 20, 10, 11, 21, 23};
    for (i = 0; i < 11; i++) {
        drawSprite(hard_mode[i], 27 + i, 100 + (i * 8), 120 / 2 + 30);
    }
}

// Function to enable & set the Pause Menu for players
void setPauseMenu() {
    int i;
    int pause_menu[] = {16, 10, 17, 8, 15};

    // draw "PAUSE" title
    for (i = 0; i < 5; i++) {
        drawSprite(pause_menu[i], 21 + i, 100 + (i * 10), 120 / 2);
    }
}

// Function to display the Level Number for players
void displayLevelNumber(int levelNumb) {
    int i;
    int level_text[] = {13, 15, 14, 15, 13, 24};

    // draw "Level" text
    for (i = 0; i < 6; i++) {
        drawSprite(level_text[i], 38 + i, 0 + (i * 8), 0);
    }

    // draw Level Number
    drawSprite(levelNumb / 10 + 25, 44, 48, 0);
    drawSprite(levelNumb % 10 + 25, 45, 56, 0);
}

// Function to clear screen of existing sprites
void blankScreen() {
    int i;
    for (i = 0; i < 128; i++)
        drawSprite(0, i, 240, 160);
}

void initializeGraphics() {
    int i;

    // Set Mode 2
    *(unsigned short *)0x4000000 = 0x40 | 0x2 | 0x1000;

    // Fill SpritePal
    // Color 0 (Empty)
    *(unsigned short *)0x5000200 = 0;
    // Color 1 (Black)
    *(unsigned short *)0x5000202 = RGB(31, 0, 0);
    // Color 2 (Bright Yellow)
    *(unsigned short *)0x5000204 = RGB(24, 122, 173);
    // Color 3 (Light Green)
    *(unsigned short *)0x5000206 = RGB(16, 31, 16);
    // Color 4 (Darkest Green)
    *(unsigned short *)0x5000208 = 0x4CAF50;
    // Color 5 (Middle Green)
    *(unsigned short *)0x500020A = 0x8BC34A;
    // Color 6 (White)
    *(unsigned short *)0x500020C = RGB(31, 31, 31);
    // Color 7 (Red)
    *(unsigned short *)0x500020E = RGB(31, 0, 0);

    // Fill SpriteData
    for (i = 0; i < 128 * 8 * 8 / 2; i++)
        spriteData[i] = (sprites[i * 2 + 1] << 8) + sprites[i * 2];
    for (i = 0; i < 128; i++)
        drawSprite(0, i, 240, 160);
}

void drawSprite(int spriteId, int N, int x, int y) {
    // Gift function: displays sprite number spriteId on screen at position (x,y), as sprite object N
    *(unsigned short *)(0x7000000 + 8 * N) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8 * N) = x;
    *(unsigned short *)(0x7000004 + 8 * N) = spriteId * 2;
}

void drawPlayer(struct Player player) {
    struct Position pixelPos;
    pixelPos = gridToPixelPos(player.position);
    drawSprite(SPRITE_PLAYER, SPRITE_PLAYER_ID, pixelPos.x, pixelPos.y);
}

void drawSnake(struct Snake *snake) {
    int i;
    for (i = 0; i < snake->length; i++) {
        struct Position pixelPos = gridToPixelPos(snake->body[i]);
        drawSprite(SPRITE_SNAKE_BODY, i + SPRITE_SNAKE_ID, pixelPos.x, pixelPos.y);
    }
}

void drawEndGoal(struct Position endGoal) {
    struct Position pixelPos = gridToPixelPos(endGoal);
    drawSprite(SPRITE_END_GOAL, SPRITE_END_GOAL_ID, pixelPos.x, pixelPos.y);
}

struct Position gridToPixelPos(struct Position gridPos) {
    struct Position pixelPos;
    pixelPos.x = gridPos.x * GRID_CELL_SIZE;
    pixelPos.y = gridPos.y * GRID_CELL_SIZE;

    return pixelPos;
}

#endif  // __GRAPHICS_H__
