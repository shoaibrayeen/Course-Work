#include<iostream>
using namespace std;
int c[10],b[20];
void csort(int a[],int n,int p)
{
	int l=9;
	for(int i=0;i<=l;i++)
		c[i]=0;
	for(int j=1;j<=n;j++)
		c[(a[j]%p)/(p/10)]+=1;
	for(int i=1;i<=l;i++)
		c[i]=c[i]+c[i-1];
	for(int j=n;j>0;j--)
	{
		b[c[(a[j]%p)/(p/10)]]=a[j];
		c[(a[j]%p)/(p/10)]--;
	}
	for(int i=1; i<=n; i++)
		a[i]=b[i];
}
void rsort(int a[], int n, int d)
{
	int p=1;
	for(int i=1; i<=d; i++)
	{
		p*=10;
		csort(a, n, p);
	}
}
int main()
{
	int k[20],n;
	cout<<"\n Enter Size : ";
	cin>>n;
	cout<<"\n Enter 3 digit elements \n";
	for(int j=1;j<=n;j++)
	cin>>k[j];
	rsort(k,n,3);
	cout<<"\n after sorting\n-----------------------------------------------------------\n";
	for(int i=1;i<=n;i++)
	cout<<k[i]<<" ";
	cout<<endl;
	return 0;
}
