#include <stdio.h>

void caculate(int m[] , int n , int x , int *num , float *aver);

int main()
{ 
    int m[80],i=0,n,x,number;
    float av;
    while(1) 
    {
        scanf("%d",&m[i]);
        if(m[i]==-999) break;
        i++;
    }
    n=i;                           //输入数据的个数
    scanf("%d",&x);                 //输入正整数x
    caculate(m , n , x , &number , &av);
    printf("%-10.2f%-5d\n",av,number);
    return(0);
}

void caculate(int *m , int n , int x , int *num , float *aver)
{
    int i;
    *num = 0;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += m[i];
        if (m[i] < x)
        {
            *num += 1;
        }
    }
    *aver = (double)sum / n;
}