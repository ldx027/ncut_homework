#include <stdio.h>
#include <math.h>

const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int during(int m1, int d1, int m2, int d2)
{
    int i, a1 = 0, a2 = 0;
    for (i = 0; i < m1 - 1; i++)
        a1 = a1 + month[i];
    a1 = a1 + d1;

    for (i = 0; i < m2 - 1; i++)
        a2 = a2 + month[i];
    a2 = a2 + d2;

    return a2 - a1;
}

int main()
{
    int m1, d1, m2, d2;
    long num; 
    scanf("%d %d %ld %d %d", &m1, &d1, &num, &m2, &d2);
    // printf("%d %d %d %d %d", m1, d1, m2, d2, num);
    printf("%d", num * (int)pow(2, during(m1, d1, m2, d2)));
    return 0;
}