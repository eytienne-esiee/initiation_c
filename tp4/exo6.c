#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delOccursC(char x, char *T);

int main()
{
    char test[] = "kayak";
    printf("'%s' ", test);
    delOccursC('a', test);
    printf("=> '%s'\n", test);
}

void delOccursC(char x, char *T)
{
    while (*T)
        if (*T == x)
            strcpy(T, (char *)(T + 1));
        else
            ++T;
}
