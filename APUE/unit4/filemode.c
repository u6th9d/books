#include <unistd.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    struct stat buf;
    const char* ptr;
    for(int i = 1; i < argc; i++) {
        if(lstat(argv[i], &buf) == -1) {
            fprintf(stderr, "%s lstat error!\n", argv[i]);
            continue;
        }
        if(S_ISREG(buf.st_mode)) {
            ptr = "regular";
        } else if(S_ISDIR(buf.st_mode)) {
            ptr = "directory";
        } else if(S_ISCHR(buf.st_mode)) {
            ptr = "character special";
        } else if(S_ISBLK(buf.st_mode)) {
            ptr = "block special";
        } else if(S_ISFIFO(buf.st_mode)) {
            ptr = "fifo";
        } else if(S_ISSOCK(buf.st_mode)) {
            ptr = "socket";
        } else if(S_ISLNK(buf.st_mode)) {
            ptr = "symbolic link";
        } else {
            ptr = "unknow mode";
        }
        printf("%s: %s\n", argv[i], ptr);
    }
    exit(0);
}

// ./a.out /dev/null /dev/tty /etc /etc/passwd
