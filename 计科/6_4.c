#include <stdio.h>
#include <stdlib.h>

int *arr;

int func1(int n, int m, int idx, int val)
{
    int i;
    for (i = m * idx; i < m * idx + m; i++)
    {
        if (arr[i] > val) return 0;
    }
    return 1;
}

int func2(int n, int m, int idx, int val)
{
    int i;
    for (i = idx; i < m * n; i += m)
    {
        if (arr[i] < val) return 0;
    }
    return 1;
}

int main()
{
    int n, m, i;
    int have = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    arr = (int *)malloc(sizeof(int) * m * n);
    for (i = 0; i < n * m; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < m * n; i++)
    {
        if (func1(n, m, i / m, arr[i]) && func2(n, m, i % m, arr[i]))
        {
            have = 1;
            printf("%d %d %d\n", i / m, i % m, arr[i]);
        }
    }
    if (!have)
    {
        printf("no");
    }

    return 0;
}