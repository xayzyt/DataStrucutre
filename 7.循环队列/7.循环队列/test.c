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

//为了解决这一复杂的调整队列问题，我们可以使用循环队列来实现队列的顺序存储结构。
int equeue_Circular(Queue* Q, ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("队列满，无法入队\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}

int main()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL)
	{
		printf("内存分配失败\n");
		return 1;
	}
	InitQueue(q);
	equeue_Circular(q, 10);
	equeue_Circular(q, 20);
	equeue_Circular(q, 30);
	ElemType e;
	dequeue(q);
	getHead(q, &e);
	printf("队头元素为：%d\n", e);

	free(q);
	return 0;
}
