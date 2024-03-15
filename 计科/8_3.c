#include <stdio.h>

void solve(char *a, int m, char *b)
{
    int i;
    char *c = a + m - 1;
    char *r = b;
    while (*c != '\0')
    {
        *r = *c;
        c++;
        r++;
    }
}

int main()
{
    char buf[100];
    gets(buf);
    int m;
    scanf("%d", &m);
    char rst[100];
    solve(buf, m, rst);
    printf("%s", rst);
    return 0;
}