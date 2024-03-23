#include <stdio.h>
#include <math.h>

int wq(int x)
{
	return pow((int)sqrt(x + 100), 2) == (x + 100) && pow((int)sqrt(x + 268), 2) == (x + 268);
}

int main()
{
	int m, n, i, have = 0;
	scanf("%d %d",&m, &n);
	for (i = m; i <= n; i++)
	{
		if (wq(i)) 
		{		
			printf("%d ", i);
			have = 1;
		}
	}
	
	if (!have) printf("no");
	return 0;
}
