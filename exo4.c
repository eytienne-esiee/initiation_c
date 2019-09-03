#include <stdio.h>

int main(){
	printf("Bonjour !\n");
	int a, b;
	printf("Veuillez saisir le premier nombre : ");
	scanf("%d", &a);
	printf("Veuillez saisir le second nombre : ");
	scanf("%d", &b);
	printf("\nCalculs :\n");
	printf("\t%d + %d = %d\n", a, b, a+b);
	printf("\t%d - %d = %d\n", a, b, a-b);
	printf("\t%d * %d = %d\n", a, b, a*b);
	printf("\t%d / %d = %.3f\n", a, b, (float)a/b);
	printf("Au revoir !\n");
}
