#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    error codes :
    -1 : invalid option
    -2 : mandatory option forgotten
    -3 : no filename
*/
int main(int argc, char const *argv[])
{
    char lineNumber = -1;
    char *fileName = (char *)malloc(FILENAME_MAX * sizeof(char));
    printf("filename length : %ld\n", strlen(fileName));
    char *argument = (char *)malloc(1000 * sizeof(char));
    for (int i = 1; i < argc; ++i)
    {
        sprintf(argument, "%s", argv[i]);
        if (argument[0] == '-')
        {
            size_t taille = strlen(argument);
            if (lineNumber == -1)
                if (taille == 2)
                    lineNumber = argument[1] == 'L' ? 1 : (argument[1] == 'C' ? 0 : -1);
                else
                    exit - 1;
        }
        else
        {
            strcpy(fileName, argument);
        }
        if (lineNumber != -1 && strlen(fileName) > 0)
            break;
    }
    free(argument);
    if (lineNumber != -1)
        exit - 2;
    if (strlen(fileName) == 0)
        exit - 3;

    printf("lineNumber = %d ; filename = '%s'\n", lineNumber, fileName);
    FILE *fp = fopen(fileName, "r");
    int returnedNumber = lineNumber ? 1 : 0;
    if (fp)
    {
        char c;
        while ((c = fgetc(fp)) != EOF)
            if (!lineNumber)
                ++returnedNumber;
            else if (c == '\n')
                ++returnedNumber;
    }
    printf("Result : %d\n", returnedNumber);
    return 0;
}