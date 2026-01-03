#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//线索二叉树
typedef char ElemType;
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode *lchild;
	struct ThreadNode *rchild;
	int ltag;//0表示指向孩子，1表示指向前驱
	int rtag;//0表示指向孩子，1表示指向后继
}ThreadNode;
typedef ThreadNode* ThreadTree;
//头节点的Lchild指向根节点，Rchild指向中序遍历的最后一个节点
//第一个结点的Lchild指向头节点，最后一个结点的Rchild指向头节点
// 创建线索二叉树
char str[] = "ABDH##I##E##CF##G##";
int idx = 0;

void createTree(ThreadTree* T)
{
	ElemType ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		createTree(&((*T)->lchild));
		if ((*T)->lchild != NULL)
		{
			(*T)->ltag = 0;
		}
		createTree(&((*T)->rchild));
		if ((*T)->rchild != NULL)
		{
			(*T)->rtag = 0;
		}

	}
}
ThreadTree prev;
//具体线索化
void threading(ThreadTree T)
{
	if (T != NULL)
	{
		threading(T->lchild);
		// 前驱线索化
		if (T->lchild == NULL)
		{
			T->lchild = prev;
			T->ltag = 1;
		}
		// 后继线索化
		if (prev != NULL && prev->rchild == NULL) // 修复：增加 prev 非空判断
		{
			prev->rchild = T;
			prev->rtag = 1;
		}
		prev = T;
		threading(T->rchild);
	}
}
//中序遍历线索化
void inOrderThreading(ThreadTree *head,ThreadTree T)
{
	//头节点
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	if (*head == NULL) // 修复：检查分配是否成功
	{
		fprintf(stderr, "内存分配失败！\n");
		exit(EXIT_FAILURE);
	}
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->rchild = *head;
	if (T == NULL)
	{
		(*head)->lchild = *head;
	}
	else
	{
		(*head)->lchild = T;
		prev = *head;
		threading(T);
		prev->rchild = *head;
		prev->rtag = 1;
		(*head)->rchild = prev;
	}
}
//使用线索进行中序遍历
void inOreder(ThreadTree T)
{
	ThreadTree curr;
	curr = T->lchild;//指向根节点
	while (curr != T)
	{
		//找到最左下角的节点
		while (curr->ltag == 0)
		{
			curr = curr->lchild;
		}
		printf("%c ", curr->data);
		//如果右指针是后继线索，直接访问后继节点
		while (curr->rtag == 1 && curr->rchild != T)
		{
			curr = curr->rchild;
			printf("%c ", curr->data);
		}
		//如果右指针是孩子，转向右子树
		curr = curr->rchild;
	}
}

int main()
{
	ThreadTree head, T;
	createTree(&T);
	inOrderThreading(&head, T);
	inOreder(head);
	
	
	return 0;
}
