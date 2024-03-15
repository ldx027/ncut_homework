#include <stdio.h>
#include <math.h>

int digit(int x, int n)
{
	return (x % (int)pow(10, n) / pow(10, n-1));
}

int main()
{
	int i, j;
	for (i = 100; i < 1000; i++)
	{
		int ans = 0;
		for (j = 1; j <= 3; j++)
		{
			ans = ans + pow(digit(i, j), 3);
		}
		if (ans == i)
		{
			printf("%d ", ans);
		}
	}
	
	return 0;
}
