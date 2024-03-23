#include <stdio.h>

int find(char *a, char *b, int begin)
{
    int i, j, is;
    for (i = begin; a[i] != '\0'; i++)
    {
        if (a[i] == b[0])
        {
            is = 1;
            for (j = 0; a[i + j] != '\0' && b[j] != '\0'; j++)
            {
                if (a[i + j] != b[j]) is = 0;
            }
            if (a[i + j] == '\0' && b[j] != '\0') is = 0;
            if (is) return i;
        }
    }
    return -1;
}

int len(char *buf)
{
    int i;
    for (i = 0; buf[i] != '\0'; i++);
    return i;
}

int *change(char *buf, int idx, char *new, int bias)
{
    int i, j;
    char rst[100];
    for (i = 0; i < idx; i++)
    {
        rst[i] = buf[i];
    }
    for (j = 0; new[j] != '\0'; j++)
    {
        rst[i++] = new[j];
    }
    for (;buf[i + bias] != '\0'; i++)
    {
        rst[i] = buf[i + bias];
    }
    rst[i] = '\0';
    for (i = 0;rst[i] != '\0';i++)
    {
        buf[i] = rst[i];
    }
    buf[i] = '\0';
    return idx + strlen(new);
}

int main()
{
    char buf[100];    
    gets(buf);
    char s1[20], s2[20];
    scanf("%s %s", s1, s2);
    int idx, begin = 0;
    while (s1[0] != '0' || s2[0] != '0')
    {
        idx = find(buf, s1, 0);
        while (idx >= 0)
        {
            begin = change(buf, idx, s2, len(s1) - len(s2));
            idx = find(buf, s1, begin);
        }
        scanf("%s %s", s1, s2);
    }
    printf("%s", buf);
    return 0;
}