#include <stdio.h>
#include <math.h>

int digit(int x, int n)
{
	return (x % (int)pow(10, n) / pow(10, n-1));
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	char num[50];
	scanf("%s", &num);
	
	int i, j;
	int dot;
	int idxN = -1;
	int last;
	char ans[50];
	ans[49] = '\0';
	
	for (i = 0;;i++)
	{
		if (num[i] == '\0') break;
		if (num[i] == '.')
		{
			dot = i;
		}
		if (num[i] >= '1' && num[i] <= '9')
		{
			if (idxN == -1 )idxN = i;
			last = i;
		}
	}

	
	i = 0;
	ans[i++] = num[idxN];
	if (last - idxN > 0)
	{
		ans[i++] = '.';
	}
	for (j = idxN + 1; j <= last; j++)
	{
		if (num[j] == '.') j++;
		ans[i++] = num[j];
	}

	ans[i++] = 'e';
	if (idxN > dot)
	{
		ans[i++] = '-';
		int en = idxN - dot;
		for (j = 0; j < max(log10(en), 1); j++)
		{
			ans[i++] = digit(en, log10(en) + 1 - j) + '0';
		}
	}
	else
	{
		int en = dot - idxN - 1;
		if (en != 0)
			for (j = 0; j < max(log10(en) + 1, 1); j++)
			{
				ans[i++] = digit(en, log10(en) + 1 - j) + '0';
			}
		else
		{
			ans[i++] = '0';
		}
	}
	ans[i] = '\0';
	
	printf("%s", ans);
	
	return 0;
}
