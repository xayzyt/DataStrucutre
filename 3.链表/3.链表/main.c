#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//链表
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}Node;
//链表初始化
Node* initList()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
//链表插入数据（头插法）
int insertHead(Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
//链表插入数据（尾插法）
Node * insertTail(Node* L, ElemType e)
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = NULL;
	p->next = s;
	return s;
}

//链表遍历
void traverseList(Node* L)
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
	//插入数据
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	//遍历链表
	traverseList(list);

	return 0;
}