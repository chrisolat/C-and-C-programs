#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024
#define MAXROW 50

void print_strings(char**, int);

void print_strings(char** strings, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%s", strings[i]);
	}
}

int main(int argc, char *argv[]){
	if(argc == 1){
		puts("Enter file name");
	}
	FILE* fp;
	
	// check that file exists and can be opened
	if((fp = fopen(argv[1], "r")) == NULL){
		perror("Error opening file");
		return 1;
	}
	
	char buffer[MAXSIZE];
	int i = 0;
	char* strings[MAXROW];
	// read file line by line
	while((fgets(buffer, MAXSIZE, fp) != NULL) && i < MAXROW){
		strings[i] = malloc(strlen(buffer)+1);
		strcpy(strings[i], buffer);
		i++;
	}
	
	print_strings(strings, i);

	for(int j = 0; j < i; j++){
		free(strings[j]);
	}
	
	fclose(fp);
	return 0;
}