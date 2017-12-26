#include<iostream>
#include<stdlib.h>
using namespace std;
#define inf 999
void dij(int n,int v,int w[10][10],int *d)
{	
	int f[10],u,count,min,i,j;
	for(i=1;i<=n;i++)
	  f[i]=0,d[i]=w[v][i];
 	count=2;
 	while(count<=n)
	{
  		min=99;
  		for(j=1;j<=n;j++)
   			if(d[j]<min && !f[j])
    				min=d[j],u=j;
  		f[u]=1;
  		count++;
  		for(j=1;j<=n;j++)
   			if((d[u]+w[u][j]<d[j]) && !f[j])
    					d[j]=d[u]+w[u][j];
 	}
}
int main()
{
	system("clear");
	int n,i,v,j;
	cout<<"\nEnter Number of Nodes\t:\t";	
	cin>>n;
	int w[10][10],d[10];
	cout<<"\nEnter the Weighted Matrix\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i<j){	cin>>w[i][j]; w[j][i]=w[i][j];}
			else if(i==j){w[i][j]=inf;}}
	cout<<"\nWeighted Matrix\n";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){if(i==j){cout<<"0   ";}else {cout<<w[i][j]<<"   ";}}cout<<endl;}
	cout<<"\n\nEnter the Source Vertex\t:\t";
	cin>>v;
	dij(n,v,w,d);
	cout<<"\n Shortest path:\n";
 	for(i=1;i<=n;i++)
  		if(i!=v)
   			cout<<v<<"->"<<i<<"\t:\t"<<d[i]<<"\n";
	return 0;
}
