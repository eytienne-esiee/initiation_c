int main()
{
    int i = 2;
    int *ptr;
    ptr = &i;
    *ptr = 3;
    printf(" entrez valeur de i :");
    scanf("% d", i);
    printf(" entrez valeur de ptr :");
    scanf("% d", ptr);
    return 0;
}