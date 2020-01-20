#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

struct BinaryTree * createNewNode(int data)
{
	struct BinaryTree *node=malloc(sizeof(struct BinaryTree));
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

int search(char *inorder,int data)
{
	int i;
	for(i=0;i<strlen(inorder);i++)
		if(data==inorder[i])
			return i;
}

struct BinaryTree *  BuildTree(char *inorder,char *preorder,int inorderStart,int inorderEnd)
{
	static int preOrderIndex=0;
	
	if(inorderStart>inorderEnd)	
		return NULL;

	int rootValue=preorder[preOrderIndex++];
	int midPoint=search(inorder,rootValue);
	struct BinaryTree * newNode=createNewNode(rootValue);
	
	if(inorderStart==inorderEnd)
		return newNode;

	newNode->left=BuildTree(inorder,preorder,inorderStart,midPoint-1);
	newNode->right=BuildTree(inorder,preorder,midPoint+1,inorderEnd);

	return newNode;
}


void inorderTraverse(struct BinaryTree *root)
{
	if(root==NULL)
		return ;
	inorderTraverse(root->left);
	printf("%c\t",root->data);
	inorderTraverse(root->right);
}

int main()
{
	char inorder[]="FBAGDHCEI",preorder[]="ABFCDGHEI";

	struct BinaryTree *root=BuildTree(inorder,preorder,0,strlen(inorder)-1);
	
	inorderTraverse(root);

	return 0;
}