#include <stdio.h>

int func(int N)
{
    if (N <= 0) return 0;
    if (N <= 2) return N;
    return func(N - 1) + func(N - 2);
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d", func(N));

    return 0;
}