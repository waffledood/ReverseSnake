#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#define SPRITE_WIDTH 10
#define EMPTY_DIGIT -1

void drawSprite(int numb, int N, int x, int y) {
    // Gift function: displays sprite number numb on screen at position (x,y), as sprite object N
    *(unsigned short *)(0x7000000 + 8 * N) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8 * N) = x;
    *(unsigned short *)(0x7000004 + 8 * N) = numb * 2;
}

void drawU16(unsigned short num, int id, int x, int y) {
    int digit_arr[5] = {EMPTY_DIGIT, EMPTY_DIGIT, EMPTY_DIGIT, EMPTY_DIGIT, EMPTY_DIGIT};

    if (num == 0) {
        digit_arr[0] = 0;
    }

    int i;
    for (i = 0; num > 0; i++) {
        int digit = num % 10;
        digit_arr[i] = digit;
        num /= 10;
    }

    for (i = 5 - 1; i >= 0; i--) {
        int pos = 5 - 1 - i;
        int x_digit = x + SPRITE_WIDTH * pos;
        drawSprite(digit_arr[i], id + i, x_digit, y);
    }
}
#endif // __GRAPHICS_H__