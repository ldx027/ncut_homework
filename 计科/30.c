#include <stdio.h>

int func(char* buf)
{
	int ans;
	int maxLen = 0;
	int len = 0;
	int i, j;
	for (i = 0; buf[i] != '\0';i++)
	{
		len = 0;
		for (j = i;(buf[j] >= 'a' && buf[j] <= 'z') || (buf[j] >= 'A' && buf[j] <= 'Z'); j++)
		{
			len++;
		}
		if (len > maxLen)
		{
			ans = i;
			maxLen = len;
		}
		i = j;
	}
	
	return ans;
}

void printWord(char* buf, int idx)
{
	int j;
	for (j = idx; (buf[j] >= 'a' && buf[j] <= 'z') || (buf[j] >= 'A' && buf[j] <= 'Z') ; j++)
	{
		printf("%c", buf[j]);
	}
}

int main()
{
	char buf[80];
	gets(buf);
	printWord(buf, func(buf));
	return 0;
}
