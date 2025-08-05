#include "screen.h"
#include "keyboard.h"

void kernel_main() {
    clear_screen();
    print("Welcome to \nAstraSoft OS\n\n");

    print("Type something: ");

    while (1) {
        char c = get_char();
        if (c) {
            char str[2] = {c, '\0'};
            print(str);
        }
    }
}
