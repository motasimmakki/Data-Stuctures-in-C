#include"MyStack.c"

int isOperand(char ch)
{
	if((ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
		return 1;
	else
		return 0;
}

int priority(char ch)
{
	if(ch=='(')
		return 3;
	else if(ch=='/'||ch=='*'||ch=='%')
		return 2;
	else if(ch=='+'||ch=='-')
		return 1;
}

int main()
{
	struct Stack *S=createStack(10);

	char infix[20],postfix[20];
	int j=0,i;
	printf("Enter an infix expression : ");
	scanf("%s",infix);
	
	for(i=0;infix[i]!='\0';i++)
	{
		if(isOperand(infix[i]))	//if operand
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]==')')  //')'
		{
			while(peek(S)!='(')
				postfix[j++]=pop(S);
			pop(S);
		}
		else{	//Operator
			while( (!isEmpty(S)) && priority(infix[i])<=priority(peek(S)) && peek(S)!='(' ){
				postfix[j++]=pop(S);
			}
			push(S,infix[i]);
		}	
	}
	
	while(!isEmpty(S)){
		postfix[j++]=pop(S);
	}
	postfix[j]='\0';
	
	printf("%s",postfix);
}

