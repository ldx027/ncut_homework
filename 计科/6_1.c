#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int*) malloc(sizeof(int) * n + 1);
    int i, j;
    for (i = 0; i < n; i++) arr[i] = i;
    for (i = 2; i < n; i++)
    {  
        if (arr[i] != -1)
        {
            for (j = 2; j * i < n + 1; j++)
            {
                arr[j * i] = -1;
                // printf("%d %d\n", j , i);
            }
        } 
    }
    for (i = 2; i < n + 1; i++)
    {
        if (arr[i] != -1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}