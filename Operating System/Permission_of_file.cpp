#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<pwd.h>
using namespace std;
int main(int ac ,char** av)
{
	system("clear");
	char f[10];
	int i=1;
	while(i<ac)
	{
		strcpy(f,av[i]);
		struct stat h;
		if(stat(f,&h)<0){cout<<"\nFile "<<f<<" not Exist\n";}
		else
		{
			cout<<"\nPermission of File "<<f<<"\n";
			cout<<"\nFile Permission\t:\t";
			int k,c;
			c=256;
			k=h.st_mode;
			if((c&k)==c){cout<<"r";}
			else{cout<<"-";}
			if(((c/2)&k)==(c/2)){cout<<"w";}
			else{cout<<"-";}
			if(((c/4)&k)==(c/4)){cout<<"x";}
			else{cout<<"-";}
			if(((c/8)&k)==(c/8)){cout<<"r";}
			else{cout<<"-";}
			if(((c/16)&k)==(c/16)){cout<<"w";}
			else{cout<<"-";}
			if(((c/32)&k)==(c/32)){cout<<"x";}
			else{cout<<"-";}
			if(((c/64)&k)==(c/64)){cout<<"r";}
			else{cout<<"-";}
			if(((c/128)&k)==(c/128)){cout<<"w";}
			else{cout<<"-";}
			if(((c/256)&k)==(c/256)){cout<<"r";}
			else{cout<<"-";}
			struct passwd *p=getpwuid(h.st_uid);
			cout<<"\nUser Name is\t:\t"<<p->pw_name;
			cout<<"\nAccess Time is\t:\t";
			struct tm* t=localtime(&(h.st_atime));
			cout<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec;
			cout<<"\nAccess Date is\t:\t";	
			cout<<t->tm_mday<<"/"<<t->tm_mon+1<<"/"<<t->tm_year+1900<<"\n";
		}
		i++;
	}
	return 0;
}
