#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int file1, file2;
    char buff[1024];
    long int n;
    if(((file1 = open(argv[1], O_RDONLY)) == -1) ||
    ((file2=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC, 0700)) == -1)){
        printf("file problem");
        exit(1);
    }
    while((n=read(file1, buff, 1024)) > 0){
        if(write(file2, buff, n) != n){
        printf("writing problem ");
        exit(3);
        }
    }
    close(file1);
    close(file2);
}