#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
        exit - 1;
    char *filename = (char *)malloc(FILENAME_MAX * sizeof(char));
    strcpy(filename, argv[1]);

    int table[__SCHAR_MAX__] = {0};
    
    FILE *fp = fopen(filename, "r");
    if (fp)
    {
        char c;
        while ((c = fgetc(fp)) != EOF)
            table[c]++;
    }
    for (char i = 0; i < __SCHAR_MAX__; i++)
        if (table[i] > 0)
            printf("%d fois la lettre '%c'\n", table[i], i);
    return 0;
}
