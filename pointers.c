#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int a = 7;
	int b = 3;
	int* c = &b;
	unsigned char *peek;
	
	memcpy(&b, &a, sizeof(int));
	printf("a = %d, b = %d\n", a, b);
	
	*c = 9;
	printf("a = %d, b = %d\n", a, b);
	
	c[0] = 13;
	printf("a = %d, b = %d\n", a, b);
	
	c = &a;
	c[0] = 1;
	printf("a = %d, b = %d\n", a, b);
	
	printf("Peeking at bytes in a... \n");
	peek = (unsigned char *) &a;
	for(int i=0; i < sizeof(a); i++){
		printf("%02x\n", peek[i]);
	}
	
	putchar(97);
	putchar('a');
	putchar((char) "hello");
	return 0;
}