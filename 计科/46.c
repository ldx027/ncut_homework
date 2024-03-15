#include <stdio.h>

typedef struct
{
	int rank;
	int id;
	char name[20];
	int sMath;
	int sEng;
	int sCH;	
	double score;
} Student;

void avg(Student *stu)
{
	stu->score = (stu->sMath + stu->sEng + stu->sCH) / 3.0;
}

void rank(Student *stu, int len)
{
	int idx = 1;
	int i;
	for (i = 0; i < len; i++)
	{
		if (i > 0 && stu[i].score == stu[i - 1].score)
		{
			stu[i].rank = stu[i - 1].rank;
		}
		else
		{
			stu[i].rank = i + 1;
		}
	}
}

void popSort(Student *stus, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (stus[j].score < stus[j + 1].score || (stus[j].score == stus[j + 1].score && stus[j].id > stus[j + 1].id))
				swap_stu(stus, j, j+1);
		}
	}
}

void swap_stu(Student *stus, int a, int b)
{
	Student temp = stus[a];
	stus[a] = stus[b];
	stus[b] = temp;
}

void printStu(Student s)
{
	printf("%4d%10d%10s%5d%5d%5d", s.rank, s.id, s.name, s.sMath, s.sEng, s.sCH);
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n < 1 || n > 9)
	{
		printf("Please input 1-9.");
		return 0;
	}
	int i;
	Student stu[10];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &stu[i].id);
		scanf("%s", &stu[i].name);
		scanf("%d", &stu[i].sMath);
		scanf("%d", &stu[i].sEng);
		scanf("%d", &stu[i].sCH);
		avg(&stu[i]);
	}
	
	int idx;
	popSort(stu, n);
	rank(stu, n);
	for (idx = 0; idx < n ; idx++)
	{
		printStu(stu[idx]);
		printf("\n");
	}
	
	
	return 0;
}
