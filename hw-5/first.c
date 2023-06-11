#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path to fifo>\n", argv[0]);
        return 1;
    }

    int fd;
    char * fifo = argv[1];

    mkfifo(fifo, 0666);

    char str1[80], str2[80];
    
    while (1) {
        fd = open(fifo, O_RDWR);

        fgets(str2, 80, stdin);
        write(fd, str2, strlen(str2) + 1);

        read(fd, str1, sizeof(str1));
        printf("Received: %s\n", str1);

        close(fd);
    }
    return 0;
}
