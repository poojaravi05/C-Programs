//C program to read data from "/dev/mydevice" and print it.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/mydevice", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buf[256];
    ssize_t n = read(fd, buf, sizeof(buf));

    if (n < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    write(STDOUT_FILENO, buf, n);
    close(fd);
    return 0;
}
