#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *prior;
	struct Node * next;
}Node;
//初始化链表
Node* initList()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	L->prior = NULL;
	return L;

}

//头插法
int insertHead(Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	p->prior = L;
	if (L->next != NULL)
	{
		L->next->prior = p;
	}
	L->next = p;
	return 1;

}
//尾插法
Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prior = tail;
	tail->next = p;
	p->next = NULL;
	return p;
}
//删除节点
int deleteNode(Node* L, ElemType e)
{
	Node* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return 0; //未找到
	}
	p->prior->next = p->next;
	if (p->next != NULL)
	{
		p->next->prior = p->prior;
	}
	free(p);
	return 1;
}

//遍历
void traverse(Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Node* list = initList();
//	insertHead(list,10);
//	insertHead(list, 20);
//	insertHead(list, 30);
	insertTail(list, 10);
	insertTail(list, 20);
	insertTail(list, 30);
	traverse(list);

	return 0;
}
