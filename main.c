// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------

#include "gameStatus.h"
#include "gba.h"
#include "graphics.h"
#include "player.h"
#include "snake.h"

#define TICKS_PER_MILLISECOND 16781

#define SPAWN_PLAYER_X_MIN 15
#define SPAWN_PLAYER_Y_MIN 1
#define SPAWN_PLAYER_X_MAX 23
#define SPAWN_PLAYER_Y_MAX 5

#define SPAWN_SNAKE_X_MIN 3
#define SPAWN_SNAKE_Y_MIN 6
#define SPAWN_SNAKE_X_MAX 20
#define SPAWN_SNAKE_Y_MAX 9

#define SPAWN_GOAL_X_MIN 0
#define SPAWN_GOAL_Y_MIN 10
#define SPAWN_GOAL_X_MAX 8
#define SPAWN_GOAL_Y_MAX 15

#define BASE_SNAKE_LENGTH 5
#define BASE_SNAKE_SPEED 5
#define NORMAL_SPEED_GROWTH_RATE 0.1
#define HARD_SPEED_GROWTH_RATE 0.2

void handler(void);
void initalizeGame();
void startGame();
void initializeInterrupts();
void checkButton(void);
struct Position getRandPos(int lowerLimitX, int lowerLimitY, int upperLimitX, int upperLimitY);
int isPlayerEaten(struct Snake* s, struct Player* p);
void spawnEntities();

// enum to track the state of the game
enum GAME_STATE gameState = GAME_INACTIVE;
enum GAME_MODE gameMode = MODE_NORMAL;
enum DIRECTION lastDirection = NONE;

struct Player player;
struct Snake snake;
struct Position endGoal;

int stage = 1;
unsigned long ticks = 0;

void handler(void) {
    REG_IME = 0x00;  // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_TIMER0) == INT_TIMER0) {
        ticks++;
        initalizeGame();
    }

    REG_IF = REG_IF;  // Update interrupt table, to confirm we have handled this interrupt
    REG_IME = 0x01;   // Re-enable interrupt handling
}

// function to initialize the game
void initalizeGame() {
    checkButton();

    if (gameState == GAME_INITIALIZE) {
        spawnEntities();
        gameState = GAME_ACTIVE;
    } else if (gameState == GAME_PAUSE) {
        setPauseMenu();
    } else if (gameState == GAME_ACTIVE) {
        displayLevelNumber(stage);
        startGame();
    } else {
        setMainMenu();
    }
}

// function to start the game
void startGame() {
    movePlayer(&player, lastDirection);
    moveSnake(&snake, player.position);

    // if player dies, return to Main Menu
    if (isPlayerEaten(&snake, &player)) {
        gameState = GAME_INACTIVE;
        stage = 1;  // reset stage
        blankScreen();
        return;

    // if player reaches endGoal, increase stage
    } else if (isPositionEqual(player.position, endGoal)) {
        gameState = GAME_INITIALIZE;
        stage++;
        blankScreen();
        return;  //blankScreen();
    }

    drawPlayer(player);
    drawSnake(&snake);
    drawEndGoal(endGoal);
}

void initializeInterrupts() {
    // Set Handler Function for interrupts and enable selected interrupts
    REG_INT = (int)&handler;
    REG_IE |= INT_TIMER0;
    REG_IME = 0x1;  // Enable interrupt handling

    // Set Timer Mode (fill that section and replace TMX with selected timer number)
    REG_TM0D = -TICKS_PER_MILLISECOND;
    REG_TM0CNT |= TIMER_FREQUENCY | TIMER_ENABLE | TIMER_INTERRUPTS;
}

void checkButton(void) {
    u16 buttons = INPUT;

    // KEY_A (z) -> start the game, in "Normal Mode" (from the main menu)
    if ((buttons & KEY_A) == KEY_A) {
        if (gameState == GAME_INACTIVE) {
            blankScreen();
            gameMode = MODE_NORMAL;
            gameState = GAME_INITIALIZE;
        }
    }

    // KEY_B (x) -> start the game, in "Hard Mode" (from the main menu)
    if ((buttons & KEY_B) == KEY_B) {
        if (gameState == GAME_INACTIVE) {
            blankScreen();
            gameMode = MODE_HARD;
            gameState = GAME_INITIALIZE;
        }
    }

    // KEY_SELECT (backspace) -> pause game whilst mid-game
    if ((buttons & KEY_SELECT) == KEY_SELECT) {
        if (gameState == GAME_ACTIVE) {
            blankScreen();
            gameState = GAME_PAUSE;
        }
    }

    // KEY_START (enter) -> resume game whilst mid-game
    if ((buttons & KEY_START) == KEY_START) {
        if (gameState == GAME_PAUSE) {
            blankScreen();
            gameState = GAME_ACTIVE;
        }
    }
    if ((buttons & KEY_RIGHT) == KEY_RIGHT) {
        lastDirection = RIGHT;
    }
    if ((buttons & KEY_LEFT) == KEY_LEFT) {
        lastDirection = LEFT;
    }
    if ((buttons & KEY_UP) == KEY_UP) {
        lastDirection = UP;
    }
    if ((buttons & KEY_DOWN) == KEY_DOWN) {
        lastDirection = DOWN;
    }
}

struct Position getRandPos(int lowerLimitX, int lowerLimitY, int upperLimitX, int upperLimitY) {
    srand(ticks);

    struct Position pos;

    pos.x = rand() % (upperLimitX + 1 - lowerLimitX) + lowerLimitX;
    pos.y = rand() % (upperLimitY + 1 - lowerLimitY) + lowerLimitY;

    return pos;
}

int isPlayerEaten(struct Snake* s, struct Player* p) {
    int i;
    for (i = 0; i < s->length; i++) {
        struct Position snakePos = s->body[i];

        if (isPositionEqual(snakePos, p->position) == 1) {
            return 1;
        }
    }

    return 0;
}

void spawnEntities() {
    struct Position playerSpawn = getRandPos(SPAWN_PLAYER_X_MIN,
                                             SPAWN_PLAYER_Y_MIN,
                                             SPAWN_PLAYER_X_MAX,
                                             SPAWN_PLAYER_Y_MAX);

    struct Position snakeSpawn = getRandPos(SPAWN_SNAKE_X_MIN,
                                            SPAWN_SNAKE_Y_MIN,
                                            SPAWN_SNAKE_X_MAX,
                                            SPAWN_SNAKE_Y_MAX);

    endGoal = getRandPos(SPAWN_GOAL_X_MIN,
                         SPAWN_GOAL_Y_MIN,
                         SPAWN_GOAL_X_MAX,
                         SPAWN_GOAL_Y_MAX);

    player = constructPlayer(playerSpawn.x, playerSpawn.y, 8);

    if (gameMode == MODE_HARD) {
        snake = constructSnake(snakeSpawn.x, snakeSpawn.y,
                               BASE_SNAKE_SPEED + stage * HARD_SPEED_GROWTH_RATE, BASE_SNAKE_LENGTH + stage);

    } else if (gameMode == MODE_NORMAL) {
        snake = constructSnake(snakeSpawn.x, snakeSpawn.y,
                               BASE_SNAKE_SPEED + stage * NORMAL_SPEED_GROWTH_RATE, BASE_SNAKE_LENGTH);
    }
}

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void) {
    initializeGraphics();
    initializeInterrupts();

    while (1) {
    }

    return 0;
}
