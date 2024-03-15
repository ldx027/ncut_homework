#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int isP(int x)
{
	if (x <= 1) return 0;
	int i;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}

int have(int x, int* arr, int len)
{
	int i;
	for (i = 0; i < len; i++) if (x == arr[i]) return 1;
	return 0;
}

void popSort(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		} 
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[20];
	int ans[100];
	int idx = 0;
	int i, j;
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 0; i < n; i++)
	{
		for (j = 2; j <= sqrt(arr[i]); j++)
		{
			//printf("%d ", j);
			if (isP(j) && (arr[i] % j == 0) && !have(j, ans, idx + 1))
			{
				ans[idx++] = j;
				//printf("[%d] ", j);
			}

		}
		if (isP(arr[i]) && !have(j, ans, idx + 1))
		{
			ans[idx++] = arr[i];
		}
	}

	popSort(ans, idx);
	for (i = 0; i < idx; i++) printf("%d ", ans[i]);

	return 0;
}