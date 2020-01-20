#include<stdio.h>
#include<stdlib.h>

struct HeapTree
{
	int *array;
	int count;
	int size;
	int type;	// 0 mean max-heap, 1 means min-heap
};

struct HeapTree * createHeapTree(int size,int type)
{
	struct HeapTree *t=malloc(sizeof(struct HeapTree));
	t->count=0;
	t->size=size;
	t->type=type;
	t->array=malloc(sizeof(int)*t->size);
	return t;
}

int deleteMax(struct HeapTree *t)
{
	if(t->count==0)
		return -1;
	int temp;
	temp=t->array[t->count-1];
	t->array[t->count-1]=t->array[0];
	t->array[0]=temp;
	t->count--;
	percolateDown(h,0);//homework...	
}

void heapsort()
{
	//homework (Hint:preserve the count)
}

void insert(struct HeapTree *t,int data)
{
	if(t->count==t->size){
		t->size*=2;
		t->array=realloc(t->array,t->size);
	}
	
	t->count++;
	
	int presentIndex=t->count-1;
	//PercolateUp
	while(presentIndex>0&&data>t->array[(presentIndex-1)/2]){
		t->array[presentIndex]=t->array[(presentIndex-1)/2];
		presentIndex=(presentIndex-1)/2;
	}
	t->array[presentIndex]=data;
}

int main()
{
	struct HeapTree *h=createHeapTree(10,0);
	insert(h,31);
	insert(h,9);
	insert(h,8);
	insert(h,2);
	insert(h,12);
	insert(h,11);
	insert(h,32);
	int i;	
	for(i=0;i<h->count;i++)
	{
		printf("%d\t",h->array[i]);
	}

}

