#include"LinkedList.c"

LinkedList * sum(LinkedList *list1,LinkedList *list2)
{
	LinkedList *output=NULL;
	if(list1==NULL&&list2==NULL)
		return output;
	if(list1==NULL||list2==NULL)
		return (list1!=NULL)?list1:list2;
	
	int x;
	int y;
	int z;
	int carry=0;
	while(list1!=NULL&&list2!=NULL)
	{
		x=list1->data;
		y=list2->data;
		z=x+y+carry;
		if(z/10!=0){
			carry=1;
			z=z%10;
		}else{
			carry=0;
		}
		output=insertAtTail(output,z);
		list1=list1->next;
		list2=list2->next;
	}

	while(list1!=NULL){
		x=list1->data;
		z=x+carry;
		if(z/10!=0){
			carry=1;
			z=z%10;
		}else{
			carry=0;
		}
		insertAtTail(output,z);
		list1=list1->next;
	}

	while(list2!=NULL)
	{
		y=list2->data;
		z=y+carry;
		if(z/10!=0){
			carry=1;
			z=z%10;
		}else{
			carry=0;
		}
		insertAtTail(output,z);
		list2=list2->next;
	}


	if(carry==1){	//if we get carry from last digit
		insertAtTail(output,1);
	}
	return output;
	
}

int main()
{
	/*617
	+295
----------------
      912
---------------*/

	LinkedList *list1=NULL;
	list1=insertAtTail(list1,7);
	insertAtTail(list1,1);
	insertAtTail(list1,6);

	LinkedList *list2=NULL;
	list2=insertAtTail(list2,5);
	insertAtTail(list2,9);
	insertAtTail(list2,2);
	
	printList(list1);
	printList(list2);

	LinkedList *output=sum(list1,list2);
	printList(output);
	return 0;
}