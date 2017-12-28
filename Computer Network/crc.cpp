#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void rem( char* msg, char *gen)
{

	int m=strlen(msg);
	int r=strlen(gen);
	msg[m]='\0';
	int i=0;
	while(r<=m)
	{
		while(msg[i]=='0'){i++;m--;};	
		if(r<=m)
		{
			for(int j=0;j<r;j++)
			{
				if(msg[i+j]==gen[j])
					msg[i+j]='0';
				else
					msg[i+j]='1';
			}
		}
		i++,m--;
	}
}
void error(char *msg)
{
	int l=strlen(msg);
	for(int i=(l-1);i>=0;i++)
		if(msg[i]=='1'){
			cout<<"\nError in Codeword\n";return;}
}
int main()
{
	char msg[30],gen[10],rm[30],m,r,i;
	system("clear");
	cout<<"\nEnter Message\t:\t";
	cin>>msg;
	cout<<"\nEnter Generator\t:\t";	
	cin>>gen;	
	m=strlen(msg);
	r=strlen(gen);
	for(i=0;i<r;i++)
		msg[m++]='0';
	msg[m]='\0';
	strcpy(rm,msg);
	rem(rm,gen);
	int l=m;
	for(i=0;i<r;i++)
	{
		l--;
		msg[l]=rm[l];
	}
	cout<<"\nRemainder\t:\t"<<rm;
	cout<<"\nCodeword\t:\t"<<msg;
	cout<<"\n\n";
	strcpy(rm,msg);
	rem(rm,gen);
	cout<<"\n------------------------Errorless Medium---------------------------------------\n";
	cout<<"\nRemainder\t:\t"<<rm;
	cout<<"\nNo Error in Code:\t"<<msg;
	int kk=rand()%m;
	strcpy(rm,msg);
	cout<<"\n----------------------------Errorneous Medium----------------------\n";
	if(rm[kk]=='1'){rm[kk]='0';}else{rm[kk]='1';}
	rem(rm,gen);
	cout<<"\nRemainder\t:\t"<<rm;
	error(rm);
	return 0;
}
