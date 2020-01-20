#include<stdio.h>
#include<stdlib.h>
struct DoublyLinkedList
{
	int data;
	struct DoublyLinkedList *prev;
	struct DoublyLinkedList *next;
};

struct DoublyLinkedList typedef DLL;

struct DoublyLinkedList * createNode(int data)
{
		DLL *node=(DLL *)malloc(sizeof(DLL));
		if(node==NULL){
			printf("Memory overflows");
			return NULL;
		}
		node->data=data;
		node->prev=node->next=NULL;
		return node;
}

struct DoublyLinkedList * insertAtTail(DLL *head,int data)
{
	DLL * node=createNode(data);
	if(head==NULL){
		head=node;
		return head;
	}
	DLL * temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=node;
	node->prev=temp;
	return head;
}

void printList(DLL *head)
{
	while(head!=NULL)
	{
		printf("[%d]\t",head->data);
		head=head->next;
	}
	printf("\n");
}

int main()
{	
	DLL *head=NULL;
	head=insertAtTail(head,10);
	insertAtTail(head,20);
	insertAtTail(head,30);
	insertAtTail(head,40);
	insertAtTail(head,50);
	insertAtTail(head,60);
	printList(head);
	return 0;
}