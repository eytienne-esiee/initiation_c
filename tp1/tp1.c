#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 3

void menu();
double somme(int pN);
double avg(int pN);
void testCaract(char pC);

int main(){
	menu();
	// printf("result : %lf\n", somme(3));
	// printf("result : %lf\n", avg(3));
	// testCaract('A');
}

void testCaract(char pC){
	char* type = "autre";
	printf("%c", tolower((int) pC));
	printf("C'est un caractère de type : %s\n", type);
}

double avg(int pN){
	return somme(pN)/pN;
}

double somme(int pN){
	double somme = 0.;
	int index;
	for( index=0 ; index < pN ; ++index ){
		double input;
		printf("input n°%d : \n", index+1);
		scanf("%lf", &input);
		int c;
		while ((c = getchar()) != '\n' && c != EOF) { }
		if(input < 0.){
			printf("FIN\n");
			break;
		}
		somme += input;
	}
	return somme;
}

void menu(){
	char* options[SIZE] = {"option 1","option 2","option 3"};
	char input[255];
	strcpy(input,"\0");
	int choice = -2;
	do {
		int i;
		printf("Choisissez une option :\n");
		for( i = 0 ; i < SIZE ; ++i ){
			printf("%s\n", options[i]);
		}
		scanf("%s", &input);
		choice = atoi(input)-1;
		printf("atoi %d\n", choice);
		if(strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
			choice = -2;
	} while (!(choice >= -2 && choice == choice < SIZE));
	if(choice == -1){
		printf("fuyez !\n");
	} else if(choice > 1){
		printf("Vous avez choisi : %s\n", options[choice]);
	}
}
