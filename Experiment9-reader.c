//reader.cpp
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include<fcntl.h>

int main(){
	int pid1, pid2; 
	pid1 = fork();  
	if(pid1 == 0){ 
		int fd = open("sample.txt", O_RDONLY); 
		printf("Opened the fd with child 1, fd = %d\n", fd);
		if(fd == -1){
			perror("Error: unable to open!");		 
		} 
		printf("child(1) -> pid1 = %d and ppid = %d\n", getpid(), getppid()); 
		return 0;
	}else{ 
		pid2 = fork(); 
		if(pid2 == 0){ 
			int fd = open("dummy.txt", O_RDONLY); 
			if(fd == -1){
				perror("Error: unable to open!");			 
			} 
			printf("Opened the fd with child 2, fd = %d\n", fd); 
			printf("child(2) -> pid2 = %d and ppid = %d\n", getpid(), getppid()); 
		}else{ 
			printf("parent -> pid = %d\n", getpid()); 
		} 
	}
	return 0; 
}