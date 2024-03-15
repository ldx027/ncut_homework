#include <stdio.h>

int zys(int x)
{
    int rst = 0;
    int i;
    for (i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            rst += i;
        }
    }
    return rst;
}

int main()
{
    int N;
    scanf("%d", &N);
    int i;
    int a, b;
    for (i = 0; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        printf(zys(a) == b && zys(b) == a ? "YES\n" : "NO\n");
    }
    return 0;
}