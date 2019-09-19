#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delOccursW(char *w, char *T);

int main()
{
    char test[] = "totaly";
    delOccursW("t", test);
    printf("=> %s\n", test);
}

void delOccursW(char *w, char *T)
{
    const int lengthToRemove = strlen(w);
    while (*T)
    {
        char keepIt = *(T + lengthToRemove);
        *(T + lengthToRemove) = '\0';
        if (strcmp(T, w) == 0)
        {
            *(T + lengthToRemove) = keepIt;
            strcpy(T, T + lengthToRemove);
            break;
        }
        else
        {
            *(T + lengthToRemove) = keepIt;
            T++;
        }
    }
}