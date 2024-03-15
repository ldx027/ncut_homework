#include <stdio.h>
#include <math.h>


int main()
{
	int n;
	scanf("%d", &n);
	
	int i;
	float total = 100;
	
	for (i = 0; i < n - 1; i++)
	{
		total = total + 100 / pow(2, i);
	}
	
	printf("%.2f %.2f", total, 100 / pow(2, n));
	
	return 0;
}
