#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef int ElemType;
//队列的顺序结构
typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;
//初始化队列
void InitQueue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

//判断队列是否为空
int isQueueEmpty(Queue* q)
{
	if (q->front == q->rear)
	{
		printf("队列为空\n");
		return 1;
	}
	else
	{
		printf("队列不为空\n");
		return 0;
	}
}
//出队
ElemType dequeue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		return 0;
	}
	ElemType e = Q->data[Q->front];
	Q->front++;
	return e;
}

//获取对头数据
int getHead(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("队列为空，无法获取队头元素\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}

//队尾满了调整队列
int queueFull(Queue* Q)
{
	if (Q->front > 0)
	{
		int step = Q->front;
		for (int i = Q->front; i <= Q->rear; ++i)
		{
			Q->data[i - step] = Q->data[i];
		}
		Q->front = 0;
		Q->rear = Q->rear - step;
		return 1;
	}
	else
	{
		return 0;
	}
}
//入队
int equeue(Queue* Q, ElemType e)
{
	if (Q->rear >= MAXSIZE)
	{
		if (!queueFull(Q))
		{
		printf("队列满，无法入队\n");
		return 0;
		}

	}
	Q->data[Q->rear] = e;
	Q->rear++;
	return 1;
}
//栈的顺序结构
typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}Stack;

//初始化栈
void InitStack(Stack *s)
{
	s->top = -1;
}
//判断栈是否为空
int isEmpty(Stack* s)
{
	if (s->top == -1)
	{
		printf("栈为空\n");
		return 1;

	}
	else
		{
		printf("栈不为空\n");
		return 0;
	}
}
//入栈
int push(Stack* s, ElemType e)
{
	if (s->top == MAXSIZE - 1)
	{
		printf("栈满，无法入栈\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//出栈
ElemType pop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("栈空，无法出栈\n");
		return 0;
	}
	*e = s->data[s->top];//将栈顶元素赋值给e
	s->top--;//栈顶指针减1
	return 1;
}

//获取栈顶元素
ElemType getTop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("栈空，无法获取栈顶元素\n");
		return 0;
	}
	*e = s->data[s->top];//将栈顶元素赋值给e
	return 1;
}

int main()
{
	//栈是一个特殊的线性表，只允许在一端进行插入和删除操作，遵循“后进先出”的原则。
	//队列是一个特殊的线性表，只允许在一端进行插入操作，在另一端进行删除操作，遵循“先进先出”的原则。
	Stack s;
	InitStack(&s);
	isEmpty(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	ElemType e;
	pop(&s, &e);
	printf("出栈元素为：%d\n", e);
	getTop(&s, &e);
	printf("栈顶元素为：%d\n", e);
	return 0;
}
