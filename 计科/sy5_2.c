#include <stdio.h>

int H2D(char *num)
{
    int rst = 0, i;
    for (i = 0; num[i] != '\0'; i++)
    {
        rst *= 16;
        if (num[i] >= '0' && num[i] <= '9') rst += num[i] - '0';
        else rst += num[i] + 10 - 'a';
    }
    return rst;
}

int main()
{
    char x1[80], x2[80];
    int rst;
    scanf("%s", x1);
    scanf("%s", x2);
    rst = H2D(x1) + H2D(x2); 
    printf("%d\n",rst); 

    return 0;
}