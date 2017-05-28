#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#ifndef OPEN_MAX
#define OPEN_MAX 1024
#endif

int __dup2(int fd1, int fd2) {
    if (fd1 < 0 || fd2 < 0) {
        return -1;
    }
    int fds[OPEN_MAX] = {0};
    close(fd2);
    int fd;
    while ((fd = dup(fd1) != fd2)) {
        if(fd == -1) {
            fprintf(stderr, "Dup error!\n");
            exit(2);
        } else {
            fds[fd] = 1;
        }
    }
    for(int i = 0; i < OPEN_MAX; i++) {
        if(!!fds[i]) {
            if(close(i) == -1) {
                fprintf(stderr, "Close error!\n");
                exit(3);
            }
        }
    }
    return fd;
}

int main() {
    int fd = __dup2(STDOUT_FILENO, 5);
    write(fd, "Hello World!\n", 13);
}


