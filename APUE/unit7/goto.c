#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if(argc != 4) {
        fprintf(stderr, "error parm!\n");
        exit(0);
    }
    long a = atol(argv[1]);
    long b = atol(argv[2]);
    long c = atol(argv[3]);
    int flag = 0;
    void* p = malloc(a);
    if(p == NULL) {
        flag = 1;
        goto end1;
    }
    void* q = malloc(b);
    if(q == NULL) {
        flag = 2;
        goto end2;
    }
    void* r = malloc(c);
    if(r == NULL) {
        flag = 3;
        goto end3;
    }
    //
    free(r);
    end3:
    free(q);
    end2:
    free(p);
    end1:
    exit(flag);
}
