#include<stdio.h>

int max(int a,int b)
{
	return (a>b)?a:b;
}

int LCS(char X[],int i,int m
	   ,char Y[],int j,int n)
{
  if(i==m||j==n)
	return 0;
  else if(X[i]==Y[j])
	return 1+LCS(X,i+1,m,Y,j+1,n);
  else 
	return max(LCS(X,i+1,m,Y,j,n),
			   LCS(X,i,m,Y,j+1,n));
}

int main()
{
	char X[]="ABCD",Y[]="DABD";
	
	printf("%d",LCS(X,0,3,Y,0,3));

	return 0;
}