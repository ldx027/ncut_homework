#include <stdio.h>

double jc(double x)
{
    if (x <= 1) return 1;
    return x * jc(x - 1);
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%.0lf", jc(x));

    return 0;
}