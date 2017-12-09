
#include<iostream>
#include<cstdlib>
using namespace std;
#define swap(x,y)   {int t=x;x=y;y=t;}
int c=0;
int part(int a[],int p,int r)
{
	int i=rand()%(r-p) + p;
	swap(a[i],a[r]);
	int x=a[r];
	int k=p-1;
	for(int j=p;j<r;j++)
	{
		c++;
		if(a[j]<=x)
		{
			k++;
			swap(a[k],a[j]);
		}
	}
	swap(a[k+1],a[r]);
	return k+1;
}
void qsort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=part(a,p,r);
		qsort(a,p,q-1);
		qsort(a,q+1,r);
	}	
}


int main()
{
	int a[10],n;
	cout<<"\n Enter size : ";
	cin>>n;
	cout<<"\n Enter Elements\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	qsort(a,0,n-1);
	cout<<"\n Number of Comparisons : "<<c;
	cout<<"\n After Sorting \n----------------------------------------------------------\n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
