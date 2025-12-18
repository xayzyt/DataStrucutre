#include<stdio.h>
#include<string.h>
//初始化顺序表
#define MAXSIZE 100	
typedef int ElemType; //假设顺序表存储的数据类型为整型

typedef struct
{
	ElemType data[MAXSIZE]; //存储顺序表元素的数组
	int length;             //顺序表当前长度
}SqList;

void InitList(SqList *L)
{
	L->length = 0; //初始化顺序表长度为0
}
//在顺序表尾部插入元素
int ListInsert(SqList *L, ElemType e)
{
	if (L->length >= MAXSIZE) //顺序表已满
	{
		return 0; //插入失败
	}
	L->data[L->length] = e; //将元素e插入到顺序表末尾
	L->length++; //顺序表长度加1
	return 1; //插入成功
}
//顺序表遍历
void ListTraverse(SqList *L)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]); //输出顺序表中的元素
	}
	printf("\n");
}
//顺序表在指定位置插入元素
int insertElem(SqList *L, int pos, ElemType e)
{
	int i;
	if (pos < 0 || pos > L->length || L->length >= MAXSIZE) //位置不合法或顺序表已满
	{
		return 0; //插入失败
	}
	for (i = L->length; i > pos; i--) //将pos位置及其后面的元素后移一位
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[pos] = e; //将元素e插入到pos位置
	L->length++; //顺序表长度加1
	return 1; //插入成功
}

//顺序表删除指定位置元素
int deleteElem(SqList *L, int pos)
{
	int i;
	if (pos < 0 || pos >= L->length) //位置不合法
	{
		return 0; //删除失败
	}
	for (i = pos; i < L->length - 1; i++) //将pos位置后面的元素前移一位
	{
		L->data[i] = L->data[i + 1];
	}
	L->length--; //顺序表长度减1
	return 1; //删除成功
}

//顺序表查找元素
int locateElem(SqList *L, ElemType e)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] == e) //找到元素e
		{
			return i; //返回元素e的位置
		}
	}
	return -1; //未找到元素e
}

//顺序表动态分配内存初始化
SqList* InitDynamicList()
{
	SqList *L = (SqList*)malloc(sizeof(SqList)); //动态分配内存
	if (!L)
	{
		return NULL; //分配失败
	}
	L->length = 0; //初始化顺序表长度为0
	return L; //返回顺序表指针
}

//定义图书结构体
struct book
{
	int isbn;
	char bookname[30];
	double price;
};

int main()
{
	//计算频度
	int n = 10000;
	char c[101][101];
	for (int i = 1; i <= n; i++)//频度为n+1
	{
		for (int j = 1; j <= n; j++)//频度为n*（n+1）
		{
			c[i][j] = 0;   //频度为 n*n
			for (int k = 1; k <= n; k++)//频度为n*n*（n+1）
			{
				c[i][j] = 0;   //频度为 n*n*n
			}
		}
	}
	//总频度为 n + n*(n+1) + n*n + n*n*(n+1) + n*n*n
	//f(n) = 2n^3 + 3n^2 + 2n + 1
	//时间复杂度为 O(n^3)取最高次项
	//简单来看，三重循环嵌套，时间复杂度为 O(n^3)，二重循环嵌套，时间复杂度为 O(n^2)，单循环，时间复杂度为 O(n)

	//x++; //频度为1，时间复杂度为 O(1)
	//for (i = 1; i <= 100000; i++) 
	//{
	//	x++;//频度为 n，时间复杂度为 O(1)
	// }

	/*
		时间复杂度为 O(n)
		for(int i = 0;i<n;i++)		n+1
		{
			x++;		n
			s = 0;		n
		}
	
	*/

	//线性表
	//线性表的定义：由n(n>=0)个数据特性相同的元素构成的有限序列
	//线性表的特性：1.线性表中的元素个数是有限的
	//				2.线性表中的每个元素都有唯一的前驱和后继
	//				3.线性表中第一个元素没有前驱，最后一个元素没有后继
	//				4.线性表中元素的存储位置不一定是连续的

	struct book b;
	b.isbn = 78564186;
	strcpy_s(b.bookname, sizeof(b.bookname), "C Programming");
	b.price = 59.8;

	//顺序表
	//顺序表的定义：用一段地址连续的存储单元依次存放线性表的各个元素
	//顺序表的优点：1.存取元素时，可以通过下标直接访问，时间复杂度为 O(1)
	//顺序表的缺点：1.插入和删除元素时，需要移动大量元素，时间复杂度为 O(n)

	//顺序表初始化
	SqList list;
	InitList(&list);
	//顺序表插入元素
	ListInsert(&list, 11);
	ListInsert(&list, 88);
	ListInsert(&list, 99);
	//顺序表遍历
	ListTraverse(&list);
	//在下标为2的位置插入元素77
	insertElem(&list, 2, 77);
	//顺序表遍历
	ListTraverse(&list);
	//删除下标为1的元素
	deleteElem(&list, 1);
	//顺序表遍历
	ListTraverse(&list);



	return 0;
}

