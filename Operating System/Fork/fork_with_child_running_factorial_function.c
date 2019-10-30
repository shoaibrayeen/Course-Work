#include<stdio.h>
int main()
{
	system("clear");
	int i,n,pid,k,s;
	printf("\nEnter Number\t:\t");
	scanf("%d",&n);
	pid=fork();
	k=n;
	if(pid==0)
	{
		for(i=(n-1);i>=1;i--) {
			n*=i;
                } 
		printf("\nFactorial of %d\t:\t%d\n",k,n);
	}
	else
	{
		wait((void*)&s);
		printf("\nChild Process Successfully Executed!!!!!!!!!!!!!!\n");
		for(i=1;i<=k;i++)
		{
			if(k%i==0)
				printf("\nFactor of %d\t:\t%d\n",k,i);
		}
	}
	return 0;
}
