#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	system("clear");
	int n,i;
	cout<<"\nEnter number of blocks in Memory\t:\t";
	cin>>n;
	int b[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter Size of Block "<<i<<"\t:\t";
		cin>>b[i];
	}
	int c,m,ps;
	while(1)
	{
		cout<<"\nBlock\t\t\tSize\n";
		for(i=0;i<n;i++)
		{
			cout<<i<<"\t\t\t"<<b[i]<<"\n";
		}
		cout<<"\nEnter the size of Process\t:\t";
		cin>>ps;
		cout<<"\n\n\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit\n";
		cin>>c;
		switch(c)
		{
			case 1: m=0;
				for(i=0;i<n;i++)
				{
					if(b[i]>=ps)
					{
						cout<<"\nProcess is fitted in Block "<<i<<"\nSize of Block "<<b[i];
						b[i]-=ps;
						cout<<"\nRemaining Size of Block "<<i<<" is "<<b[i];
						m=1;
						break;
					}
				}
				if(m==0){cout<<"\nThere is no space for Process\n";}break;
			case 2: m=-1;
				for(i=0;i<n;i++)
				{
						if(b[i]>=ps)
						{
							if(m==-1){m=i;}
							else{
								if(b[i]<=b[m]){m=i;}
								}
						}
				}
				if(m==-1){cout<<"\nThere is No Space for Process\n";}
				else{		cout<<"\nProcess is fitted in Block "<<m<<"\nSize of Block "<<b[m];
						b[m]-=ps;
						cout<<"\nRemaining Size of Block "<<m<<" is "<<b[m];}
				break;
			case 3: m=-1;
				for(i=0;i<n;i++)
				{
						if(b[i]>=ps)
						{
							if(m==-1){m=i;}
							else{if(b[i]>b[m]){m=i;}}
						}
				}
				if(m==-1){cout<<"\nThere is No Space for Process\n";}
				else{		cout<<"\nProcess is fitted in Block "<<m<<"\nSize of Block "<<b[m];
						b[m]-=ps;
						cout<<"\nRemaining Size of Block "<<m<<" is "<<b[m];}
				break;
			case 4:exit(0);
		}
	}
	return 0;
}
