#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1

int main(int argc, char *argv[]) {
    int inFile, outFile, rdCount, wrCount;
    char buffer[1024];

    if(argc != 3) exit(1);

    inFile = open(argv[1], O_RDONLY);
    if(inFile < 0) exit(2);

    outFile = creat(argv[2], 0700);
    if(outFile < 0) exit(3);

    while(TRUE) {
        rdCount = read(inFile, buffer, sizeof(buffer));
        if(rdCount < 0) break;

        wrCount = write(outFile, buffer, rdCount);
        if(wrCount < 0) exit(4);

    }

    close(inFile);
    close(outFile);

    if(rdCount < 0) exit(5);

    exit(0);

}
