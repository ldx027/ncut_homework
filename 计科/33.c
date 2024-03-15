#include <stdio.h>

int ls(int x)
{
	int i;
	int ans = 0;
	for (i = 1; i <= x / 2; i++)
		if (x % i == 0)
			ans = ans + i;
	return ans;
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int i;
	int have = 0;
	for (i = m; i <= n; i++)
	{
		if (ls(ls(i)) == i &&  i < ls(i) && ls(i) <= n)
		{
			printf("%d %d\n", i, ls(i));
			have = 1;
		}
	}
	if (!have)
	{
		printf("NONE");
	}
	
	return 0;
}
