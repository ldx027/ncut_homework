#include <stdio.h>

#define N 3

struct student
{
    int id;
    char name[10];
    int mathS;
    int engS;
    int csS;
    int total;
};

int main()
{
    struct student arr[N];
    int i, j; 
    double avgM = 0, avgE = 0, avgC = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i].id);
        scanf("%s", &arr[i].name);
        scanf("%d", &arr[i].mathS);
        avgM += arr[i].mathS / 3.0;
        scanf("%d", &arr[i].engS);
        avgE += arr[i].engS / 3.0;
        scanf("%d", &arr[i].csS);
        avgC += arr[i].csS / 3.0;
        arr[i].total = arr[i].csS + arr[i].mathS + arr[i].engS;
    }

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1 - i; j++)
        {
            if (arr[j].total < arr[j + 1].total)
            {
                struct student s = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = s;
            }
        }
    }
    printf("NO   Name   Maths   English   Computer   Total\n");
    for (i = 0; i < N; i++)
    {
        printf("%d    %s    %d    %d    %d    %d\n", arr[i].id, arr[i].name, arr[i].mathS, arr[i].engS, arr[i].csS, arr[i].total);
    }
    printf("average of Maths:%.2f\n", avgM);
    printf("average of English:%.2f\n", avgE);
    printf("average of Computer:%.2f\n", avgC);

    return 0;
}