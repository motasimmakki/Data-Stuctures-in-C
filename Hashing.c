#include<stdio.h>
#include<stdlib.h>
#define BLOCK 5

enum boolean{false,true};

int hash(int data,int size)
{
	return data%size;
}

struct LinkedList
{
	int data;
	struct LinkedList *next;		
};

struct HashBlock
{
	int element;
	struct LinkedList *head;
};

struct HashTable
{
	int totElement;	//#total elements in a hashtable(sum of all elements from all bloack)
	int size;		//#block (# means number of)
	struct HashBlock **table;
};

struct HashTable * createHashTable(int total)
{
	int i;
	struct HashTable *h=malloc(sizeof(struct HashTable));
	h->totElement=0;
	h->size=total/BLOCK;

	h->table=malloc(sizeof(struct HashBlock *)*h->size);

	for(i=0;i<h->size;i++){
		h->table[i]=malloc(sizeof(struct HashBlock));
		h->table[i]->element=0;
		h->table[i]->head=NULL;
	}
	return h;	
}

enum boolean search(struct HashTable *h,int data)
{
	int key=hash(data,h->size);
	struct LinkedList *head=h->table[key]->head;
	while(head!=NULL){
		if(head->data==data){
			return true;
		}
		head=head->next;
	}
	return false;
}

int insert(struct HashTable *h,int data)
{	
	if(search(h,data)){
		printf("duplicacy");
		return 0;
	}
	int key=hash(data,h->size);
	struct LinkedList *node=malloc(sizeof(struct LinkedList));
	node->data=data;
	node->next=h->table[key]->head;

	h->table[key]->head=node;
	h->totElement++;
	h->table[key]->element++;
	return 1;	
}

int main()
{
	struct HashTable *h=createHashTable(50);
	insert(h,10);	
	insert(h,10);	//not inserted	
	insert(h,20);
	insert(h,33);	
	printf("%d\n",search(h,10));//present
	printf("%d",search(h,22));//absent
	return 0;
}