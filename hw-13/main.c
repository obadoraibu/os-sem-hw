#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char oldname[256];
    char newname[256];

    int fd = open("a", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    close(fd);
    strcpy(oldname, "a");

    int depth;
    for (depth = 0; ; depth++) {
        sprintf(newname, "a%d", depth);

        if (symlink(oldname, newname) == -1) {
            perror("Failed");
            exit(EXIT_FAILURE);
        }

        int fd = open(newname, O_RDONLY);
        if (fd == -1) {
            break; 
        }
        close(fd);

        strcpy(oldname, newname);
    }

    printf("Максимальная глубина: %d\n", depth);

    return 0;
}
