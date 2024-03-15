#include <stdio.h>
#include <stdlib.h>

typedef struct NODE 
{
    int val;
    struct NODE *next;
} Node;

Node *push(Node *node, int val)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    node->next = new;
    return new;
}

void show(Node *base)
{
    Node *now = base;
    while(now->next != NULL)
    {
        printf("%d ", now->val);
        now = now->next;
    }
    printf("%d\n", now->val);
}

Node *solve(Node *base, int m, int n)
{
    int i;
    m = (m + n) % n;
    Node *now = base;
    while (now->next != NULL)
    {
        now = now->next;
    }
    now->next = base;
    now = base;

    for (i = 0; i < n - m - 1; i++)
    {
        now = now->next;
    }
    Node *newBase = now->next;
    now->next = NULL;

    return newBase;
}

int main()
{
    int n, m, val;
    scanf("%d %d", &n, &m);
    Node  * const baseNode = (Node*)malloc(sizeof(Node));
    Node *now = baseNode;

    scanf("%d", &val);
    baseNode->val = val;

    int i;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &val);
        now = push(now, val);
    }
    Node * newBase = solve(baseNode, m, n);
    show(newBase);

    return 0;
}