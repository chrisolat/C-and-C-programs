#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b){
	return strcmp(*(char**)a, *(char**)b);
}

int main(){
	char* strings[] = {"hey","hi","hello"};
	int arrsize = sizeof(strings)/sizeof(strings[0]);
	qsort(strings, arrsize, sizeof(char*), cmp);
	for (int i = 0; i < arrsize; i++){
		printf("%s", strings[i]);
	}
	return 0;
}