#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	char buf[20][80] = {{'\0'}};
	getchar();
	int i, j;
	int ans[5] = { 0 };
	for (i = 0; i < n; i++)
	{
		gets(buf[i]);
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0;;j++)
		{
			char c = buf[i][j];
			if (c == '\0') break;
			else if (c >= 'A' && c <= 'Z') ans[0]++;
			else if (c >= 'a' && c <= 'z') ans[1]++;
			else if (c >= '0' && c <= '9')
			{
				ans[2]++;
			 } 
			else if (c == ' ') ans[3]++;
			else ans[4]++;
		}
	}
	
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ans[i]);
	}
		
	return 0;
}
