#include <stdlib.h>
#include <stdio.h>

extern char** environ;

int main(int argc, char** argv) {
    printf("argv:\n");
    for(int i = 0; argv[i] != NULL; i++) {
        puts(argv[i]);
    }
    printf("env:\n");
    for(int i = 0; environ[i] != NULL; i++) {
        puts(environ[i]);
    }
    exit(0);
}
