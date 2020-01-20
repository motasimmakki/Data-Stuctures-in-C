#include"MyStack.c"

int isOperand(char ch)
{
	if((ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
		return 1;
	else
		return 0;
}

int main()
{
	char postfix[20];
	char operand1,operand2;
	int i=0;
	struct Stack *S=createStack(10);
	printf("Enter postfix Expression : ");
	scanf("%s",postfix);
	while(postfix[i])
	{
		if(isOperand(postfix[i])) 
			push(S,postfix[i]);
		else
		{
			operand2=pop(S)-48;
			operand1=pop(S)-48;
			switch(postfix[i])
			{
				case '+':push(S,(operand1+operand2)+48);
						 break;
				case '-':push(S,(operand1-operand2)+48);
						 break;
				case '*':push(S,(operand1*operand2)+48);
						 break;
				case '/':push(S,(operand1/operand2)+48);
						 break;
			}
		}
		i++;
		
	}
	
	printf("%d\n",peek(S)-48);

	return 0;
}