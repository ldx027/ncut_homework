#include <stdio.h>
#include <stdlib.h>

typedef struct CARRIAGE
{
    struct CARRIAGE *prev;
    int id;
    struct CARRIAGE *next;
} Carriage;

Carriage *create(Carriage *base, int _id)
{
    Carriage *new = (Carriage*)malloc(sizeof(Carriage));
    if (base != NULL) base->next = new;
    new->prev = base;
    new->id = _id;
    new->next = NULL;
    return new; 
}

void show(Carriage *base)
{
    Carriage *now = base;
    int n = 0;
    while (now->next != NULL)
    {
        n++;
        printf("%d ", now->id);
        now = now->next;
    }
    printf("%d\n", now->id);
    printf("%d\n", ++n);
    while (now != NULL)
    {
        printf("%d ", now->id);
        now = now->prev;
    }
}

int main()
{
    int id;
    scanf("%d", &id);
    Carriage *base = create(NULL, id);
    Carriage *now = base;
    while (scanf("%d", &id), id != 0)
    {
        now = create(now, id);
    }
    show(base);

    return 0;
}