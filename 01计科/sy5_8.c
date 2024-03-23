#include <stdio.h>

int days(int m, int d)
{
    static int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, rst = 0;
    for (i = 0; i < m - 1; i++) rst += month[i];
    return rst + d;
}

int main()
{
    int i, w;
    scanf("%d", &w);
    w--;
    for (i = 1; i < 13; i++)
    {
        if ((days(i, 13) + w - 1) % 7 == 4) printf("%d\n", i);
    }

    return 0;
}