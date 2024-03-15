#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *create(struct Node *p, int val)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->val = val;
    new->next = NULL;
    p->next = new;
    return new;
}

void set(struct Node *p, int val)
{
    p->val = val;
}

void print(struct Node *head)
{
    struct Node *p = head;
    do
    {
        printf("%d ", p->val);
        p = p->next;
    }
    while (p->next != NULL);
    printf("%d", p->val);
}

void clear(struct Node *p)
{
    if (p->next != NULL)
    {
        clear(p->next);
    }
    free(p);
}

void insert(struct Node *head, int val)
{
    struct Node *p = head;
    while (p->next->val < val)
    {
        p = p->next;
    }
    struct Node *next = p->next;
    create(p, val)->next = next;
}

int main()
{
    int v;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &v);
    set(head, v);
    struct Node *now = head;
    while (scanf("%d", &v) && v != 0)
    {
        now = create(now, v);
    }

    int val;
    scanf("%d", &val);
    insert(head, val);

    print(head);
    
    clear(head);
    return 0;
}