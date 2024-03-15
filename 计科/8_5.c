#include <stdio.h>

int greater(char *a, char *b)
{
    while (*a != '\0' && *b != '\0')
    {
        if (*a > *b) return 1;
        if (*a < *b) return 0;
        a++; b++;
    }

    if (*a == '\0') return 0;
    return 1;
}

void swap(char *a, char *b)
{
    int i;
    char temp[10];
    for (i = 0; i < 10; i++)
    {
        temp[i] = a[i];
        a[i] = b[i];
        b[i] = temp[i];
    }
}

int main()
{
    char buf[10][10];
    int i, j, n;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        gets(buf[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (greater(buf[j], buf[j + 1]))
            {
                swap(buf[j], buf[j + 1]);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n", buf[i]);
    }
    return 0;
}