#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	int b[10],a[10],p[10],wt[10],tat[10],r[10],rm[10],i,j,ft[10],tm;
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
	int pn=0;
	while(rm[pn]<=0 && pn<n)	
		pn++;
	if(pn!=n)
	{	
		for(int i=pn; i<n; i++)
		{
			if(rm[i]<rm[pn] && rm[i]>0 && a[i]<=tm)
				pn=i;
		}
	}
	while(pn<n)
	{
		if(r[pn]==-1)
			r[pn]=tm-a[pn];
		tm++;
		ft[pn]=tm;
		tat[pn]=tm-a[pn];
		wt[pn]=tat[pn]-b[pn];
		rm[pn]--;
		pn=0;
		while(rm[pn]<=0 && pn<n)	
			pn++;
		if(pn!=n)	
		{	
			for(int i=pn; i<n; i++)
			{
				if(rm[i]<rm[pn] && rm[i]>0 && a[i]<=tm)
				pn=i;
			}
		}
	}
	system("clear");
	cout<<"\nDisplay Details of Processes\n\n";
	cout<<"\nProcess\t\tBurst Time\t\tArrival Time\t\tWaiting Time\t\tTurn Arraound Time\t\tResponse Time\n";
	for(i=0;i<n;i++)
	{
		aw+=wt[i];
		at+=tat[i];
		cout<<"P"<<p[i]<<"\t\t\t"<<b[i]<<"\t\t\t"<<a[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<"\t\t\t\t"<<r[i]<<"\n";
	}
	cout<<"\n\nAverage Waiting Time\t\t:\t"<<(aw/n);
	cout<<"\n\nAverage Turn Around Time\t:\t"<<(at/n)<<"\n";
	return 0;	
}
