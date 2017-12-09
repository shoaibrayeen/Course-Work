#include<iostream>
using namespace std;
void csort(int a[],int b[],int n, int k)
{
        int *c = new int[k+1];

	int i,j;
	for(i=0;i<=k;i++)
		c[i]=0;
	for(j=1;j<=n;j++)
		c[a[j]]+=1;
	for(i=1;i<=k;i++)
		c[i]+=c[i-1];
	for(j=n;j>0;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]--;
	}

        delete[] c;
}
int main()
{
	int k[20],b[20],n, max;
	cout<<"\n Enter Size : ";
	cin>>n;
        cout<<"\n Enter maximum value : "; 
        cin>>max;
	cout<<"\n Enter elements (Max "<<max<<")\n";
	for(int j=1;j<=n;j++)
	cin>>k[j];
	cout<<"\n before sorting\n-----------------------------------------------------------\n";
	for(int i=1;i<=n;i++)
	cout<<k[i]<<" ";
	cout<<endl;
	csort(k,b,n, max);
	cout<<"\n after sorting\n-----------------------------------------------------------\n";
	for(int i=1;i<=n;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
