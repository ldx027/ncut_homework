#include <stdio.h>
#include <stdlib.h>

typedef struct MOUSE
{
    char id[6];
    char color[10];
    int weight;
} Mouse;

void popSort(Mouse *arr, int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (arr[j].weight < arr[j + 1].weight)
            {
                Mouse temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void show(Mouse *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%s %s\n", arr[i].id, arr[i].color);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    Mouse *arr = (Mouse*)malloc(sizeof(Mouse) * N);
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%s%d%s", arr[i].id, &arr[i].weight, arr[i].color);
    }
    popSort(arr, N);
    show(arr, N);

    return 0;
}