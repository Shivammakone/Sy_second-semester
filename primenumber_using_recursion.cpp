#include<stdio.h>
int main()
{
	int n,k;
	int prime(int n);
	printf("enter number to check:");
	scanf("%d",&n);
	prime(n);
	if(prime(n)==3)
	printf("number is prime..");
	else
	printf("number is not prime");
}
int prime(int n)
{
	int i=2;
	if(i<n)
	{
		if (n%i==0)
		return 0;
		else
		{
			i++;
			prime(n);
		}
	}
	return 3;
}
