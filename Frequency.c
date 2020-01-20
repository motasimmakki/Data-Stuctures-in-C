#include<stdio.h>
#include<string.h>

int frequencyCalculator(char str[],char X,int start,int end)
{
	if(start==end)
	{
			if(str[start]==X)
				return 1;
			else
				return 0;
	}
	int mid=(start+end)/2;
	int left=frequencyCalculator(str,X,start,mid);
	int right=frequencyCalculator(str,X,mid+1,end);
	return left+right;
}

int main()
{
	char str[30]="Jamia Millia Islamia";
	
	printf("%d",frequencyCalculator(str,'a',0,strlen(str)-1));

	return 0;		
}