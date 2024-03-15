#include <stdio.h>

void popSort_a(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) swap(arr, i, j);
		}
	}
}

void popSort(int* arr, int len)
{
 	int i, j, temp;
    for (i = 0; i < len - 1; i++)
    	for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) 
			{
            	temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void del(int* arr, int* len)
{
	int i, j;
	for (i = 0; i < *len - 1; i++)
	{
		if (arr[i] == arr[i+1])
		{
			for (j = i + 1; j < *len - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			*len = *len - 1;
			i--;
		}
	}
}

void swap(int* arr, int a, int b)
{
	if (a == b)	return;
	arr[a] = arr[a] ^ arr[b];
	arr[b] = arr[a] ^ arr[b];
	arr[a] = arr[a] ^ arr[b];
}

void printArr(int* arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int n1, n2;
	int arr[40];
	scanf("%d %d", &n1, &n2);
	int len = n1 + n2;
	int i;
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	popSort(arr, len);
	del(arr, &len);
	printArr(arr, len);
	
	return 0;
}
