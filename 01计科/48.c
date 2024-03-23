#include <stdio.h>

int getLen(char* buf)
{
    int i;
    for (i = 0; buf[i] != '\0'; i++);
    return i;
}

int main()
{
	FILE *in, *out;
    in = fopen("text1.dat", "r");
    out = fopen("text2.dat", "w");
	char buf[81];
    int i;
    int len;
	while (fgets(buf, 80, in) != NULL)
	{
        len = getLen(buf);
		for(i = 0; i < len; i++)
		{
			fprintf(out, "%c", buf[len-i-1]);
		}
		fprintf(out, "\n");
	}
	return 0;
}