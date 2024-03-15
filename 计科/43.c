#include <stdio.h>

void func(char* buf, int* arr)
{
	int i, j, idx = 0;
	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			int num = 0;
			for (j = i; buf[j] >= '0' && buf[j] <= '9'; j++)
			{
				num = num * 10 + buf[j] - '0';
			}
			arr[idx++] = num;
			i = j;
		}
	}
	arr[101] = idx;
}

void printArr(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	char buf[101];
	gets(buf);
	
	int arr[101];
	func(buf, arr);
	
	int len = arr[101];
	printf("%d ", len);
	printArr(arr, len);
}
