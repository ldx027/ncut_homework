#include <stdio.h>

int gcd(int a, int b)
{
    while (b^=a^=b^=a%=b);
    return a;
}

int func2(int a, int b)
{
    return a * b / gcd(a, b); 
}

void swap(int *a, int *b)
{
    if (a >= b) return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    swap(&a, &b);
    swap(&c, &d);
    printf("%d\n", gcd(a, b) + gcd(c, d));
    printf("%d", func2(c, d) + func2(a, b));
    return 0;
}