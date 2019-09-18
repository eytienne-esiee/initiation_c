#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

typedef struct s_Node
{
    int value;
    struct s_Node *next;
} Node;

void afficher(Node n)
{
    Node *ptr = &n;
    while (ptr != NULL)
    {
        printf("value : %d\n", ptr->value);
        ptr = ptr->next;
    }
}

int main()
{
    Node myFirst;
    Node mySecond;
    Node myThird;
    myFirst.value = 1;
    myFirst.next = &mySecond;
    mySecond.value = 3;
    mySecond.next = &myThird;
    myThird.value = 5;
    myThird.next = NULL;

    afficher(myFirst);
}