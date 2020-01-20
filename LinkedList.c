#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}LinkedList;

LinkedList * createNode(int data)
{
		struct LinkedList *node = malloc(sizeof(LinkedList));
		node->data=data;
		node->next=NULL;
		return node;
}

void insertAtHead(LinkedList **head,int data)
{
		LinkedList * node = createNode(data);
		if(*head==NULL)	//Empty List
		{
			*head=node;
		}
		else{
			node->next=*head;
			*head=node;
		}
		
}

LinkedList * insertAtTail(LinkedList *head,int data)
{
		LinkedList * node = createNode(data);
		if(head==NULL)
		{
			head=node;
		}
		else{
			LinkedList * temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=node; 
		}
		return head;
}

void printList(LinkedList *head)
{
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
	printf("\n");
}

void printRecursive(LinkedList *head)
{
	if(head!=NULL)
	{
		printRecursive(head->next);
		printf("%d\t",head->data);
	}
}

LinkedList * reverseList(LinkedList *head)
{
	LinkedList *temp=head;
	LinkedList *prev=NULL;
	LinkedList *extra=NULL;

	while(temp!=NULL)
	{
		extra=prev;
		prev=temp;
		temp=temp->next;
		prev->next=extra;
	}
	return prev;
}

LinkedList * reverseListRecursive(LinkedList *head)
{
		if(head==NULL)
			return NULL;
		else if(head->next==NULL)
			return head;
		//to be continued...
}
