#include <stdio.h>
#include <stdlib.h>

typedef struct PLAYER
{
    char id[20];
    int score[4];
    int sum;
} Player;

int getMin(Player *ply)
{
    int i;
    int min = ply->score[0];
    for (i = 1; i < 4; i++)
    {
        min = ply->score[i] > min ? min : ply->score[i];
    }
    return min;
}

void popSort(Player *arr, int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j].sum < arr[j + 1].sum || (arr[j].sum == arr[j + 1].sum && getMin(arr + j) < getMin(arr + j + 1)))
            {
                Player temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void show(Player *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%-10s%-6d\n", arr[i].id, arr[i].sum);
    }
}

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    Player *arr = (Player*)malloc(sizeof(Player) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i].id);
        int sum = 0;
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &arr[i].score[j]);
            sum += arr[i].score[j];
            arr[i].sum = sum - getMin(&arr[i]);
        }
    }
    popSort(arr, n);
    show(arr, n);

    return 0;
}