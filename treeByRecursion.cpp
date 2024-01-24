#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
node *create(node *root)
{
	node *temp,*newnode,*parant;
	int n,num,i;
	printf("enter the limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(node*)malloc(sizeof(node));
		printf("Enter the value:");
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
			parant=temp;
			if(newnode->data<temp->data)
			temp=temp->left;
			else 
			temp=temp->right;
		}
		if (newnode->data<parant->data)
		parant->left=newnode;
		else
		parant->right=newnode;
	}
	return root;
}
void *inorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
void *preorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		printf("%d  ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void *postorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
void mirror(node *root)
{
	node *temp=root,*temp1;
	if(temp!=NULL)
	{
		if(temp->left!=NULL)
		mirror(temp->left);
		if(temp->right!=NULL)
		mirror(temp->right);
		
		temp1=temp->left;
		temp->left=temp->right;
		temp->right=temp1;
	}
}
int main()
{
	int ch;
	node *root=NULL;
	node *create(node *root);
	void *inorder(node *root);
	void *preorder(node *root);
	void *postorder(node *root);
	void mirror(node *root);
	do{
	
//	printf("\n 0-create \n 1-Inorder \n 2-Preorder \n 3-Postorder \n 4-mirror in Inorder \n 5-mirror in Preorder \n 6-mirror in Postorder");
	printf("\n enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:root=create(root);
			break;
		case 1:printf("In Inorder:");
		    inorder(root);
			break;
		case 2:printf("In Preorder:");
		    preorder(root);
			break;
		case 3:printf("In Postorder:");
		    postorder(root);
			break;
		case 4:	printf("\nInorder display:\n");
				inorder(root);
			    mirror(root);
				printf("\nBy mirror in Inorder:\n");
				inorder(root);
				break;
		case 5:
				printf("\nPreorder display:\n");
				preorder(root);
			    mirror(root);
				printf("\nBy mirror in Preorder:\n");
				preorder(root);
				break;
		case 6:
				printf("\npostorder display:\n");
				postorder(root);
			    mirror(root);
				printf("\nBy mirror in Postorder:\n");
				postorder(root);
				break;
		default:printf("Invalid choice.....");
	}
	}while(ch<8);
}


