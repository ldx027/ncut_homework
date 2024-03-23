#include <stdio.h>
#define N 5

int main()
{
    char id[10];
    char name[10];
    int score[3];
    double avg;

    int i;
    FILE *file = fopen("stud.dat", "w");
    for (i = 0; i < N; i++)
    {
        scanf("%s%s%d%d%d", id, name, &score[0], &score[1], &score[2]);
        avg = (score[0] + score[1] + score[2]) / 3.0;

        fprintf(file, "%s %s %d %d %d %.2f\n", id, name, score[0], score[1], score[2], avg);
    }
    fclose(file);

    file = fopen("stud.dat", "r");
    char c;
    while (c = fgetc(file), c != EOF)
    {
        printf("%c", c);
    }
    fclose(file);

    return 0;
}