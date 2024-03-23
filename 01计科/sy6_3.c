#include <stdio.h>
#include <stdlib.h>

int stringcmp(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    char **arr= (char**)malloc(sizeof(char*) * 2 * n);
    int i;
    for (i = 0; i < 2 * n; i++)
    {
        arr[i] = (char*)malloc(sizeof(char) * 30);
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", stringcmp(arr[2 * i], arr[2 * i + 1]));
    }
    return 0;
}