#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 1000
/*
    How can You Compile and Run Given Program
    Compile - gcc task4.c -o task4
    HOW TO RUN ->
        1)  ./task4 -> It'll ask user about filename
        2)  ./task4 filename -> it'll open filename and send output to stdout
        3)  ./task4 -f filename -> it'll check given option and act Accordingly
*/
int main(int argc , char * argv[]) {
    int opt; 
    // If More than Two Arguments in CLA
    if ( argc > 3) {
        printf("\nToo Many Arguments\n");
        exit(0);
    }
    char filename[20];
    // If No file name given by CMD , then Ask from USER
    if ( argc == 1 ) {
        printf("\nEnter Filename\t:\t");
        scanf("%s" , filename);
    }
    // If only filename given by CMD , Directly copy to filename
    else if (argc == 2) {
        strcpy(filename , argv[1]);
    }
    // If Option is given , check for legality of option.
    else {
        while((opt = getopt(argc, argv, "f:")) != -1)  {  
            switch (opt) {
                case 'f':
                        strcpy(filename , argv[2]);
                        break;
               
                default:
                    fprintf(stderr, "Usage: ./task4 %s OR ./task4 -f  %s\n", argv[2] , argv[2]);
                    exit(EXIT_FAILURE);
                } 
        }  
    }
    int fd;   // declaring file descriptor ->
    char* buffer; // declaring buffer as Character
    buffer = (char *)malloc(sizeof(char)*BUFFER_SIZE);  // allocating memory to buffer
    fd = open ( filename, O_RDONLY );   // opening file
    while ( read ( fd , buffer, sizeof(buffer) ) != 0 ) { // reading from file
        fputs(buffer , stdout); //sending buffer data to stdout
    }
    strcpy(buffer , "");
    close (fd);
    printf("\n");
}
