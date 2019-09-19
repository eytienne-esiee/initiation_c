#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindTab(char *s);
int palindPtr(char *s);

int main()
{
    char *word1 = "kayak";
    char *word2 = "kabbak";
    char *word3 = "kaytk";
    printf("%s => %d\n", word1, palindPtr(word1));
    printf("%s => %d\n", word2, palindPtr(word2));
    printf("%s => %d\n", word3, palindPtr(word3));
}

int palindPtr(char *s)
{
    char *beg = s - 1;
    char *end = s;
    while (*(end) && ++end)
        ;
    end;

    while (beg < end && *(++beg) == *(--end))
        ;
    return beg < end
               ? 0
               : 1;
}

int palindTab(char *s)
{
    int beg = -1;
    int end = strlen(s);

    while (beg < end && s[++beg] == s[--end])
        ;
    return beg < end ? 0 : 1;
}
