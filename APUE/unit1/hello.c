#include <unistd.h>

#include <stdlib.h>

int main() {
    write(STDOUT_FILENO, "Hello APUE!\n", 12);
    exit(0);
}
