#include <stdio.h>

int main()
{
    FILE *file = fopen("test.txt", "w");
    char c;
    while (c = getchar(), c != '!')
    {
        if (c >= 'a' && c <= 'z') c += 'A' - 'a';
        fprintf(file, "%c", c);
    }

    return 0;
}