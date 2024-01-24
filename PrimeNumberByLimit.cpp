#include<stdio.h>
int main()
{
	int n;
	int prime(int n);
	printf("enter the number:");
	scanf("%d",&n);
	prime(n);
	if((prime(n))==1)
	printf("Number is prime");
	else
	printf("Number is not prime");
}
int prime(int n)
{
	static int i=2,k=2,m=n;
	if(i<n)
	{
		if(n%i==0)
		{
			return 0;
		}
		else
		{
			i++;
			return prime(n);
		}
	}
	return 1;
	
}
