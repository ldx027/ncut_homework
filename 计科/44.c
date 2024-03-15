#include <stdio.h>

struct Node
{
	struct Node *pre;
	int value;
	struct Node *next;
} NODE;

struct Node * addNode(struct Node *preNode, int value)
{
	struct Node *node = malloc(sizeof(NODE));
	preNode->next = node;
	node->pre = preNode;
	node->value = value;
	node->next = NULL;
	
	return node;
}

void showNodeList(struct Node *baseNode)
{
	struct Node *now = baseNode->next;
	while (now != NULL)
	{
		printf("%d ", now->value);
		now = now->next;
	}
}

void showNodeListRev(struct Node* now)
{
	while (now->pre != NULL)
	{
		printf("%d ", now->value);
		now = now->pre;	
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int i, value;
	
	struct Node *baseNode = malloc(sizeof(NODE));
	baseNode->pre = NULL;
	struct Node *now = baseNode;
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &value);
		now = addNode(now, value);
	}
	showNodeListRev(now);
	
	return 0;
}
