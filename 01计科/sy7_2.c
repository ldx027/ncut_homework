#include <stdio.h>
#include <stdlib.h>

typedef struct BOOK
{
    char name[31];
    char cbs[16];
    int number;
    double price;
    struct BOOK *next;
} Book;

Book *create(Book *base)
{
    Book *new = (Book*)malloc(sizeof(Book));
    Book *now = base;
    scanf("%s%s%d%lf", new->name, new->cbs, &new->number, &new->price);
    if (base == NULL || new->price < base->price)
    {
        new->next = base;
        return new;
    }

    while (now->next != NULL)
    {
        if (now->next->price > new->price)
        {
            new->next = now->next;
            now->next = new;
            return base;
        }
        now = now->next;
    }
    new->next = NULL;
    now->next = new;
    return base;
}

void show(Book *base)
{
    double sum = 0;
    Book *now = base;
    while (now != NULL)
    {
        sum += now->price * now->number;
        printf("%-30s%-20s%-10d%-.2f\n", now->name, now->cbs, now->number, now->price);
        now = now->next;
    }
    printf("%.2f", sum);
}

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    Book *base = NULL;
    for (i = 0; i < n; i++)
    {
        base = create(base);
    }
    show(base);

    return 0;
}