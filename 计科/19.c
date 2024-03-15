#include <stdio.h>

void printArr(int* arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void popSort(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - i -1 ; j++)
		{
			if (arr[j] < arr[j + 1]) swap(arr, j, j + 1);
		}
	}
}

void swap(int* arr, int a, int b)
{
	if (a == b) return;
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void del(int* arr, int* plen)
{
	int i, j;
	for (i = 0; i < *plen - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			for (j = i; j + 2 < *plen; j++)
			{
				arr[j] = arr[j + 2];
			}
			*plen = *plen - 2;
			i--;
		}
	}
}

int main()
{
	int n1, n2, i;
	int ans[40];
	int len;
	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
		scanf("%d", &ans[i]);
	scanf("%d", &n2);
	for (i = 0; i < n2; i++)
		scanf("%d", &ans[i+n1]);
	len = n1 + n2;
	
	popSort(ans, len);
	del(ans, &len);
	printArr(ans, len);
	return 0;
}
