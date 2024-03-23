#include <stdio.h>

void str_bin(char s1[], char s2[], char s[])
{
	int i, p1 = 0, p2 = 0;
	for (i = 0; s1[p1] != '\0' && s2[p2] != '\0'; i++)
	{
		s[i] = s1[p1] < s2[p2] ? s1[p1++] : s2[p2++];
	}
	while (s1[p1] != '\0')
	{
		s[i++] = s1[p1++];
	}
		
	while (s2[p2] != '\0')
	{
		s[i++] = s2[p2++];
	}
	s[i++] = '\0';
		
}

int main()
{
	char s1[100] = { '\0' }, s2[100] = { '\0' }, s[200];
	scanf("%s %s", &s1, &s2);
	str_bin(s1, s2, s);
	printf("%s", s);
	return 0;
}
