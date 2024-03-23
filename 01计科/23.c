#include <stdio.h>

int main()
{
	
	int m, n;
	scanf("%d %d", &m, &n);
	
	int i;
	int have = 0;
	for (i = m; i <= n; i++)
	{
		int ys = 0;
		int j;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				ys = ys + j;
			}
		}
		if (ys == i)
		{
			printf("%d ", i);
			have = 1;
		}
	}
	
	if (!have)
	{
		printf("No Answer");
	}
	
	return 0;
}
