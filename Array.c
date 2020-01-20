#include<stdio.h>
#include<stdlib.h>
int main()
{
	//1-D Array Creation
	int n=5,i,j;
	int *p=malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
	{
		p[i]=i*10;
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d\n",p[i]);
	}

	//2-D Creation
	int row=5,col=4;
	
	int **multi=malloc(sizeof(int *)*row);
	
	for(i=0;i<row;i++)
	{
			multi[i]=malloc(sizeof(int)*col);
	}
	
	int count=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			multi[i][j]=count++;
		}
	}

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("[%d]\t",multi[i][j]);
		}
		printf("\n");
	}

	return 0;
}