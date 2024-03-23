#include <stdio.h>
#include <stdlib.h>

typedef struct STU
{
    char id[6];
    char name[11];
    int score[3];
    double avg;
} Stu;

void stuInput(Stu *stu)
{
    scanf("%s", stu->id);
    scanf("%s", stu->name);
    int i;
    for (i = 0; i < 3; i++) scanf("%d", &stu->score[i]);
    stu->avg = (stu->score[0] + stu->score[1] + stu->score[2]) / 3.0;
}

double stuAvg(Stu *arr, int n)
{
    int sum = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum += arr[i].score[j];
        }
    }
    return sum / 3.0 / n;
}

void print(Stu *arr, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    printf("%5s%10s%5d%5d%5d%8.2f\n", arr[i].id, arr[i].name, arr[i].score[0], arr[i].score[1], arr[i].score[2], arr[i].avg);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    Stu *arr = (Stu*)malloc(sizeof(Stu) * n);
    for (i = 0; i < n; i++)
    {
        stuInput(&arr[i]);
    }
    double avg = stuAvg(arr, n);
    printf("%.2f\n", avg);
    print(arr, n);

    return 0;
}