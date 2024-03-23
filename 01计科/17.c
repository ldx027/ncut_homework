#include <stdio.h>

int havezc(char* a, char* b)
{
	int i, j;
	int len = getLen(b);
	
	for  (i = 0; a[i] != '\0'; i++)
	{
		int ans = i;
		for (j = 0; j < len && a[i + j] != '\0'; j++)
		{
			if (a[i + j] != b[j]) ans = -1;
		}
		if (ans != -1) return ans;
	}
	return -1;
	
}

int getLen(char* s)
{
	int i;
	int len = 0;
	for (i = 0; s[i] != '\0'; i++)
		len++;
	return len;
}

void del(char*s ,int n, int len)
{
	int i;
	for (i = n; s[i + len] != '\0'; i++)
	{
		s[i] = s[i + len];
	}
	s[i] = '\0';
}

int main()
{
	char a[100];
	char b[100];
	gets(a);
	gets(b);
	
	int zc = havezc(a, b); 
	if (zc != -1)
	{
		while(havezc(a, b) != -1)
		{
			zc = havezc(a, b);
			del(a, zc, getLen(b));
		}
		
		printf("%s", &a);
	}
	else
	{
		printf("%s", &b);
	}
	
	return 0;
	
}
