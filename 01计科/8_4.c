#include <stdio.h>

int main()
{
    char buf[200];
    gets(buf);
    int rst[5] = { 0 };
    int i;
    for (i = 0; i < 5; i++) rst[i] = 0;
    char *c = buf;
    while (*c != '\0')
    {
        if (*c >= 'A' && *c <= 'Z') rst[0]++;
        else if (*c >= 'a' && *c <= 'z') rst[1]++;
        else if (*c == ' ') rst[2]++;
        else if (*c >= '0' && *c <= '9') rst[3]++;
        else rst[4]++;
        c++;
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d ", rst[i]);
    }

    return 0;
}