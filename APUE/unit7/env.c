#include <stdlib.h>
#include <stdio.h>

extern char** environ;

int main() {
    char** copy = environ;

    if(setenv("Hello", "World", 1) != 0) {
        fprintf(stderr, "setenv error!");
        exit(1);
    }
    if(copy == environ) {
        printf("==\n");
    } else {
        printf("!=\n");
    }

    char* p = *copy;
    printf("%s\n", p);
    char* q = *environ;
    printf("%s\n", q);
    if(p == q) {
        printf("==\n");
    } else {
        printf("!=\n");
    }

    exit(0);
}
