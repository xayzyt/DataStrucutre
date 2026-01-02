#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElemType;
//队列的链式结构体
typedef struct QueueNode
{
	ElemType data;
	struct QueueNode* next;
}QueueNode;
typedef struct
{
	QueueNode* front; //队头指针
	QueueNode* rear;  //队尾指针
}Queue;

//初始化队列
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = 0;
	node->next = NULL;
	q->front = node;
	q->rear = node;
	return q;
}
//入队
//在队尾插入元素
void enqueue(Queue* q, ElemType value)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = value;
	node->next = NULL;
	q->rear->next = node; //将新节点链接到队尾
	q->rear = node;       //更新队尾指针
}
//出队
int dequeue(Queue* q, ElemType* e)
{
	QueueNode* node = q->front->next; //获取队头节点
	*e = node->data;               //获取出队元素
	q->front->next = node->next; //更新队头指针
	if (q->rear == node) //如果出队的是最后一个节点
	{
		q->rear = q->front; //更新队尾指针
	}
	free(node); //释放出队节点
	return 1; //出队成功
}
//获取队头元素
int getFront(Queue* q, ElemType* e)
{
	if (q->front == q->rear) //队列为空
	{
		return 0; //获取失败
	}
	*e = q->front->next->data; //获取队头元素
	return 1; //获取成功
}

int main()
{


	return 0;                                                                                                                                                      
}
