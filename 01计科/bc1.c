#include <stdio.h>
#include <math.h>

int digit(int x, int n)
{
    return x % (int)pow(10, n) / pow(10, n - 1);
}

int xg(int x)
{
    int i;
    if (x % 6 == 0) return 1;
    for (i = 1; i <= log10(x) + 1; i++)
    {
        if (digit(x, i) == 6) return 1;
    }
    return 0;
}

int main()
{
    int M, N, n = 0;
    scanf("%d%d", &M, &N);
    while (n < N)
    {
        M++;
        if (xg(M))
        {
            n++;
            printf("%-10d ", M);
        }
    }

    return 0;
}