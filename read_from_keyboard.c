#include <stdio.h>

int main(int argc, char * argv[]){
	int c;
	while((c = getchar()) != EOF){
		printf("Entered char is %c\n", c);
	}
	return 0;
}