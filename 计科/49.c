#include <stdio.h>

int func(int x, int sum)
{
	if (x == 1) return sum + 1;
	return func(x - 1, sum + x);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", func(n, 0));
}
