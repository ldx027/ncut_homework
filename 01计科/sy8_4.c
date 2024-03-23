#include <stdio.h>

int isR(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


void date(int days)
{
    static int Mons[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static char Weeks[7][10] = {"Monday", "TuesDay", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int year = 2000;
    int mon = 1;
    int day = 1;
    int week = 5;

    week += days;
    week %= 7;
    while (days >= (isR(year) ? 366 : 365))
    {
        year++;
        days -= (isR(year) ? 366 : 365);
    }
    Mons[1] = isR(year) ? 29 : 28;    

    while  (days >= Mons[mon - 1])
    {
        days -= Mons[mon++ - 1];
    }

    day += days;
    printf("%4d-%02d-%02d %s\n", year, mon, day, Weeks[week]);
}

int main()
{
    int days;
    scanf("%d", &days);
    while (days != -1)
    {
        date(days);
        scanf("%d", &days);
    }

    return 0;
}