#include <stdio.h>
#include <math.h>

void move(char* buf, int dot, int x)
{
	int i;
	if (x >= 0)
	{
		for (i = 0; i < x; i++)
		{
			if (buf[i + dot + 1] == '\0')
			{
				buf[i + dot + 1] = '0';
				buf[i + dot + 2] = '\0';
			}
			swap(buf, i + dot, i + dot + 1);
		}
	}
	else
	{
		x = -x;
		for (i = 0; i < x; i++)
		{
			if (i + dot - 1 < 0)
			{
				int j;
				int last = 0;;
				for (j = 0; buf[j] != '\0'; j++)
				{
					last++;
				}
				for (j = last; j > 0; j--)
				{
					buf[j] = buf[j - 1];
				}
				buf[0] = '0';
			}
			swap(buf, i + dot, i + dot - 1);
		}
	}
}


int getE(char* buf, int e)
{
	int i;
	int len = 0;
	for (i = e + 1;buf[i] != '\0';i++)
	{
		if (buf[i] == '-') continue;
		len++;
	}
		
	int ans = 0;
	for (i = 0; i < len; i++)
	{
		if (buf[i + e + 1] == '-') continue;
		ans = ans + pow(10, len - i - 1) * (buf[i + e + 1] - '0');
	}
	return ans;
}

void swap(char* arr, int a, int b)
{
	if (a == b) return;
	char temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int main()
{
	char num[200];
	scanf("%s", &num);
	
	int dot;
	int e;
	int efh = 0;
	
	int i;
	for (i = 0;;i++)
	{
		if (num[i] == '\0') break;
		if (num[i] == '-')
		{
			efh = 1;
		}
		if (num[i] == 'e')
		{
			e = i;
			num[i] = '\0';
		}
		if (num[i] == '.')
		{
			dot = i;
		}
		
	}
	
	move(num, dot, pow(-1, efh) * getE(num, e));
	
	for (i = 0; num[i] != '\0';i++)
	{
		if (num[i] == '.' && num[i + 1] == '\0')
		{
			num[i] = '\0';
		}
	}
	
	printf("%s", num);
	
	
	
	return 0;
}
