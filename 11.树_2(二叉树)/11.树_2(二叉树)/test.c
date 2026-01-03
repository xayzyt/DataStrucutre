#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//二叉树存储结构

//链式存储
typedef char ElemType;
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;
typedef TreeNode* BiTree;

//前序遍历
void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}
//中序遍历
void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	inOrder(T->lchild);
	printf("%c ", T->data);
	inOrder(T->rchild);
}
//后序遍历
void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c ", T->data);
}

char str[] = "ABDH#K###E##CFI###G#J##";
int index = 0;
//造树
void createTree(BiTree* T)
{
	ElemType ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
}

int main()
{
	//树的性质
	//1.树中所有结点数等于所有结点的度数之和加1
	//2.对于度为m的树，第i层上至多有m^(i-1)个结点
	//3.对于度为m的树，高为h的树至多有(m^h-1)/(m-1)个结点

	//二叉树：每个结点的度最大为2，其子树分为左子树和右子树
	//性质一：二叉树的第i层最多有2^(i-1)个结点
	//性质二：深度为h的二叉树最多有2^h-1个结点
	//性质三：对于非空的二叉树T，如果叶子结点的个数为n0，度为2的结点个数为n2，则n0=n2+1

	//满二叉树：除最后一层外，每一层的结点数都达到最大值，并且最后一层的结点都连续集中在最左边
	//完全二叉树：没有左子树，不能有右子树，上一层没有铺满，不能有下一层
	//满二叉树一定是完全二叉树，完全二叉树不一定是满二叉树
	//完全二叉树有偶数个结点说明有一个度为1的结点，有奇数个结点说明没有度为1的结点

	BiTree root = NULL;
	createTree(&root);

	printf("前序遍历: ");
	preOrder(root);
	printf("\n");

	printf("中序遍历: ");
	inOrder(root);
	printf("\n");

	printf("后序遍历: ");
	postOrder(root);
	printf("\n");



	return 0;
}