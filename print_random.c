#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	int nums[50];
	int i;
	int *arr = nums;
	
	srand(time(NULL));
	i = 0;
	do{
		*arr = rand();
		printf("Random number from two different angles are %d and %d\n", *arr, nums[i]);
		i++;
		arr++;
		printf("value if i is %d , value of arr is %lu\n\n", i, (unsigned long)arr);
	}while(i < 50);
	return 0;
}