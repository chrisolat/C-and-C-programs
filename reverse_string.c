#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct test {
	char c;
	int num;
};

void reverse_string(char *);

void reverse_string(char *str){
	printf("%s\n",str);
	int l = 0;
	int r = strlen(str)-1;
	char temp;
	while(l<r){
		temp = str[l];
		str[l] = str[r];
		str[r] = temp;
		l++;r--;
	}
	printf("%s",str);
}

int main(int argc, char *argv[]){
	struct test t;
	printf("%d\n", sizeof(t));
	if (argc == 1){
		char str[] = "my string";
		reverse_string(str);
	}else{
		int buf2[10];
		char buffer[11];
		printf("%d\n",sizeof(buf2));
		if(strlen(argv[1]) < sizeof(buffer)){
			memcpy(buffer, argv[1], strlen(argv[1]));
			buffer[strlen(argv[1])] = '\0';
			reverse_string(buffer);
		}else{
			puts("Input string is too long\n");
		}
	}
	return 0;
}