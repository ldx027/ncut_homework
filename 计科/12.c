#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int a, b;
	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			if ((10 * a + b) * (10 * b + a) == N)
			{
				printf("A=%d,B=%d", a, b);
				return 0;
			}
		}
	 }
	 
	 printf("No Answer");
	
	return 0;
}
