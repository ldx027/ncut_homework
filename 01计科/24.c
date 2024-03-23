#include <stdio.h>

int isy(int x)
{
	int yes[] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};
	int i;
	for (i = 0; i < sizeof(yes) / sizeof(yes[0]); i++)
	{
		if (yes[i] == x) return 1;
	}
	return 0;
}

int main()
{
	char buf[100];
	char ans[100];
	scanf("%[^\n]",buf);
	
	int i;
	int j = 0;
	for (i = 0;buf[i] != '\0';i++)
	{
		if (isy(buf[i]))
			ans[j++] = buf[i];	
	}
	ans[j] = '\0';
	printf("%s", ans);
	
	return 0;
}
