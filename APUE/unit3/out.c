#include <unistd.h>

#include <stdlib.h>

int main() {
    write(STDOUT_FILENO, "STDOUT\n", 7);
    write(STDERR_FILENO, "STDERR\n", 7);
    exit(0);
}

// ./a.out 2>&1 > outfile
// ./a.out > outfile 2>&1

