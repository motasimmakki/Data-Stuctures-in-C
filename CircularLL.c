#include<stdio.h>
#include<stdlib.h>
struct CircularLL
{
	int data;
	struct CircularLL *next;
};

struct CircularLL typedef CLL;

struct CircularLL * createNode(int data)
{
	 CLL *node=malloc(sizeof(CLL));
		if(node==NULL)
		{
			 printf("Memory overflows exception\n");
			 return NULL;
		}
	 node->data=data;
	 node->next=node;
	 return node;
}

CLL * insertAtTail(CLL *head,int data)
{
		CLL *node=createNode(data);
		if(head==NULL){
			return node;
		}
		
		CLL *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=node;
		node->next=head;
}

void printCLL(CLL *head)
{
	if(head==NULL)
	{
		return ;
	}
	CLL *temp=head;
	do{
		printf("[%d]\t",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}

int main()

{
	CLL * head=NULL;
	int i;
	head=insertAtTail(head,1);
	for(i=2;i<=100;i++)	
		insertAtTail(head,i);
	
	printCLL(head);
}