#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd = open("./lseek", O_RDWR | O_CREAT | O_APPEND, 0664);

    write(fd, "Hello", 5); 
    lseek(fd, 0, SEEK_SET);
    write(fd, "World", 5);
    
    lseek(fd, 0, SEEK_SET);
    char buffer[32] = {0};
    read(fd, buffer, 31);
    puts(buffer);

    close(fd);
    exit(0);
}

