#include <stdio.h>

int main()
{
    int num[3];
    int *arr[3];
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    int i, j;
    for (i = 0; i < 3; i++) arr[i] = &num[i];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2 - i; j++)
        {
            if (*arr[j] > *arr[j + 1])
            {
                int *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < 3; i++) printf("%d ", *arr[i]);

    return 0;
}