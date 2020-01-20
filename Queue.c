#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
enum bool{false,true};

struct Queue
{
	int rear;
	int front;
	int capacity;
	int *arr;
};

struct Queue typedef Queue;

Queue * createQueue(int capacity)
{
		Queue *Q=malloc(sizeof(Queue));
		if(Q==NULL){
			printf("Memory Overflows");
			return ;
		}
		Q->capacity=capacity;
		Q->arr=malloc(sizeof(int)*capacity);
		if(Q->arr==NULL){
			printf("Memory Overflows");
			return ;
		}
		Q->front=Q->rear=-1;
		return Q;
}

enum bool  isEmpty(Queue *Q)
{
	return (Q->rear==-1)&&(Q->front==-1);
}

enum bool isFull(Queue *Q)
{
	return (Q->front==(Q->rear+1)%Q->capacity); 
}

enum bool enQueue(Queue *Q,int data)
{
	if(isFull(Q)){
		printf("Queue is overflow\n");
		return false;
	}
	if(isEmpty(Q)){
		Q->front++;
	}
	Q->rear= (Q->rear+1)%Q->capacity;
	Q->arr[Q->rear]=data;
	return true;
}

int deQueue(Queue *Q)
{
	if(isEmpty(Q)){
		printf("Queue is undeflow\n");
		return -1;
	}

	int elem=Q->arr[Q->front];
	if(Q->rear==Q->front)
		Q->rear=Q->front=-1;
	else
		Q->front=(Q->front+1)%Q->capacity;
	return elem;
}

int main()
{
	Queue *Q=createQueue(5);
	enQueue(Q,10);
	enQueue(Q,20);
	enQueue(Q,30);
	enQueue(Q,40);
	enQueue(Q,50);
	//getch();
	enQueue(Q,60);

	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));

	printf("%d\t",deQueue(Q));

	enQueue(Q,10);
	enQueue(Q,20);
	enQueue(Q,30);
	enQueue(Q,40);
	enQueue(Q,50);
	//getch();
	enQueue(Q,60);

	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));
	printf("%d\t",deQueue(Q));

	printf("%d\t",deQueue(Q));
	
	return 0;
}