#include <stdio.h>
#include <math.h>

int getMax(int* arr , int len)
{
	int i;
	int idx = 0;
	for (i = 0 ; i < len ; i++)
	{
		idx = arr[idx] > arr[i] ? idx : i;
	}
	return arr[idx];
}

int isp(int x)
{
	int i;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
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

int solve(int* arr, int len, int* ans)
{
	int max = getMax(arr, len);
	int i, j, idx = 0, have;
	for (i = 2;; i++)
	{
		if (isp(i))
		{
			have = 0;
			for (j = 0; j < len; j++)
			{
				while (arr[j] % i == 0)
				{
					arr[j] = arr[j] / i;
					if (!have)
					{
						ans[idx++] = i;
						have = 1;
					}
				}
			}
		}
		max = getMax(arr, len);
		if (i > max) break;
	}
	return idx--;
}

int main()
{
	int n;
	int arr[20];
	int ans[50];
	
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int len = solve(arr, n, ans);
	
	printArr(ans, len);
	
	return 0;
}
