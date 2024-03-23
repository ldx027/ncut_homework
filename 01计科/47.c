#include <stdio.h>

struct Node
{
	struct Node *pre;
	struct Node *next;
	int id;
	int score;
} NODE;

struct Node* addNode(struct Node *preNode ,int _id, int _score)
{
	struct Node *node = malloc(sizeof(NODE));
	node->id = _id;
	node->score = _score;
	node->pre = preNode;
	node->next = NULL;
	preNode->next = node;
	
	return node;
}

void delNode(struct Node *node)
{
	node->pre->next = node->next;
	free(node);
}

void delNodeById(struct Node *baseNode, int id)
{
	struct Node *now;
	now = baseNode;
	while (now != NULL)
	{
		if (now->id == id)
		{
			struct Node *temp = now->next;
			delNode(now);
			now = temp;
		}
		else
		{
			now = now->next;
		}
		
	}
}

void showNodeList(struct Node *baseNode)
{
	struct Node *now = baseNode->next;
	while (now != NULL)
	{
		printf("%d %d\n", now->id, now->score);
		now = now->next;
	}
}

int main()
{
	struct Node *baseNode = malloc(sizeof(NODE));
	struct Node *now = baseNode;
	int id = 0;
	int score;
	while (1)
	{
		scanf("%d", &id);
		if (id == -1)
		{
			scanf("%d", &id);
			break;
		}
		scanf("%d", &score);
		now = addNode(now, id, score);
	}
	
	int ids[100];
	int idx = 0;
	id = 0;
	while (1)
	{
		scanf("%d", &id);
		if (id == -1)
			break;
		
		ids[idx++] = id;
		getchar();
	}
	ids[idx] = -1;
	
	int i;
	for (i = 0; ids[i] != -1; i++)
	{
		delNodeById(baseNode, ids[i]);
	}
	
	showNodeList(baseNode);
	
	free(baseNode);
	return 0;
}
