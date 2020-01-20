#include<stdio.h>
#include"MyStack.c"

struct Advance
{
	struct Stack *M;
	struct Stack *T;
};

struct Advance * createAdvanceStack(int size)
{
		struct Advance *S=malloc(sizeof(struct Advance ));
		S->M=createStack(size);
		S->T=createStack(size);
		return S;
}

void advancePush(struct Advance *S,int data)
{
		if(isEmpty(S->M)){
			push(S->M,data);
			push(S->T,data);
			return ;
		}
		if(data>peek(S->T)){
			push(S->T,peek(S->T));
		}
		else{
			push(S->T,data);
		}
		push(S->M,data);
}

int advancePop(struct Advance *S)
{
		pop(S->T);
		return pop(S->M);
}

int min(struct Advance *S)
{
	return peek(S->T);
}

int main()
{
		struct Advance * S=createAdvanceStack(10);
		
		advancePush(S,10);
		printf("Minimum is %d\n",min(S));
		advancePush(S,2);
		printf("Minimum is %d\n",min(S));
		advancePush(S,5  );
		printf("Minimum is %d\n",min(S));
		advancePush(S,1);
		printf("Minimum is %d\n",min(S));
		advancePop(S);
		advancePop(S);
		printf("Minimum is %d\n",min(S));

		return 0;	
}