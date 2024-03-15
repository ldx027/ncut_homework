#include <stdio.h>
#include <math.h>

int isp(int x)
{
	int i;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int n;
	int have = 0;
	scanf("%d", &n);
	int i;
	for (i = 1;10 * i + 1<=n;i++)
	{
		if (isp(10 * i + 1))
		{
			printf("%d ", 10 * i + 1);
			have = 1;
		}
	}
	if (!have)
	{
		printf("-1");
	}
	return 0;
}
