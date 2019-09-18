#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copie(char *T, char *S);

int main()
{
    char *myS = "totoEtTata";
    char *myT;
    copie(myT, myS);
}

void copie(char *T, char *S)
{
    printf("target : %p ; source : %p\n", T, S);
    int i = 0;
    while (T[i] = S[i++])
        ;
    printf("target : %p ; source : %p\n", T, S);
}
