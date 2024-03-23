#include <stdio.h>

typedef struct KEY
{
    char letter;
    int val;
} Key;

int main()
{
    int i, j, I;
    Key arr[26];

    int n;
    char buf[1000];
    scanf("%d", &n);
    for (I = 0; I < n; I++)
    {
        for (i = 0; i < 26; i++)
        {
            arr[i].letter = 'a' + i;
            arr[i].val = 0;
        }

        scanf("%s", buf);
        for (j = 0; buf[j] != '\0'; j++)
        {
            arr[buf[j] - 'a'].val++;
        }

        for (i = 0; i < 25; i++)
        {
            for (j = 0; j < 25 - i; j++)
            {
                if (arr[j].val < arr[j + 1].val || arr[j].val == arr[j + 1].val && arr[j].letter > arr[j + 1].letter)
                {
                    Key temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        printf("%c %d\n", arr[0].letter, arr[0].val);
    }

    return 0;
}