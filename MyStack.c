#include<stdio.h>
#include<stdlib.h>
struct Stack
{
	int capacity;
	int top;
	int *array;
};

struct Stack * createStack(int capacity)
{
	struct Stack *S=(struct Stack *)malloc(sizeof(struct Stack));
	S->capacity=capacity;
	S->top=-1;
	S->array=malloc(sizeof(int)*capacity);
	return S;
}

void doubleStack(struct Stack *S)
{
		S->capacity*=2;
		S->array=realloc(S->array,S->capacity);
}

int isFull(struct Stack *S)
{
	if(S->top==(S->capacity-1))
		return 1;
	else
		return 0;
}

int isEmpty(struct Stack *S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}

void push(struct Stack *S,int element)
{
	if(isFull(S))
	{
	//	printf("Stack is overflow\n");
		doubleStack(S);
	}
	S->top++;
	S->array[S->top]=element;
}

int pop(struct Stack *S)
{
	if(isEmpty(S))
	{
		printf("Stack is underflow\n");
		return -1;
	}
	return S->array[S->top--];
}

int peek(struct Stack *S)
{
	if(isEmpty(S))
	{
		printf("Stack is underflow\n");
		return -1;
	}
	return S->array[S->top];
}