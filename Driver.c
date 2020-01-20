#include"LinkedList.c"
void join()
{
	/*LinkedList *list1=NULL;
	LinkedList *list2=NULL;

	list1=insertAtTail(list1,10);
	insertAtTail(list1,20);
	insertAtTail(list1,30);
	insertAtTail(list1,40);
	insertAtTail(list1,50);
	
	list2=insertAtTail(list2,60);
	insertAtTail(list2,70);
	
	//Joining
	list2->next->next=list1->next->next;

	printList(list1);
	printList(list2);*/
}

int length(LinkedList *list)
{
	int count=0;
	while(list!=NULL)
	{
		count++;
		list=list->next;
	}
	return count;
}

LinkedList * mid(LinkedList *list)
{
	int len=length(list);
	int i;
	for(i=0;i<len/2;i++)
		list=list->next;
	return list;
}

int main()
{
	LinkedList *list=NULL;
	list=insertAtTail(list,10);
	insertAtTail(list,20);
	insertAtTail(list,30);
	insertAtTail(list,40);
	insertAtTail(list,50);
	insertAtTail(list,60);

	printList(list);
	printf("Middle Element is %d",mid(list)->data);

	return 0;	
}