#include <stdio.h>
#include <string.h>

int isWord(char c)
{
    if (c == '_') return 1;
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;  
}

int isNum(char c)
{
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

void getWord(char* buf, char (*words)[11])
{
    int i, j;
    int idx = 0;
    for (i = 0; buf[i] != '\0'; i++)
    {
        if (isWord(buf[i]) && !isNum(buf[i]))
        {
            for (j = 0; isWord(buf[i + j]); j++)
            {
                words[idx][j] = buf[i + j];
            }
            i = i + j;
            words[idx++][j] = '\0';
        }
    }
}

void printBufArr(char (*words)[11])
{
    int i;
    for (i = 0; i < 20; i++) printf("%s ", words[i]);
    printf("\n");
}

void init(char (*words)[11])
{
    int i;
    for (i = 0; i < 20; i++) words[i][0] = '\0';
}

int haveItem(char (*words)[11], char *buf)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (strcmp(words[i], buf) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void same(char (*words1)[11], char (*words2)[11])
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (haveItem(words2, words1[i]))
        {
            printf("%s ", words1[i]);
        }
    }
}

int main()
{
    char input[100], output[100];
    gets(input);
    gets(output);
    
    char words1[20][11];
    char words2[20][11]; 
    
    init(words1);
    init(words2);

    getWord(input, words1);
    getWord(output, words2);



    same(words1, words2);
    return 0;
}