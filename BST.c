#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};

struct BST typedef BST;

BST * createBSTNode(int data)
{
	struct BST *node=malloc(sizeof(BST));
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

BST * insert(BST *root,int data)
{
	BST *head=root;
	BST *node=createBSTNode(data);
	if(root==NULL)
	{
		return node;
	}
	BST *temp;
	while(root!=NULL)
	{
		temp=root;
		if(root->data < data)
		{
			root=root->right;
		}
		else{
			root=root->left;
		}
	}
	
	if(temp->data < data){
		temp->right=node;
	}
	else{
		temp->left=node;
	}
	return head;
}


void inorder(struct BST *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("[%d]\t",root->data);
		inorder(root->right);
	}
}


BST *  getMin(BST * root)
{
	if(root==NULL)
		return root;
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

int main()
{
	BST *root=NULL;
	root=insert(root,7);
	insert(root,8);
	insert(root,1);
	insert(root,5);
	insert(root,3);
	insert(root,9);
	insert(root,11);
	insert(root,12);
	insert(root,4);
	
	inorder(root);

	printf("\n%d",getMin(root)->data);

	return 0;
}