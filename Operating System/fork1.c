#include<stdio.h>
int main(int ac,char **av)
{
	int s,i;
	int pid=fork();
	if(pid==0)
	{
		execvp(av[1],&av[1]);
		printf("\nError\n");
		return 7;	
	}
	else
	{
		wait((void*)&s);
		printf("\nValue Returned By Child Process\t:\t%d\n",s/256);
		if((s/256)!=4)
		{
			printf("\nError in Child Program\n");
			return 0;
		}
	}
	return 0;
}
