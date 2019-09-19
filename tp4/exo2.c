#include <stdio.h>
#include <stdlib.h>

void ajouterALaFinTab(int *dest, int *src);
void ajouterALaFinPtr(int *dest, int *src);

int main()
{
    int T[20] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, S[10] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
    ajouterALaFinPtr(T, S);
    int i = 0;
    while (T[i])
        printf("%d\t", T[i++]);
    printf("\n");
}

void ajouterALaFinTab(int dest[], int src[])
{
    int i = 0;
    while (dest[i])
        ++i;
    int j = 0;
    while (dest[i + j] = src[j])
        ++j;
    dest[i + j - 1] = 0;
}

void ajouterALaFinPtr(int *dest, int *src)
{
    while (*(dest))
        dest++;
    while (*dest = *src)
        ++dest && ++src;
    *(dest - 1) = 0;
}