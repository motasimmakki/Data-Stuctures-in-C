#include<stdio.h>
#include"LinkedList.c"

LinkedList typedef LL;

LL * merge(LL *list1,LL *list2)
{
	LL * newNode=NULL,*temp;
	if(list1==NULL&&list2==NULL)
		return NULL;
	
	if(list1==NULL||list2==NULL)
		return (list1!=NULL)?list1:list2;

	if(list1->data < list2->data)
		newNode=list1;
	else
		newNode=list2;
	while(list1!=NULL && list2!=NULL)
	{
		if( list1->data < list2->data )
		{
			if( list1->next!=NULL && list1->next->data < list2->data )
				list1 = list1->next;
			else{
				temp = list1;
				list1=list1->next;
				temp->next = list2;
			}
		}
		else{
			if( list2->next!=NULL && list2->next->data < list1->data )
				list2 = list2->next;
			else{
				temp = list2;
				list2=list2->next;
				temp->next = list1;
			}
		}
	}//while
	return newNode;
}



int main()
{
	LinkedList * list1=NULL;
	LinkedList * list2=NULL;
	int a[5]={1,5,10,12,14},i;
	int b[]={2,9,11,13,15,16,19};

	list1=insertAtTail(list1,a[0]);
	list2=insertAtTail(list2,b[0]);

	for(i=1;i<5;i++)
		insertAtTail(list1,a[i]);

	for(i=1;i<7;i++)
		insertAtTail(list2,b[i]);

	printList(list1);
	printList(list2);

	LL *finalList=merge(list1,list2);
	printList(finalList);
   
	return 0;
}