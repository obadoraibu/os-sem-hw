#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h> 

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten, pos;
    int readfFile, writeFile;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    readfFile = open(argv[1], O_RDONLY);
    if (readfFile == -1) {
        perror("Source file open error");
        return 1;
    }

    writeFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (writeFile == -1) {
        perror("Destination file open error");
        close(readfFile);
        return 1;
    }

    while ((bytesRead = read(readfFile, buffer, BUFFER_SIZE)) > 0) {
        pos = 0;
        do {
            bytesWritten = write(writeFile, &buffer[pos], bytesRead - pos);
            if (bytesWritten >= 0) {
                pos += bytesWritten;
            } else {
                perror("Write error");
                close(readfFile);
                close(writeFile);
                return 1;
            }
        } while (bytesRead > pos);
    }

    if (bytesRead == -1) {
        perror("Read error");
    }

    if (close(readfFile) == -1) {
        perror("Source file close error");
        return 1;
    }

    if (close(writeFile) == -1) {
        perror("Destination file close error");
        return 1;
    }

    return 0;
}
