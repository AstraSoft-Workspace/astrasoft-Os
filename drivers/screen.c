#include <stdint.h>
#include "../kernel/screen.h"

#define VIDEO_MEMORY (uint16_t*)0xB8000
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0F

int cursor = 0;

void print(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        VIDEO_MEMORY[cursor++] = (WHITE_ON_BLACK << 8) | str[i];
    }
}

void clear_screen() {
    for (int i = 0; i < MAX_COLS * 25; i++) {
        VIDEO_MEMORY[i] = (WHITE_ON_BLACK << 8) | ' ';
    }
    cursor = 0;
}
