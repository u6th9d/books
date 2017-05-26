#include <unistd.h>

int main() {
    write(STDOUT_FILENO, "Hello APUE!\n", 12);
}
