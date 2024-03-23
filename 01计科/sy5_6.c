#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    char id[20];
    int m, d;
} Stu;

int main()
{
    int n, i, j;
    scanf("%d", &n);
    Stu *arr = (Stu*)malloc(sizeof(Stu) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d", &arr[i].id, &arr[i].m, &arr[i].d);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].m > arr[j + 1].m || arr[j].m == arr[j + 1].m && arr[j].d > arr[j + 1].d)
            {
                Stu temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (i + 1 < n && arr[i].m == arr[i + 1].m && arr[i].d == arr[i + 1].d)
        {
            printf("%d %d ", arr[i].m, arr[i].d);
            for (j = i; j < n && arr[j].m == arr[i].m && arr[j].d == arr[i].d; j++)
                printf("%s ", arr[j].id);
            printf("\n");
            i = j - 1;
        } 
        else 
        {
            printf("%d %d %s\n", arr[i].m, arr[i].d, arr[i].id);
        }
    }

    return 0;
}