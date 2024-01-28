#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}Shiv;
Shiv *create(Shiv *root)
{
	Shiv *temp,*parent,*newnode;
	int i,n;
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(Shiv*)malloc(sizeof(Shiv));
		printf("\nEnter value:");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(newnode->data<temp->data)
			temp=temp->left;
			else
			temp=temp->right;
		}
		if(newnode->data<parent->data)
			parent->left=newnode;
		else
			parent->right=newnode;
	}
	return root;
}
void inorder(Shiv *root)
{
	Shiv *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
		
	}
}
Shiv *deletetree(Shiv *root,int num)
{
	Shiv *temp;
	if(root==NULL)
	return root;
	if(num<root->data)
		root->left=deletetree(root->left,num);
	else if(num>root->data)
		root->right=deletetree(root->right,num);
	else if(num==root->data)
	{
		if(root->left==NULL)
		{
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp=root->left;
			free(root);
			return temp;
		}
		temp=root->right;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		root->data=temp->data;
		root->right=deletetree(root->right,temp->data);
	}
	return root;
}
int main()
{
	int num;
	Shiv *root=NULL;
	Shiv *create(Shiv *root);
	void inorder(Shiv *root);
	Shiv *deletetree(Shiv *root,int num);
	root=create(root);
	inorder(root);
	printf("\n Enter number to delete:");
	scanf("%d",&num);
	root=deletetree(root,num);
	inorder(root);
}
