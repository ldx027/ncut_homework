#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct money
{
	char name[10];
	int score1;
	int score2;
	char ch1;
	char ch2;
	int number;
	int money;
};
int main()
{
	int N, i;
	scanf("%d", &N);
	while (N < 1 || N>100)
	{
		scanf("%d", &N);
	}
	struct money* p =(struct money *) malloc(N * sizeof(struct money));
	for (i = 0; i < N; i++)
	{
		scanf("%s", p[i].name);
		scanf("%d%d", &p[i].score1, &p[i].score2);
		scanf("%c%c", &p[i].ch1, &p[i].ch2);
		scanf("%d",&p[i].number);
		p[i].money = 0;
	}
	int sum = 0;
	for (i = 0; i < N; i++)
	{
		if (p[i].score1 > 80 && p[i].number >= 1)
		{
			p[i].money += 8000;
		}
		if (p[i].score1 > 85 && p[i].score2 > 80)
		{
			p[i].money += 4000;
		}
		if (p[i].score1 > 90)
		{
			p[i].money += 2000;
		}
		if (p[i].score1 > 85 && p[i].ch2 == 'Y')
		{
			p[i].money += 1000;
		}
		if (p[i].score1 > 80 && p[i].ch1 == 'Y')
		{
			p[i].money += 850;
		}
		sum += p[i].money;
	}
	int j, money1 = 0;
	for (i = 0; i < N; i++)
	{
		if (p[i].money > money1)
		{
			j = i;
			money1 = p[i].money;
		}
	}
	printf("%s\n%d\n%d", p[j].name, p[j].money, sum);
	return 0;
}