#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copieTab(char *T, char *S);
void copiePtr(char *T, char *S);

int main()
{
    char *myS = "hello world !";
    char myT[100];
    copiePtr(myT, myS);
    printf("%s\n", myT);
}

void copiePtr(char *T, char *S)
{
    while (*(T++) = *(S++))
        ;
}

void copieTab(char *T, char *S)
{
    int i = 0;
    while (T[i] = S[i++])
        ;
}
