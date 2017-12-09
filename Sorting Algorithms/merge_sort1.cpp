#include<iostream>
#include<math.h>
using namespace std;
int c=0;

void merge(int a[],int p,int q,int r)
{
	int i,j,k,b[20];
	i=p;
	j=q+1;
	k=p;
	while(i<= q && j<=r)
	{
		c++;
		if(a[i]<a[j])
			b[k++]=a[i++];
		else if(a[i]>a[j])
			b[k++]=a[j++];
		else if(a[i]==a[j])
		{
			b[k++]=a[i++];
			b[k++]=a[j++];
		}
	}
	while(i<=q)
		b[k++]=a[i++];
	while(j<=r)
		b[k++]=a[j++];
	for(i=p;i<k;i++)
		a[i]=b[i];
}
void msort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		msort(a,p,q);
		msort(a,q+1,r);
		merge(a,p,q,r);
	}	
	return;
}

int main()
{
	int a[10],n;
	cout<<"\n Enter size : ";
	cin>>n;
	cout<<"\n Enter Elements\n";
	for(int i=0;i<n;i++)
	cin>>a[i];


	msort(a,0,n-1);

	cout<<"\n Number of Comparisons : "<<c;
	cout<<"\n After Sorting \n----------------------------------------------------------\n";


	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
