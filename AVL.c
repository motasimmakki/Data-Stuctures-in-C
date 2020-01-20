#include<stdio.h>
#include<stdlib.h>
struct AVL
{
	int data;
	struct AVL *left,*right;
	int height;
};

struct AVL * createNode(int data)
{
	struct AVL *node=malloc(sizeof(struct AVL));
	node->data=data;
	node->left=node->right=NULL;
	node->height=0;
	return node;
}

int height(struct AVL *root)
{
	if(root==NULL)
		return -1;
	else
		return root->height;
}

void inorder(struct AVL *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	printf("[%d : %d]\n",root->data,root->height);
	inorder(root->right);
}


int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}


struct AVL * singleLeft(struct AVL *X)
{
	struct AVL *W=X->left;
	X->left=W->right;
	W->right=X;

	X->height=max(height(X->left),height(X->right))+1;
	W->height=max(height(W->left),height(W->right))+1;
	return W;
}

struct AVL * singleRight(struct AVL *X)
{
	struct AVL *W=X->right;
	X->right=W->left;
	W->left=X;

	X->height=max(height(X->left),height(X->right))+1;
	W->height=max(height(W->left),height(W->right))+1;
	return W;
}

struct AVL * doubleRight(struct AVL *X)
{
	X->right=singleLeft(X->right);
	return singleRight(X);
}

struct AVL * doubleLeft(struct AVL *X)
{
	X->left=singleRight(X->left);
	return singleLeft(X);
}

struct AVL * insert(struct AVL *root,int data)
{
	if(root==NULL)
		root=createNode(data);

	else if(data<root->data)
	{
		root->left=insert(root->left,data);
		if(height(root->left)-height(root->right)==2)
		{
			
			if(data<root->left->data)
				root=singleLeft(root);
			else
				root=doubleLeft(root);
		}
	}
	else if(data>=root->data)
	{	
		root->right=insert(root->right,data);
		if(height(root->right)-height(root->left)==2)
		{
			if(data>root->right->data)
				root=singleRight(root);
			else
				root=doubleRight(root);
		}
	}
	root->height=max(height(root->left),height(root->right))+1;
	return root;
}


int main()
{
	struct AVL *root=NULL;
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,6);
	root=insert(root,5);
	root=insert(root,4);
	root=insert(root,10);
	root=insert(root,9);

	inorder(root);		
	
}