#include <stdio.h>

int main()
{
	int arr1[3][3];
	int arr2[3][3];
	int x, y;
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			scanf("%d", &arr1[x][y]);
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			printf("%d ", arr1[y][x]);
		}
		printf("\n");
	}
	return 0;
}
