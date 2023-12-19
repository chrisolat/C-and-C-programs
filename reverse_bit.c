#include <stdio.h>

unsigned char shiftByte(unsigned char);

unsigned char shiftByte(unsigned char b){
	unsigned char a = '\0';
	int i = 0;
	
	for(;i < 8; i++){
		a = a << 1;
		unsigned char temp = b & 1;
		b = b >> 1;
		a = a | temp;
	}
	return a;
}

int main(){
	unsigned char test = 0x80;
	printf("%x\n", shiftByte(test));
}