#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void menu();
double somme(int pN);
double avg(int pN);
void testCaract(char pC);
void codesAscii();
double conversionFC(double celsius);

int main()
{
	// menu();
	// printf("result : %lf\n", somme(3));
	// printf("result : %lf\n", avg(3));
	// testCaract('&');
	// codesAscii();
	printf("%lf\n", conversionFC(37));
}

double conversionFC(double celsius)
{
	return (celsius * 9 / 5) + 32;
}

void codesAscii()
{
	char index = 0;
	do
	{
		char output[10];
		sprintf(output, "%d => %c%c", index, index);
		printf("%8.8s%c", output, index % 8 == 0 ? '\n' : '\t');
		++index;
	} while (index != 0);
	printf("\n");
}

void testCaract(char pC)
{
	char *type;
	if (pC >= (int)'a' && pC <= (int)'z')
		type = "minuscule";
	else if (pC >= (int)'A' && pC <= (int)'Z')
		type = "majuscule";
	else if (atoi(&pC) != 0 || pC == '0')
		type = "chiffre";
	else if (pC == '\n')
		type = "retour à la ligne";
	else
		type = "autre";
	printf("C'est un caractère de type : %s\n", type);
}

double avg(int pN)
{
	return somme(pN) / pN;
}

double somme(int pN)
{
	double somme = 0.;
	int index;
	for (index = 0; index < pN; ++index)
	{
		double input;
		printf("input n°%d : \n", index + 1);
		scanf("%lf", &input);
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		if (input < 0.)
		{
			printf("FIN\n");
			break;
		}
		somme += input;
	}
	return somme;
}

void menu()
{
	char *options[SIZE] = {"option 1", "option 2", "option 3"};
	char input[255];
	strcpy(input, "\0");
	int choice = -2;
	do
	{
		int i;
		printf("Choisissez une option :\n");
		for (i = 0; i < SIZE; ++i)
		{
			printf("%s\n", options[i]);
		}
		scanf("%s", input);
		choice = atoi(input) - 1;
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
			choice = -2;
	} while (!(choice >= -2 && choice < SIZE && choice != -1));
	if (choice == -2)
	{
		printf("fuyez !\n");
	}
	else if (choice > -1)
	{
		printf("Vous avez choisi : %s\n", options[choice]);
	}
}
