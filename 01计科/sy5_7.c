#include<stdio.h>
#include<string.h>

#define Digit 81

int strcm(char *str1,char *str2);
void strlw(char *str);

int main()
{

	char S1[Digit],S2[Digit];
	scanf("%s",S1);
	scanf("%s",S2);
	strlw(S1);
	strlw(S2);
	switch (strcm(S1, S2))
	{
		case 0: printf("="); break;
		case 1: printf(">"); break;
		case -1: printf("<"); break;
	}

	return 0;
}

void strlw(char *str)
{
	int i;
	for(i=0;i<Digit && str[i] != '\0';i++)
		if(str[i]>='A' && str[i]<='Z')
			str[i]=str[i]+'a'-'A';
}

int strcm(char *str1,char *str2)
{
	int i;
	for(i=0;i<Digit && (str1[i] != '\0' || str2[i] != '\0');i++)
		if(str1[i]>str2[i])
			return 1;
		else if(str1[i]<str2[i])
			return -1;
	return 0;
}