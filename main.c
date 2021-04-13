// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------

#include "gba.h"
#include "graphics.h"
#include "player.h"
#include "snake.h"

#define TICKS_PER_MILLISECOND 16781
// #define PLAYER_ID 1

#define GAME_INACTIVE 0
#define GAME_PAUSE 1
#define GAME_ACTIVE 2

#define MODE_NORMAL 0
#define MODE_HARD 1

// pseudo boolean to track the status of the game
// 0 -> game is not active
// 1 -> game is active 
//#define gameState 0

int gameState = GAME_INACTIVE;
int gameMode = MODE_NORMAL;

enum DIRECTION lastDirection = NONE;
struct Player player;
struct Snake snake;

unsigned time = 0;

void handler(void) {
    REG_IME = 0x00;  // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_TIMER0) == INT_TIMER0) {
        initalizeGame();
    }

    REG_IF = REG_IF;  // Update interrupt table, to confirm we have handled this interrupt
    REG_IME = 0x01;   // Re-enable interrupt handling
}

// function to initialize the game 
void initalizeGame() {

    /*time++;
    in num = time / 1000; */
    checkButton();

    if (gameState == GAME_PAUSE) {
        return;
    } else if (gameState == GAME_ACTIVE) {
        startGame();
    } else {
        setMainMenu();
    }
}

// function to start the game 
void startGame() {
    
    time++;
    int num = time / 1000;
    //drawU16(num, 500, 180, 10);
    //checkButton();
    movePlayer(&player, lastDirection);
    moveSnake(&snake, player.position);

    if (isPlayerEaten(&snake, &player)) {
        gameState = GAME_INACTIVE;
        blankScreen();
        spawnEntities();
        return;
    }
        
    drawPlayer(player);
    drawSnake(&snake);
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

    if ((buttons & KEY_A) == KEY_A) {
        // set up Key A as the button to start the game (from the main menu)
        if (gameState == GAME_INACTIVE) {
            blankScreen();
            gameMode = MODE_NORMAL;
        }
        //startGame();
    }
    if ((buttons & KEY_B) == KEY_B) {
        if (gameState == GAME_INACTIVE) {
            blankScreen();
            gameMode = MODE_HARD;
        }
    }
    if ((buttons & KEY_SELECT) == KEY_SELECT) {
    }
    if ((buttons & KEY_START) == KEY_START) {
        // set up "Start" button as the button to return to main menu whilst mid-game
        if (gameState == GAME_ACTIVE) {
            blankScreen();
            gameState = GAME_PAUSE;
        } else if (gameState == GAME_PAUSE) {
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
    srand(time);

    struct Position pos;

    pos.x = rand() % (upperLimitX + 1 - lowerLimitX) + lowerLimitX;
    pos.y = rand() % (upperLimitY + 1 - lowerLimitY) + lowerLimitY;

    return pos;
}

int isPlayerEaten(struct Snake* s, struct Player* p) {
    int i;
    for (i = 0; i < s->length; i++)
    {
        struct Position snakePos = s->body[i];

        if (isPositionEqual(snakePos, p->position) == 1) {
            return 1;
        }
    }

    return 0;
}

void spawnEntities() {
    struct Position playerSpawn;
    struct Position snakeSpawn;
    struct Position endGoal;

    playerSpawn = getRandPos(7, 0, 23, 10);
    snakeSpawn = getRandPos(7, 0, 15, 15);
    endGoal = getRandPos(0, 7, 12, 15);

    player = constructPlayer(playerSpawn.x, playerSpawn.y, 10);
    snake = constructSnake(snakeSpawn.x, snakeSpawn.y, 5, 5);
}

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void) {
    initializeGraphics();
    initializeInterrupts();
    spawnEntities();

    while (1) {
    }

    return 0;
}
