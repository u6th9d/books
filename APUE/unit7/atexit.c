#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

void hello() {
    printf("Hello");
}
void world() {
    printf("World");
}
void crlf() {
    printf("\n");
}

int main() {
    atexit(&crlf);
    atexit(&world);
    atexit(&hello);
#ifdef EXIT
    exit(0);
#elif __EXIT
    _exit(0);
#else
    return 0;
#endif
}
