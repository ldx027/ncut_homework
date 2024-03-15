#include <stdio.h>
#include <stdlib.h>

typedef struct STUDENT 
{
    char id[20];
    int score[5];
} Stu;

double func1(Stu *arr, int len)
{
    double sum = 0;
    int i;
    for (i = 0 ; i < len; i++)
    {
        sum += arr[i].score[0];
    }
    return sum / len;
}

 void func2(Stu *arr, int len)
 {
    int i, j;
    for (i = 0; i < len; i++)
    {
        int loss = 0;
        for (j = 0; j < 5; j++)
        {
            if (arr[i].score[j] < 60) loss++;
            if (loss >= 2)
            {
                printf("%s ", arr[i].id);
                break;
            }
        }
    }
    printf("\n");
 }

 void func3(Stu *arr, int len)
 {
    int i, j;
    int have = 0;
    for (i = 0; i < len; i++)
    {
        int total = 0;
        for (j = 0; j < 5; j++) total += arr[i].score[j];
        if (total >= 450) 
        {
            have = 1;
            printf("%s ", arr[i].id);
        }
    }
    if (!have) printf("no");
    printf("\n");
 }

 int main()
 {
    int n;
    scanf("%d", &n);
    Stu *arr = (Stu*)malloc(sizeof(Stu) * n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i].id);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &arr[i].score[j]);
        }
    }
    printf("%.2f\n", func1(arr, n));
    func2(arr, n);
    func3(arr, n);

    return 0;
 }