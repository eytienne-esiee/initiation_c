#include <stdio.h>

#define SIZE 3

void affiche_tab(double t[], int n);
double init(double t[], int n);
double somme(double t[], int n);
double moyenne(double t[], int n);
int indice_premier_negatif(double t[], int n);
double valeur_plus_grand(double t[], int n);
int indice_plus_grand(double t[], int n);
int ordonne(double t[], int n);
void ajoutAukieme(double t[], int n, int k, double E);
void supprime_debut(double t[], int n);
void supprime_index(double t[], int n, int k);

int main()
{
	double myTab[SIZE] = {1., 4., -3.};
	// = {1., 2., 3.};
	// affiche_tab(myTab, SIZE);
	printf("-------------------------------\n");
	// init(myTab, SIZE);
	supprime_index(myTab, SIZE, 1);
	affiche_tab(myTab, SIZE);
	// printf("moyenne : %lf\n", moyenne(myTab, SIZE));
	// printf("indice_premier_negatif : %d\n", indice_premier_negatif(myTab, SIZE));
	// ajoutAukieme(myTab, SIZE, 0, 4.);
	// printf("valeur_plus_grand : %lf\n", valeur_plus_grand(myTab, SIZE));
	// printf("%s\n", ordonne(myTab, SIZE) ? "sorted" : "not sorted");
}

void supprime_index(double t[], int n, int k)
{
	if (k < n - 1)
	{
		int i;
		for (i = k; i < n - 1; ++i)
			t[i] = t[i + 1];
	}
	t[n - 1] = 0.;
}

void supprime_debut(double t[], int n)
{
	supprime_index(t, n, 0);
}

void ajoutAukieme(double t[], int n, int k, double E)
{
	t[k] += E;
}

int ordonne(double t[], int n)
{
	int i;
	for (i = 1; i < n; ++i)
		if (t[i - 1] > t[i])
			return 0;
	return 1;
}

int indice_plus_grand(double t[], int n)
{
	int maxIndex = 0;
	int i;
	for (i = 1; i < n; ++i)
		maxIndex = t[i] > t[maxIndex] ? i : maxIndex;
	return maxIndex;
}

double valeur_plus_grand(double t[], int n)
{
	return t[indice_plus_grand(t, n)];
}

int indice_premier_negatif(double t[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		if (t[i] < 0.)
			return i;
}

double moyenne(double t[], int n)
{
	return somme(t, n) / n;
}

double somme(double t[], int n)
{
	double somme = 0;
	int i;
	for (i = 0; i < n; ++i)
		somme += t[i];
	return somme;
}

double init(double t[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		t[i] = 0.;
}

void affiche_tab(double t[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%lf\n", t[i]);
	}
}
