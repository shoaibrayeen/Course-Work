#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,k;
	int b[10],a[10],p[10],wt[10],tat[10],r[10],rm[10],pri[10],i,j,ft[10],tm;
	system("clear");
	cout<<"\nNumber of Processor\t:\t";
	cin>>k;
	n=k;
	float aw=0,at=0;
	for(i=0;i<n;i++)
	{
		cout<<"\nProcess "<<i<<"\n";
		cout<<"\nBurst Time\t:\t";
		cin>>b[i];
		cout<<"\nArrival Time\t:\t";
		cin>>a[i];
		cout<<"\nPriority\t:\t";
		cin>>pri[i];
		p[i]=i;
		r[i]=-1;
		rm[i]=b[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);				
				swap(p[j],p[j+1]);
			}
		}
	}
	tm=a[0];
	for(i=0;i<n;i++)
	{
		int pn=0;
		while(rm[pn]<=0 && pn<n)	
			pn++;
		if(pn!=n)
		{	
			for(int i=pn; a[i]<=tm && i<n; i++)
			{
				if(pri[i]<pri[pn] && rm[i]>0)
					pn=i;
			}
		}
		r[pn]=tm-a[pn];
		tm+=b[i];
		ft[pn]=tm;
		tat[pn]=tm-a[pn];
		wt[pn]=tat[pn]-b[pn];
		rm[pn]=0;
	}
	system("clear");
	cout<<"\nDisplay Details of Processes\n\n";
	cout<<"\nProcess\tBT\tPri\tAT\tWT\tTAT\tRT\n";
	for(i=0;i<n;i++)
	{
		aw+=wt[i];
		at+=tat[i];
		cout<<"P"<<p[i]<<"\t"<<b[i]<<"\t"<<pri[i]<<"\t"<<a[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<r[i]<<"\n";
	}
	cout<<"\n\nAverage Waiting Time\t\t:\t"<<(aw/n);
	cout<<"\n\nAverage Turn Around Time\t:\t"<<(at/n)<<"\n";
	return 0;	
}
