#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 1024

void sort(int*,int);
int cmp(const void *p1, const void *p2);

int cmp(const void *p1, const void *p2){
	return *((int*)p1) - *((int*)p2);
}

void sort(int* ints, int n){
	qsort(ints,n,sizeof(int),cmp);
}

int main(int argc, char *argv[]){
	char buf[BUFFSIZE+1];
	puts("Enter number of ints to sort");
	fgets(buf, BUFFSIZE, stdin);
	int n;
	n = atoi(buf);
	int *ints = malloc(n * sizeof(int));
	char num[BUFFSIZE+1];
	int i;
	for(i=0;i<n;i++){
		puts("Enter num:\n");
		fgets(num, BUFFSIZE, stdin);
		ints[i] = atoi(num);
	}
	puts("Array before sort:\n");
	
	for(i = 0; i < n; i++){
		printf("%d, ", ints[i]);
	}
	puts("\n");
	sort(ints,n);
	puts("Array after sort:\n");
	for(i = 0; i < n; i++){
		printf("%d, ", ints[i]);
	}
	free(ints);
	return 0;
}