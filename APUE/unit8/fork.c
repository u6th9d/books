#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

int gval = 1;

int main() {
// int fd = dup(STDOUT_FILENO);
    int lval = 2;
#ifdef _VFORK
// printf("vfork\n");
    pid_t p = vfork();
#else
// printf("fork\n");
    pid_t p = fork();
#endif
    if(p < 0) {
        fprintf(stderr, "Fork error!\n");
        exit(1);
    }
    if(p == 0) {
        gval += 1;
        lval += 1;
#ifdef __EXIT
// printf("_exit\n");
        _exit(0);
#else
// printf("exit\n");
// close(STDOUT_FILENO);
// close(fd);
        exit(0);
#endif
    } else {
#ifndef _VFORK
        sleep(2);
#endif
        printf("gval = %d, lval = %d\n", gval, lval);
// write(fd, "fd\n", 3);
        exit(0);
    }
}

// gcc fork.c && gcc -D__EXIT fork.c => 1 2
//
// gcc -D_VFORK -D__EXIT fork.c => 2 3
//
// gcc -D_VFORK fork.c => ...
