#include <stdio.h>

void popSort(int *arr, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j+1);
			}
		}
	}
}

void nodup(int* arr, int *len)
{
	int i, j;
	int sameLen = 0;
	for (i = 0; i < *len - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			sameLen = 0;
			for (j = i; arr[i] == arr[j] && j < *len; j++)
			{
				sameLen++;
			}
		
			for (j = i + 1; j + sameLen - 1 < *len; j++)
			{
				arr[j] = arr[j + sameLen - 1];
			}
			
			*len = *len - sameLen + 1;
			i--;
		}
	}
}

void swap(int *arr, int a, int b)
{
	if (a == b) return;
	arr[a] = arr[a] ^ arr[b];
	arr[b] = arr[a] ^ arr[b];
	arr[a] = arr[a] ^ arr[b];
}

void printArr(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int same(int *arr1, int len1, int *arr2, int len2)
{
	int i;
	if (len1 != len2) return 0;
	for (i = 0; i < len1; i++)
		if (arr1[i] != arr2[i]) return 0;
	return 1;
}

int main()
{
	int len1, len2;
	int arr1[20], arr2[20];
	int i;
	
	scanf("%d", &len1);
	for (i = 0; i < len1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &len2);
	for (i = 0; i < len2; i++)
	{
		scanf("%d", &arr2[i]);
	}
	
	popSort(arr1, len1);
	popSort(arr2, len2);
	
	nodup(arr1, &len1);
	nodup(arr2, &len2);

	printf("%d\n", same(arr1, len1, arr2, len2));
	printArr(arr1, len1);

	return 0;
}
