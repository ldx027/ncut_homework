#include <stdio.h>

void func(char *buf)
{
    int i;
    int n[4] = { 0 };
    for (i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] >= 'a' && buf[i] <= 'z') n[0]++;
        else if (buf[i] >= 'A' && buf[i] <= 'Z') n[0]++;
        else if (buf[i] >= '0' && buf[i] <= '9') n[1]++;
        else if (buf[i] == ' ') n[2]++;
        else n[3]++;
    }

    for (i = 0; i < 4; i++) printf("%d ", n[i]);
}

int main()
{
    char buf[31];
    gets(buf);
    func(buf);

    return 0;
}