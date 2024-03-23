#include <stdio.h>
#include <math.h>

double cos_m(double x, int n)
{
	double ans = 1;
	
	int i;
	for (i = 1; i <= n; i++)
	{
		ans = ans + pow(-1, i) * pow(x, 2 * i) / jc(2 * i);
		printf("%d %f\n", i, ans);
	}
	
	return ans;
}

int jc(int a)
{
	int ans = 1;
	for (;a>1;a--)
		ans = ans * a;
	return ans;
}

int main()
{
	double x;
	int n;
	scanf("%lf %d", &x, &n);
	printf("%.8f", cos_m(x, n));
	
	return 0;
}
