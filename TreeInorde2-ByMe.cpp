#include<stdio.h>
#include<stdlib.h>
#define max 100
#define Navi (node*)malloc(sizeof(node)) 
struct stack
{
	struct node *data[max];
	int top;
}s;
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
void init()
{
	s.top==-1;
}
int isempty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(s.top==max-1)
	return 1;
	else
	return 0;
}
void push(node *temp)
{
	if(isfull())
	printf("stact is overfoly...");
	else
	{
		s.top++;
		s.data[s.top]=temp;
	}
}
node *pop()
{
	node *temp;
	if(isempty())
	printf("Stack is underflow...");
	else
	{
		temp=s.data[s.top];
		s.top--;
	}
	return temp;
}
node *create(node *root)
{
	node *temp,*newnode,*parant;
	int i,n;
	printf("enter the limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=Navi;
		printf("Enter value:");
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
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(newnode->data<parant->data)
		{
			parant->left=newnode;
		}
		else
		{
			parant->right=newnode;
		}
	}
	return root;
}
void *inorder(node *root)
{
	node *temp=root;
	while(temp!=NULL)
	{
		push(temp);
		temp=temp->left;
	}
	while(!isempty())
	{
		temp=pop();
		printf("%d\t",temp->data);
		temp=temp->right;
		while(temp!=NULL)
		{
			push(temp);
			temp=temp->left;
		}
	}
	return root;
	
}
int main()
{
	node *root=NULL;
	init();
	root=create(root);
	printf("\n Inorder Display");
	inorder(root);
}

