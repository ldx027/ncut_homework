#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int add(int a, int b)
{
    if (a == 0) return b;
    return (a && b, a || b);
}

void count(int *score, int n, int* max, int* min, float* ave)
{
	int i;
	float sum = 0;
	*max = score[0];
	*min = score[0];
	for (i = 0; i < n; i++)
	{
		*max = *max > score[i] ? *max : score[i];
		*min = *min < score[i] ? *min : score[i];
		sum += score[i];
	}
	*ave = sum / n;
}

int main()
{
	int N, i, max, min;
	float ave;
	scanf("%d", &N);
	int score[30];
	for (i = 0; i < N; i++)
	{
		scanf("%d", &score[i]);
	}
	count(score, N, &max, &min, &ave);
	printf("%d %d %.2f", max, min, ave);

	return 0;
}