#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	printf("HELLO");
	fflush(stdout);
	int i = 0;
	for(; i < strlen("HELLO"); i++){
		sleep(1);
		putchar(8);
		putchar(' ');
		putchar(8);
		fflush(stdout);
	}
	return 0;
}