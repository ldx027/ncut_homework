#include <stdio.h>
#include <math.h>

int H2D(char *num, int H)
{
    int i, rst = 0;
    for (i = 0; num[i] != '\0'; i++)
    {
        rst *= H;
        if (num[i] >= 'a' && num[i] <= 'z') rst += num[i] + 10 - 'a';
        else if (num[i] >= '0' && num[i] <= '9') rst += num[i] - '0';
        else if (num[i] >= 'A' && num[i] <= 'Z') rst += num[i] - 'A' + 10;
    }
    return rst;
}

void D2H(int num, int H, char *rst)
{
    int i, j;
    for (i = 0; i < 40; i++) rst[i] = '\0'; 
    for (i = 0; pow(H, i) <= num; i++);
    for (i--, j = 0; i > 0; j++)
    {
        rst[j] = num / (int)pow(H, i) + '0';
        num %= (int)pow(H, i--);
        if (rst[j] > '9') rst[j] += 'A' - '0' - 10;
    }
    rst[j++] = num > 9 ? (num + 'A') : (num + '0');
    rst[j] = '\0';
}

int main()
{
    int h1, h2;
    char num[40], rst[40];
    scanf("%d %s %d", &h1, num, &h2);
    int D = H2D(num, h1);
    D2H(D, h2, rst);
    printf("%s\n", rst);

    return 0;
}