#include<stdio.h>
#include"MyStack.c"
//Guess the output
/*void question(struct Stack *S,struct Stack *T){
	int element;
	if(isEmpty(S))
		return ;
	element=pop(S);
	push(T,element);
	question(S,T);
}*/
/*
void question(struct Stack *S,struct Stack *T){
	int element;
	if(isEmpty(S))
		return ;
	element=pop(S);
	question(S,T);
	push(T,element);
}*/


void insertAtBottom(struct Stack *S,int element){
	int e;
	if(isEmpty(S)){
		push(S,element);
		return ;
	}
	e=pop(S);
	insertAtBottom(S,element);
	push(S,e);
}
int main()
{	
	struct Stack *S=createStack(5);	
	insertAtBottom(S,10);
	insertAtBottom(S,20);
	insertAtBottom(S,40);
	insertAtBottom(S,50);
	insertAtBottom(S,60);
	printf("Capacity Before Overflow : %d\n",S->capacity);
	insertAtBottom(S,70);
	printf("Capacity After Overflow : %d\n",S->capacity);
	while(!isEmpty(S))
		printf("[%d]",pop(S));

}
