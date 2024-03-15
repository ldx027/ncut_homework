#include <stdio.h>
#include <stdlib.h>

typedef struct MON
{
    struct MON *prev, *next;
    int id;
} Mon;

Mon *create(Mon *base, int _id)
{
    Mon *new = (Mon*)malloc(sizeof(Mon));
    if (base != NULL) base->next = new;
    new->prev = base;
    new->next = NULL;
    new->id = _id;
    return new;
}

int solve(Mon *base, int m)
{
    Mon *now = base;
    int i = 0;;
    while (1)
    {
        if (now->next == now) return now->id;
        for (i = 0; i < m - 1; i++)
        {
            now = now->next;
        }
        now->prev->next = now->next;
        now->next->prev = now->prev;
        now = now->next;
    }
}

int main()
{
    int N, i, j;
    int n, m;
    Mon *base;
    Mon *now;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        base = create(NULL, 1);
        now = base;
        scanf("%d", &n);
        scanf("%d", &m);
        for (j = 0; j < n - 1; j++)
        {
            now = create(now, now->id + 1);
        }
        now->next = base;
        base->prev = now;
        int ans = solve(base, m);
        printf("%d\n", ans);
    }
    return 0;
}