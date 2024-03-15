#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *mat = (int *) malloc(sizeof(int) * n * n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[n * i + j]);
        }
    }
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += mat[i * n + i];
    }
    printf("%d", sum);

    return 0;
}