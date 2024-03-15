#include <stdio.h>
#include <math.h>

int change(char *h)
{
    int i, rst = 0, digit = 0;;
    for (i = 0; h[i] != '\0'; i++);
    for (i--; i >= 0; i--)
        if (h[i] >= '0' && h[i] <= '9') rst += (h[i] - '0') * pow(16, digit++);
        else if(h[i] >= 'a' && h[i] <= 'z') rst += pow(16, digit++) * (10 + h[i] - 'a');
        else if(h[i] >= 'A' && h[i] <= 'Z') rst += pow(16, digit++) * (10 + h[i] - 'A');
    return rst; 
}

int main()
{  
    char x[100]; 
    scanf("%s", x);
    printf("%d", change(x));
    
    return 0;
}