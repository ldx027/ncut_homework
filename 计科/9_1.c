#include <stdio.h>

typedef struct DATE
{
    int year, month, day;
} Date;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

 int days(Date date)
 {
    int i, rst = 0;

    if (date.year % 4 == 0 && date.year % 100 != 0) month[1] = 29;
    for (i = 0; i < date.month - 1; i++)
    {
        rst += month[i];
    }
    return rst + date.day;
 }

int main()
{
    Date date;
    scanf("%d", &date.year);
    scanf("%d", &date.month);
    scanf("%d", &date.day);
    printf("%d", days(date));

    return 0;
}