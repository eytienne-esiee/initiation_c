#include <stdio.h>
#include <stdlib.h>

#define tailleAlphabet 27

void nbOccurs(char *T);

int main()
{
    nbOccurs("k Aya k ");
}

void nbOccurs(char *T)
{
    int tabOccur[tailleAlphabet];
    /* init array */
    int h;
    for (h = 0; h < tailleAlphabet; tabOccur[h] = 0, ++h)
        ;
    /* end init */

    int i = -1;
    while (T[++i])
        if (T[i] >= 'a' && T[i] <= 'z')
            tabOccur[T[i] - 'a']++;
        else if (T[i] >= 'A' && T[i] <= 'Z')
            tabOccur[T[i] - 'A']++;
        else if (T[i] == ' ')
            tabOccur[tailleAlphabet - 1]++;

    printf("%d La chaine \"%s\" contient :\n", i, T);
    char j;
    for (j = 0; j < tailleAlphabet; j++)
        if (tabOccur[j] > 0)
            printf("%d fois la lettre '%c'\n", tabOccur[j], (j < tailleAlphabet - 1 ? j + 'a' : ' '));
}