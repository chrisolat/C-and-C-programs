#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int pid;
	pid = fork();
	
	if (pid == 0){
		puts("In child process");
	}else{
		puts("In parent process");
	}
	
	return 0;
}