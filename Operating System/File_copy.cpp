#include<iostream>
#include<stdlib.h>
#include<fcntl.h>
using namespace std;
int main()
{	
	system("clear");
	char a[10],s[10],d[10];
	int n,fd,fd1;
	cout<<"\nEnter Source File\t:\t";
	cin>>s;
	fd=open(s,O_RDONLY);
	if(fd<0)
	{
		cout<<"\nFile Not Openned\n";
		exit(0);
	}
	cout<<"\nEnter Destination File\t:\t";	
	cin>>d;
	fd1=open(d,O_CREAT|O_WRONLY,0666);
	while((n=read(fd,a,sizeof(a)))!=0)
		write(fd1,a,n);
	close(fd);
	close(fd1);
	fd1=open(d,O_RDONLY);
	n=0;
	while((n=read(fd1,a,sizeof(a)-1))!=0)
	{
		a[n]='\0';
		cout<<a;
	}
	close(fd1);
	return 0;
}
