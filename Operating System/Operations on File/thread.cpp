#include<iostream>
#include<stdlib.h>
#include<fcntl.h>
using namespace std;
void *input(void *f)
{
	cout<<"\nEnter Filename\t:\t";
	cin.getline((char*)f,10);
	pthread_exit(0);
}
void *display(void *f)
{
	int fd=open((char*)f,O_RDONLY);
	if(fd<0){cout<<"\nError In Openning File\n";pthread_exit(0);}
	int n;
	char b[10];
	cout<<"\nThe Contents of File\n";
	while((n=read(fd,b,sizeof(b)-1))!=0){b[n]='\0';cout<<b;}
	close(fd);
	pthread_exit(0);
}
int main()
{
	system("clear");
	pthread_t t1,t2;
	pthread_attr_t at;
	pthread_attr_init(&at);
	char f1[10];
	pthread_create(&t1,&at,input,f1);
	pthread_join(t1,NULL);
	pthread_create(&t2,&at,display,f1);
	pthread_join(t2,NULL);
	cout<<"\n";
	return 0;
}
