#include <stdio.h>
#include <stdlib.h>

int main()
{
    int (*arr)[5] = (int*)calloc(sizeof(int), 5);
    int i;
    for (i = 0; i < 5; i++) printf("%p", arr[i]);
}