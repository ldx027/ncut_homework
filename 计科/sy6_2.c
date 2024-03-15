#include <stdio.h>
#include <stdlib.h>

int compare(char *a, char *b);
void popSort(char **arr, int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1- i; j++)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int compare(char *a, char *b)
{
    int i;
    for (i = 0; a[i + 1] != '\0' && b[i + 1] != '\0'; i++)
    {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return 0;
    }
}

int main()
{
    int len, i;
    scanf("%d", &len);
    char **arr = (char**)malloc(sizeof(char*) * len);
    for (i = 0; i < len; i++)
    {
        arr[i] = (char*)malloc(sizeof(char) * 21);
    }

    for (i = 0; i < len; i++)
    {
        scanf("%s", arr[i]);
    }    
    popSort(arr, len);
    for (i = 0; i < len; i++)
    {
        printf("%s\n", arr[i]);
    }
    return 0;
}