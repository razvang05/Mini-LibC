#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <internal/io.h>

int puts(const char *str) {
    int nr = 0;
    for (; *str != '\0'; str++) {
        nr = nr + write(1, str, 1);
    }
    nr = nr + write(1, "\n", 1);

    return nr;
}
