#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct node
{
	int data;
	struct node *left,*right;
}Node;
struct stack
{
	struct node *data[max];
	int top;
}s;
void init()
{
	s.top=-1;
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
void push(struct node *temp)
{
	if(isfull())
	printf("stack is full..");
	else
	{
		s.top++;
		s.data[s.top]=temp;
	}
}
struct node *pop()
{
	struct node *temp;
	if(isempty())
	   printf("stack is underflow");
	else
	{
		temp=s.data[s.top];
		s.top--;
	}
  return temp;
}
Node * create(Node *root)
{
	Node *parant,*temp,*newnode;
	int n,i;
	printf("enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(Node*)malloc(sizeof(Node));
		printf("enter value in node:");
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
			if(newnode->data<parant->data)
			temp=temp->left;
			else
			temp=temp->right;
		}
		if(newnode->data<parant->data)
		parant->left=newnode;
		else
		parant->right=newnode;
	}
	return root;
}
Node *inorder(Node *root)
{
	Node *temp;
	temp=root;
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
}
int main()
{
	Node *root=NULL;
	init();
	root=create(root);
	printf("Inorder =");
	inorder(root);
}
