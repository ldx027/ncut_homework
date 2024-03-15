#include <stdio.h>
#include <math.h>

double pi(int n)
{
	int i;
	double ans = 2.0;
	for (i = 1; i <= n; i++)
	{
		ans = ans * 4.0 * pow(i, 2) / (2 * i + 1) / (2 * i - 1);
	}
	return ans;
}

double abs_f(double a)
{
	return a > 0 ? a : -a;
}

int main()
{	
	double e;
	double last = 0.0, now;
	int i = 1;
	
	scanf("%lf", &e);
	
	now = pi(1);
	while (abs_f(e - last) > abs_f(e - now))
	{
		last = now;
		now = pi(++i);
	}
	
	printf("%.9f %d", last, --i);
	
	return 0;
}
