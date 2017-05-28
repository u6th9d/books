#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#ifndef BUF_SIZE
#define BUF_SIZE 8192
#endif

static void modify_flag(int fd, int flag, int op) {
    int val = fcntl(fd, F_GETFD);
    if(val == -1) {
        fprintf(stderr, "fcntl getfd error!\n");
        exit(1);
    }
    if(!!op) {   // turn on
        val |= flag;
    } else {    // turn off
        val &= ~flag;
    }
    if (fcntl(fd, F_SETFD, val) == -1) {
        fprintf(stderr, "fcntl setfd error!\n");
        exit(2);
    }
}


int main() {
    char buffer[BUF_SIZE] = {};
    ssize_t n;
#ifdef __O_SYNC
    fprintf(stderr, "__O_SYNC!!\n");
    modify_flag(STDOUT_FILENO, O_SYNC, 1);
#endif
    while((n = read(STDIN_FILENO, buffer, BUF_SIZE )) > 0) {
        if (write(STDOUT_FILENO, buffer, n) != n) {
            fprintf(stderr, "Write error!\n");
            exit(1);
        }
    }
    if (n == -1) {
        fprintf(stderr, "Read error!\n");
        exit(2);
    }
#ifdef __FSYNC
    fprintf(stderr, "__FSYNC!\n");
    fsync(STDOUT_FILENO);
#elif __FDATASYNC
    fprintf(stderr, "__FDATASYNC!\n");
    fdatasync(STDOUT_FILENO);
#endif
    exit(0);
}

// dd if=/dev/zero bs=4M count=2560 | pv > file.bin
//
// gcc sync.c -D__FSYNC
// time ./a.out < file.bin > copy.bin
//
// gcc sync.c
// time ./a.out < file.bin > copy.bin
//
// time ./a.out < file.bin > /dev/null


