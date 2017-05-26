#include <unistd.h>

#include <stdlib.h>

#ifndef BUF_SIZE
#define BUF_SIZE 4096
#endif

int main() {
    char buffer[BUF_SIZE] = {};
    int n = read(STDIN_FILENO, buffer, BUF_SIZE);
    while(n > 0) {
        if (write(STDOUT_FILENO, buffer, n) != n) {
            exit(1);
        }
        n = read(STDIN_FILENO, buffer, BUF_SIZE);
    }
    exit(0);
}
