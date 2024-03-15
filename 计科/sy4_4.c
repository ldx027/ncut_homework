#include <stdio.h>
#include <math.h>
#define Digit 250

void print(int*);

void init(int *num)
{
    int i;
    for (i = 0; i < Digit; i++)
    {
        num[i] = -1;
    }
}

void clear(char *buf)
{
    int i;
    for (i = 0; i < Digit; i++)
    {
        buf[i] = '\0';
    }
}

void change(char *buf, int *rst)
{
    int i, idx = 0;
    init(rst);

    for (i = Digit - 1; i >= 0; i--)
    {
        if (buf[i] >= '0' && buf[i] <= '9')
        {
            rst[idx++] = buf[i] - '0'; 
        }
    }
}

void carry(int *num)
{
    int i;
    for (i = 0; i + 1 < Digit && num[i] >= 0; i++)
    {
        if (num[i] > 9)
        {
            num[i + 1] = (num[i + 1] >= 0 ? num[i + 1] : 0) + num[i] / 10;
            num[i] %= 10;
        }
    }
}

void shift(int *a, int n, int *rst)
{
    int i;
    init(rst);
    for (i = 0; i + n < Digit; i++)
    {
        rst[i + n] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        rst[i] = 0;
    }
}

void mulDigit(int *a, int b, int *rst)
{
    init(rst);
    int i;
    for (i = 0; i < Digit && a[i] >= 0; i++)
    {
        rst[i] = a[i] * b;
    }
    carry(rst);
}

void sum(int *a, int *b, int *rst)
{
    init(rst);
    int i;
    for (i = 0; i < Digit && (a[i] >= 0 || b[i] >= 0); i++)
    {
        rst[i] = (a[i] >= 0 ? a[i] : 0)  + (b[i] >= 0 ? b[i] : 0);
    }
    carry(rst);
}

void copy(int *a, int *b)
{
    int i;
    for (i = 0; i < Digit; i++)
    {
        a[i] = b[i];
    }
}

void print(int *num)
{
    int i;
    for (i = 0; i < Digit && num[i] >= 0; i++)
    {
        printf("%d", num[i]);
    }
    printf("\n");
}

void show(int *num)
{
    int i;
    for (i = 0; i < Digit && num[i] >= 0; i++);
    for (i--; i >= 0; i--)
    {
        printf("%d", num[i]);
    }
    printf("\n");
}

void mul(int *a, int *b, int *rst)
{
    init(rst);
    int i;
    for (i = 0; i < Digit && b[i] >= 0; i++)
    {
        int mulNum[Digit];
        mulDigit(a, b[i], mulNum);
        int shiftNum[Digit];
        shift(mulNum, i, shiftNum);
        int sumNum[Digit];
        sum(rst, shiftNum, sumNum);
        copy(rst, sumNum);
    }
}

int main()
{
    char bufA[Digit], bufB[Digit];
    clear(bufA);
    clear(bufB);
    int a[Digit], b[Digit];
    init(a);
    init(b);
    gets(bufA);
    gets(bufB);
    change(bufA, a);
    change(bufB, b);

    int rst[Digit];
    init(rst);
    mul(a, b, rst);
    carry(rst);
    show(rst);
    
    return 0;
}