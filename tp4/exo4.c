#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longueur(char *s);

int main()
{
    printf("%d\n", longueur("kayak"));
}

int longueur(char *s)
{
    char *i = s;
    while (*(i) && ++i)
        ;
    return (int)(i - s);
}