#include <stdint.h>
#include "../kernel/keyboard.h"

#define PORT 0x60

static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

char get_char() {
    char key = 0;
    uint8_t sc = inb(PORT);

    if (sc > 0 && sc < 58) {
        const char keymap[] = "??1234567890-=\b\tqwertyuiop[]\n?asdfghjkl;'`?\\zxcvbnm,./?";
        key = keymap[sc];
    }

    return key;
}
