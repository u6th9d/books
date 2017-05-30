#include <unistd.h>
#include <setjmp.h>

#include <stdlib.h>
#include <stdio.h>

jmp_buf buffer;

int main() {
    int state = setjmp(buffer);
    if(state == 0 || state == 1) {
        printf("Hello");
        longjmp(buffer, 2);
    } else {
        printf("World");
    }
    printf("\n");
    sleep(1);
    longjmp(buffer, 1);
    exit(0);
}
