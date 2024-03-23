#include <stdio.h>
#include <math.h>

void func1(int a, int b, int c, double d)
{
    if (a != 0) printf("%.2f %.2f", (sqrt(d) - b) / 2 / a, (-sqrt(d) - b) / 2 / a); 
    else printf("%.2f", -c / (double)b);
}

void func2(int a, int b, int c)
{
    if (a != 0) printf("%.2f", -b/2.0/a);
    else printf("%.2f", -c / (double)b);
}

void func3(int a, int b, int c, double d)
{
    if (a != 0)
    {
        printf("%.2f%+.2fi ", -b/2.0/a, sqrt(-d)/2/a);
        printf("%.2f%+.2fi", -b/2.0/a, -sqrt(-d)/2/a);
    }
    else printf("%.2f", -c / (double)b);
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double d = pow(b, 2) - 4 * a * c;

    if (d > 0) func1(a, b, c, d);
    else if (d == 0) func2(a, b, c);
    else if (d < 0) func3(a, b, c, d);

    return 0;
}
