#include <stdio.h>

void swap(int* a, int* b);

int main(){
	int a = 1, b = 5;
	
	printf("a = %d ; b = %d\n", a, b);
	// swap(&a, &b);
	a += b ;
	b = a - b;
	a -= b;
	printf("a = %d ; b = %d\n", a, b);
	
	
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

