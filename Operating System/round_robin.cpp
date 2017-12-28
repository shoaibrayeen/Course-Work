#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	int b[10],a[10],p[10],wt[10],tat[10],i,j,tq;
	system("clear");
	cout<<"\nNumber of Processor\t:\t";
	cin>>n;
	float aw=0,at=0;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter Burst Time and Arrival Time for Process "<<i<<"\n";
		cin>>b[i];
		cin>>a[i];
		p[i]=i;
	}
	cout<<"\nEnter Time Quantum\t:\t";	
	cin>>tq;
	for(i=1;i<n;i++)
	{
		for(j=i;j>=1;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);				
				swap(p[j],p[j+1]);
			}
			else
				break;
		}
	}
	int db[10],L=0,S[10];
	for(i=0;i<n;i++)
	{
		db[i]=b[i];
		L+=b[i];
		S[i]=-1;
	}

	for(j=a[0],i=0;j<L;)
	{
			if(db[i]!=0)
			{

				if(S[i]==-1)
				{	
					wt[i]=j-a[i];
				}
				else
				{
					wt[i]=wt[i]+j-S[i];
				}
	
				if(db[i]<=tq)
				{	
					j+=db[i];
					db[i]=0;
					tat[i]=j-a[i];
				}			
				else
				{	
					db[i]-=tq;
					j+=tq;
					S[i]=j;
				}
				
			}
			i=(i+1)%n;
	}
	
	cout<<"\nProcess\tBT\tAT\tWT\tTAT\n";
	for(i=0;i<n;i++)
	{
		aw+=wt[i];
		at+=tat[i];
		cout<<"P"<<p[i]<<"\t"<<b[i]<<"\t"<<a[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
	}
	cout<<"\n\nAverage Waiting Time\t\t:\t"<<(aw/n);
	cout<<"\n\nAverage Turn Around Time\t:\t"<<(at/n)<<"\n";
	return 0;	
}
