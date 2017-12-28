#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	system("clear");
	cout<<"\n\nDistance Vector Routing\n\n";
	int i,j,n,e,m;
	cout<<"\nNumber of Total Routers\t\t\t:\t";
	cin>>n; 
	cout<<"\nNumber of Adjecent Router from New Router\t:\t";
	cin>>m;
	int a[n+2][m];
	cout<<"\nEnter The New Router Number (1-n)\t:\t";	
	cin>>e;
	for(i=1;i<=m;i++)
	{
		cout<<"\nEnter Adjecent Router Number\t:\t";
		cin>>a[n+1][i];
		cout<<"\nEnter Delay From Router "<<e<<"\t:\t";
		cin>>a[0][i];
	}
	for(j=1;j<=m;j++)
	{
		cout<<"\nFor Router "<<a[n+1][j];
		for(i=1;i<=n;i++)
		{
			cout<<"\ndistance "<<i<<"\t:\t";
			cin>>a[i][j];
		}
	}
	system("clear");
	cout<<"\nDisplay Adjecency Matrix\n";
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){cout<<a[i][j]<<"\t";}cout<<endl;}
	cout<<"\n\n\n***************Distance From New Router********************\n\n";
	int min;
	cout<<"\nDistance\t\tLine\n";
	for(i=1;i<=n;i++)
	{
		min=a[0][1]+a[i][1];
		for(j=1;j<=m;j++)
		{	
			if(min > (a[0][j]+a[i][j]))
			{
				min=a[0][j]+a[i][j];
			}
		}
		if(e==i)
			cout<<0<<endl;
		else
			cout<<min<<endl;
	}
	cout<<endl;
	return 0;
			
}
