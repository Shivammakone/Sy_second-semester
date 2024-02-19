//totaldegree is addition of row...
#include<stdio.h>
void totaldegree(int a[10][10],int n);
int main()
{
	int n,a[10][10],i,j;
	printf("Enter limit:");
	scanf("%d",&n);
	printf("Enter matrx in format:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	totaldegree(a,n);	
} 
void totaldegree(int a[10][10],int n)
{
	int i,j,t;
	for(i=1;i<=n;i++)
	{
		t=0;
		for(j=1;j<=n;j++)
		{
			t=t+a[j][i]+a[i][j];
		}
		printf("\n totaldegree of V%d=%d",i,t);
	}
}
