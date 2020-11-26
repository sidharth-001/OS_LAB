#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    pid = fork();

    if(pid<0){
        fprintf(stderr, "Fork Failed!");
        return 1;
    }
    else if(pid == 0){
        execlp("/mnt/c/Users/Sidharth/os/name.out", "./name.out", NULL);
    }else{
        wait(NULL);
        printf("Child complete!\n");
    }
    return 0;
}