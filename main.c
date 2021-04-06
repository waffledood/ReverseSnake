// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------

#include "gba.h"
#include "graphics.h"
#include "player.h"

#define TICKS_PER_MILLISECOND 16781
#define PLAYER_ID 1

enum DIRECTION lastDirection = NONE;
struct Player elongate;

unsigned time = 0;

void handler(void) {
    REG_IME = 0x00;  // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_TIMER0) == INT_TIMER0) {
        time++;
        int num = time / 1000;
        checkButton();
        drawU16(num, 500, 180, 10);
        movePlayer(&elongate, lastDirection);
        drawPlayer(elongate);
    }

    REG_IF = REG_IF;  // Update interrupt table, to confirm we have handled this interrupt
    REG_IME = 0x01;   // Re-enable interrupt handling
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
    }
    if ((buttons & KEY_B) == KEY_B) {
    }
    if ((buttons & KEY_SELECT) == KEY_SELECT) {
    }
    if ((buttons & KEY_START) == KEY_START) {
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

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void) {
    initializeGraphics();
    initializeInterrupts();

    elongate = constructPlayer(50, 50, 10);

    while (1) {
    }

    return 0;
}
