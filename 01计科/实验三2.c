#include <stdio.h>

double fb(double *fbArr, int n)
{
    if (n < 1 ) return 1;
    if (fbArr[n] != 0) return fbArr[n];
    fbArr[n] = (fb(fbArr, n - 1) + fb(fbArr, n - 2));


    return fbArr[n];
}

int main()
{
    int i, n;
    double ans = 0;
    double fbArr[201];
    for (i = 0; i < 201; i++) fbArr[i] = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) ans = ans + fb(fbArr, i + 1) / fb(fbArr, i);
    printf("%.2lf", ans);

    return 0;
}