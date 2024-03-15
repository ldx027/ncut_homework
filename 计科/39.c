#include <stdio.h>

int main()
{
	char* month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int n;
	scanf("%d", &n);
	if (n > 12 || n < 1)
	{
		printf("error");
		return 0;
	}
	printf("%s", month[n - 1]);
	return 0;
}
