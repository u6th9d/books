#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd = open("./hole", O_RDWR | O_CREAT | O_EXCL, 0664);
    if (fd < 0) {
        fprintf(stderr, "Open error!\n");
        exit(1);
    }
    if (write(fd, "Hello", 5) != 5) {
        fprintf(stderr, "Write error!\n");
        exit(2);
    }
    if (lseek(fd, 5, SEEK_END) == -1) {
        fprintf(stderr, "Lseek error!\n");
        exit(3);
    }
    if (write(fd, "World", 5) != 5) {
        fprintf(stderr, "Write error!\n");
        exit(4);
    }
    close(fd);
    exit(0);
}

// od -h file

