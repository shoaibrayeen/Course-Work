#include<iostream>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
using namespace std;
int main()
{
	system("clear");
	char s[10];
	int fd[2],fd1[2];
	int n;
	if(pipe(fd)<0 || pipe(fd1)<0){cout<<"\nError in Pipe\n";exit(0);}
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		char b[10];
		cout<<"\nEnter the filename\t:\t";
		cin>>s;
		close(fd[0]);
		close(fd1[1]);
		write(fd[1],s,strlen(s)+1);
		while((n=read(fd1[0],b,sizeof(b)-1))!=0)
		{
			b[n]='\0';
			cout<<b;
		}
		close(fd[1]);
		close(fd1[0]);
	}
	else
	{
		close(fd[1]);
		close(fd1[0]);
		char b1[10];
		read(fd[0],b1,sizeof(b1)-1);
		int f=open(b1,O_RDONLY);
		while((n=read(f,b1,sizeof(b1)))!=0)
			write(fd1[1],b1,n);
		close(f);
		close(fd1[1]);
		close(fd[0]);
	}
	return 0;
}
