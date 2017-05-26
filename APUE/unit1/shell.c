#include <sys/wait.h>
#include <unistd.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUF_SIZE
#define BUF_SIZE 4096
#endif

static void sigHandler(int signo) {
    printf("\n");
}

int main() {
    if (signal(SIGINT, sigHandler) == SIG_ERR) {
        exit(1);
    }
    char buffer[BUF_SIZE] = {};
    printf("Welcome!\n");
    printf("/> ");
    while(fgets(buffer, BUF_SIZE, stdin) != NULL) {
        size_t length = strlen(buffer);
        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork error!\n");
            exit(2);
        }
        if (pid == 0) {
            execlp(buffer, buffer, NULL);
            fprintf(stderr, "Error command!\n");
            exit(3);
        } else {
            int status;
            if (waitpid(pid, &status, 0) < 0) {
                exit(4);
            }
            printf("/> ");
        }
    }
    printf("\n");
    exit(0);
}
