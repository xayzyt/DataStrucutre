#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//链表
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}Node;
//链表初始化
Node* initList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
// 链表遍历
void traverseList(Node * L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//链表插入数据（头插法）
int insertHead(Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
Node* get_tail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return &(p->data);
}
Node* insertTail(Node* L, ElemType e)
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
Node* initListWithElem()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
Node* insertTailWithNode(Node* tail, Node* node)
{
	tail->next = node;
	node->next = NULL;
	return node;
}
//双指针应用
//使用双指针找倒数第k个节点
int findNodeFS(Node* L, int k)
{
	Node* fast = L->next;
	Node* slow = L->next;
	for (int i = 0; i < k; i++)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	printf("The %dth node from the end is: %d\n", k, slow->data);
	//return 1;
}

//查找两个节点共同后缀的起始位置
Node * fineInitersectionNode(Node* headA, Node* headB)
{
	Node* pA = headA;
	Node* pB = headB;
	while (pA != pB)
	{
		pA = (pA == NULL) ? headB : pA->next;
		pB = (pB == NULL) ? headA : pB->next;
	}
	return pA;
}

int main()
{
	Node* list = initList();
//	insertHead(list, 10);
//	insertHead(list, 20);
//	insertHead(list, 30);
//	insertHead(list, 55);
//	insertHead(list, 80);
//	insertHead(list, 40);
//
//	findNodeFS(list, 5);
	Node* listA = initList();
	Node* listB = initList();
	Node* tailA = get_tail(listA);
	Node* tailB = get_tail(listB);
	tailA = insertTail(tailA, 'l');
	tailA = insertTail(tailA, 'o');
	tailA = insertTail(tailA, 'a');
	tailA = insertTail(tailA, 'd');
	tailB = insertTail(tailB, 'b');
	tailB = insertTail(tailB, 'e');

	Node* nodeI = initListWithElem('i');
	tailA = insertTailWithNode(tailA, nodeI);
	tailB = insertTailWithNode(tailB, nodeI);
	Node* nodeN = initListWithElem('n');
	tailA = insertTailWithNode(tailA, nodeI);
	tailB = insertTailWithNode(tailB, nodeI);
	Node* nodeG = initListWithElem('g');
	tailA = insertTailWithNode(tailA, nodeI);
	tailB = insertTailWithNode(tailB, nodeI);

	traverseList(listA);
	traverseList(listB);
	printf("The intersection node is: %c\n", fineInitersectionNode(listA, listB)->data);
	return 0;
}

