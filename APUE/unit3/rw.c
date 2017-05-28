#include <unistd.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv) {
    int size;
    if (argc != 2) {
        size = 8192;
    } else {
        size = atoi(argv[1]);
    }
    char* buffer = (char*)malloc(size);
    assert(buffer != NULL);
    ssize_t n;
    while((n = read(STDIN_FILENO, buffer, size)) > 0) {
        if (write(STDOUT_FILENO, buffer, n) != n) {
            fprintf(stderr, "Write error!\n");
            exit(1);
        }
    }
    if (n == -1) {
        fprintf(stderr, "Read error!\n");
        exit(2);
    }
    free(buffer);
    exit(0);
}

//dd if=/dev/zero bs=2048 count=409600 | pv | ./a.out 16 > /dev/null

