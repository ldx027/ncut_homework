#include <stdio.h>
#include <math.h>

int digit(int x, int n)
{
    return x % (int)pow(10, n) / pow(10, n - 1);
}

int numberDick(int x)
{
    if (x < 10) return x;
    int len = log10(x) + 1, sum = 0, i;
    for (i = 0; i < len; i++) sum += digit(x, i + 1);
    return numberDick(sum);
}

int main()
{
    int x;
    scanf("%d", &x);
    while (x)
    {
        printf("%d\n", numberDick(x));
        scanf("%d", &x);
    }

    return 0;
}