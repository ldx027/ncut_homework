#include <stdio.h>
#include <math.h>

int digit(int x, int n) { return x % (int)pow(10, n) / pow(10, n - 1); }

int main()
{
    int n, ans = 0, i,j, is;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        if (i % 7 != 0)
        {
            is = 1;
            for (j = 0; j <= log10(i) + 1; j++)
                if (digit(i, j) == 7)
                    is = 0;
            if (is) ans = ans + pow(i, 2);
        }
                    
    printf("%d", ans);

    return 0;
}