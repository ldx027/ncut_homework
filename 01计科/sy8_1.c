#include <stdio.h>
#include <stdlib.h>

int stringCmp(char *a, char *b)
{
    int i;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++)
    {
        if (a[i] != b[i]) return 0;
    }
    return a[i] == b[i];
}

typedef struct STUDENT
{
    char id[10];
    char name[10];
    int score[3];
} Stu;

typedef struct DATA
{
    int N;
    Stu **students;
} Data;

Stu *createStu()
{
    Stu *stu = (Stu*)malloc(sizeof(Stu));
    scanf("%s%s%d%d%d", stu->id, stu->name, &stu->score[0], &stu->score[1], &stu->score[2]);
    return stu;
}

void showStu(Stu *stu)
{
    printf("%s %s %d %d %d\n", stu->id, stu->name, stu->score[0], stu->score[1], stu->score[2]);
}

Data *createData(int N)
{
    Data *data = (Data*)malloc(sizeof(Data));
    data->N = N;
    data->students = (Stu**)malloc(sizeof(Stu*) * N);
    int i;
    for (i = 0; i < N; i++)
    {
        data->students[i] = createStu();
    }

    return data;
}

Stu *findInDataById(Data *data, char *id)
{
    int i;
    for (i = 0; i < data->N; i++)
    {
        if (stringCmp(id, data->students[i]->id)) return data->students[i];
    }
    return NULL;
}

Stu *findInDataByName(Data *data, char *name)
{
    int i;
    for (i = 0; i < data->N; i++)
    {
        if (stringCmp(name, data->students[i]->name)) return data->students[i];
    }
    return NULL;
}

void showFailStu(Data *data, int idx)
{
    int i, have = 0;
    for (i = 0; i < data->N; i++)
    {
        if (data->students[i]->score[idx] < 60) 
        {
            printf("%s %d ", data->students[i]->id, data->students[i]->score[idx]);
            have = 1;
        }
    }
    if (!have) printf("no\n");
    else printf("\n");
}

void showAvg(Data *data)
{
    int sum = 0, total = 0;
    int i, j;
    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int j = 0; j < data->N; j++)
        {
            sum += data->students[j]->score[i];
        }
        printf("%.2f ", sum / 3.0);
        total += sum;
    }
    printf("%.2f\n", total / 3.0 / data->N);
}

int main()
{
    int N;
    scanf("%d", &N);
    Data *data = createData(N);

    char id[10];
    scanf("%s", id);
    showStu(findInDataById(data, id));

    char name[10];
    scanf("%s", name);
    Stu *stu = findInDataByName(data, name);
    scanf("%s%s%d%d%d", stu->id, stu->name, &stu->score[0], &stu->score[1], &stu->score[2]);
    showStu(stu);

    int idx;
    scanf("%d", &idx);
    showFailStu(data, idx - 1);

    showAvg(data);

    return 0;
}