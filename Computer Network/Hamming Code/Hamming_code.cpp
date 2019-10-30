#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"math.h"
using namespace std;
int count(char *par,int p,int t)
{
	int l=0;
	for(int j=p;j<t;j++)
		if((j&p)==p && par[j-1]=='1')
			l++;
	return l;
}
int main()
{
	system("clear");
	char d[20];
	cout<<"\nEnter Data\t\t:\t";
	cin>>d;
	int m=strlen(d);
	d[m]='\0';
	int r=0;
	while(m+r+1>pow(2,r))
		r++;
	cout<<"\nParity Bit\t\t:\t"<<r;
	cout<<"\nData\t\t\t:\t"<<d<<endl;
	int p,j,i,k;
	char par[m+r];
	p=1,j=0;
	for(i=0;i<m+r;i++)
	{
		if((i+1)==p)
		{
			par[i]='0';
			p*=2;
		}
		else{
			par[i]=d[j++];}
	}
	par[m+r]='\0';
	cout<<"\nIntermediate Codeword\t:\t"<<par<<"\n\n";
	p=1;
	for(i=0;i<r;i++)
	{	
		k=count(par,p,(m+r));
		if(k%2!=0)
			par[p]='1';
		p*=2;
	}
	cout<<"\nHummaing Code\t\t:\t"<<par<<"\n\n";
	return 0;
}
