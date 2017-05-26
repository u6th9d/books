#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Error arguement!\n");
        exit(1);
    }
    DIR* dp = opendir(argv[1]);
    if (!dp) {
        fprintf(stderr, "Error directory!\n");
        exit(2);
    }
    struct dirent* dirp = readdir(dp);
    while(dirp) {
        printf("%s\n", dirp->d_name);
        dirp = readdir(dp);
    }
    closedir(dp);
    exit(0);

}
