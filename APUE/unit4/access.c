#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if(access(argv[i], F_OK) == -1) {
            printf("no such file or directory!\n");
            continue;
        }
        if(access(argv[i], R_OK) != -1) {
            printf("read ok ");
        }
        if(access(argv[i], W_OK) != -1) {
            printf("write ok ");
        }
        if(access(argv[i], X_OK) != -1) {
            printf("exec ok ");
        }
        printf("\n");
    }

    exit(0);
}
