#include <stdio.h>
#include <math.h>

int getDigit(int x)
{
	int digitN = 0;
	while (x > 0)
	{
		x = x / 10;
		digitN = digitN + 1;

	}
	return digitN;
}

int digit(int x, int n)
{
	return (x % (int)pow(10, n) / pow(10, n - 1));
}

void separateAgainst(int x, int digit)
{
	int i;
	for (i = 0; i < digit; i++)
	{
		printf("%d", x % 10);
		x /= 10;
	}
}

int main()
{
	int x = 0;
	scanf("%d", &x);
	int digitN = getDigit(x);
	printf("%d\n", digitN);
	
	int i;
	
	for (i = digitN; i > 0; i--)
		printf("%d ", digit(x, i));
	printf("\n");
	
	for (i = 1; i <= digitN; i++)
		printf("%d ", digit(x, i));
	
	return 0;
}
