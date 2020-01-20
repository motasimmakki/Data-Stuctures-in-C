#include<stdio.h>
#include<stdlib.h>

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

void inorder(struct BinaryTree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("[%c]\t",root->data);
		inorder(root->right);
	}
}

void preorder(struct BinaryTree *root)
{
	if(root!=NULL)
	{
		printf("[%c]\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct BinaryTree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%c]\t",root->data);
	}
}


int main()
{
	struct BinaryTree *root=createNewNode('A');
	root->left=createNewNode('B');
	root->right=createNewNode('C');
	root->left->left=createNewNode('D');
	root->left->right=createNewNode('E');
	root->right->left=createNewNode('F');
	root->right->right=createNewNode('G');
	root->left->left->left=createNewNode('H');
	
	printf("Inorder : ");
	inorder(root);
	printf("\n");
	printf("Preorder : ");
	preorder(root);
	printf("\n");
	printf("Postorder : ");
	postorder(root);
	return 0;
}