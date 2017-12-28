#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	int b[10],a[10],p[10],wt[10],tat[10],r[10],i,j,ft[10],tm;
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
		r[i]=tm-a[i];
		tm+=b[i];
		ft[i]=tm;
		tat[i]=ft[i]-a[i];
		wt[i]=tat[i]-b[i];
		at+=tat[i];
		aw+=wt[i];

	}
	system("clear");
	cout<<"\nDisplay Details of Processes\n\n";
	cout<<"\nProcess\t\tBurst Time\t\tArrival Time\t\tWaiting Time\t\tTurn Arraound Time\t\tResponse Time\n";
	for(i=0;i<n;i++)
	{
		cout<<"P"<<p[i]<<"\t\t\t"<<b[i]<<"\t\t\t"<<a[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<"\t\t\t\t"<<r[i]<<"\n";
	}
	cout<<"\n\nAverage Waiting Time\t\t:\t"<<(aw/n);
	cout<<"\n\nAverage Turn Around Time\t:\t"<<(at/n)<<"\n";
	return 0;	
}
