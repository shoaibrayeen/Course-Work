#include<iostream>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10],u;
 
main()
{
	int m,c,l;
	cout <<"enter no of vertices : ";
	cin >> n;
	cout <<"ente no of edges : ";
	cin >> m;
	cout <<"\nEDGES Cost\n";
	for(k=1;k<=m;k++)
	{
		cout<<"\nEnter source : ";
		cin>>i;
		cout<<"\nEnter Destination : ";
		cin>>j;
		cout<<"\nEnter Weight : ";
		cin>>c;
		cost[i][j]=c;
		cost[j][i]=c;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		if(cost[i][j]==0)
		cost[i][j]=31999;
 
	cout <<"\nORDER OF VISITED VERTICES\n";
	k=1;
	while(k<n)
	{
		l=31999;
		if(k==1)
		{
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
				if(cost[i][j]<l)
				{
					l=cost[i][j];
					u=i;
				}
		}
		else
		{
			for(j=n;j>=1;j--)
			if(cost[v][j]<l && visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				stk[top]=j;
				top++;
				l=cost[v][j];
				u=j;
			}
		}
		cost[v][u]=31999;
		v=u;
		cout<<v << " ";
		k++;
		visit[v]=0; visited[v]=1;
	}
	cout<<endl;
	return 0;
}
