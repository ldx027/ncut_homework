#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int getlen(char *buf)
{
    int i;
    for (i = 0; buf[i] != '\0'; i++);
    return i;
}

int main()
{
    char a[80], b[80];
    gets(a);
    gets(b);
    int lena = getlen(a); 
    int lenb = getlen(b); 
    int i;
    for (i = 0; i < min(5, lenb); i++)
    {
        a[i + lena] = b[i];
    }
    a[lena + i] = '\0';

    printf("%s", a);
    return 0;
}