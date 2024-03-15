#include <stdio.h>
#include <math.h>

int isP(int x)
{
    int i;
    for (i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return 0;
    return 1;
}

int main()
{
    int x;
    scanf("%d", &x);
    if (x <= 1) printf("error");
    else printf(isP(x) ? "YES" : "NO");

    return 0;
}