#include <stdio.h>
#include <stdlib.h>

typedef struct STU
{
    char id[12];
    int score[5];
    struct STU *next;
} Stu;

Stu *create(Stu *base)
{
    Stu *new = (Stu*)malloc(sizeof(Stu));
    if (base != NULL)
    {
        base->next = new;
    }
    scanf("%s", new->id);
    int i;
    for (i = 0; i < 5; i++) scanf("%d", &new->score[i]);

    return new;
}

void func1(Stu *base)
{
    int sum = 0;
    int n = 0;
    Stu *now = base;
    while (now != NULL)
    {
        n++;
        sum += now->score[0];
        now = now->next;
    } 
    printf("%.2f\n", (double)sum / n);
}

void func2(Stu *base)
{
    int have = 0;
    Stu *now = base;
    int n, i;
    while (now != NULL)
    {
        n = 0;
        for (i = 0; i < 5; i++)
        {
            if (now->score[i] < 60) n++;
        }
        if (n >= 2)
        {
            printf("%s ", now->id);
            have = 1;
        }
        now = now->next;
    }
    if (!have)
    {
        printf("no");
    }
    printf("\n");
}

void func3(Stu *base)
{
    int sum, i, have = 0;
    Stu *now = base;
    while (now != NULL)
    {
        sum = 0;
        for (i = 0; i < 5; i++)
        {
            sum += now->score[i];
        }
        if (sum >= 450)
        {
            printf("%s ", now->id);
            have = 1;
        }
        now = now->next;
    }
    if (!have)
    {
        printf("no");
    }
}

int main()
{
    int N;
    int i;
    scanf("%d", &N);
    
    Stu *base = create(NULL);
    Stu *now = base;
    for (i = 0; i < N - 1; i++)
    {
        now = create(now);
    }
    now->next = NULL;

    func1(base);
    func2(base);
    func3(base);

    return 0;
}