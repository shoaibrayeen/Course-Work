#include<bitstdc++.h>
#include<math.h>
using namespace std;
int c=0;
void smax(int a[],int k)
{
	int n=0;
	int l=a[1];
	int sl=0;
	for(int i=2;i<=k;i++)
    	{	n=a[i];
    		if (++c && n>l)
       		{	sl=l;
       		 	l=n;
		}
    		else
		{
       		 	if (++c && n>sl)
       			     sl= n;
		}
     	}
	cout<<"\n2nd Largest :  "<<sl;
}
int main()
{
	cout<<"\nEnter tournament : ";
	int k;
	cin>>k;
	int a[k];
	cout<<"\nEnter "<<k<<" Element\n";
	for(int j=1;j<=k;j++)
	cin>>a[j];
	cout<<"\nDisplay array\n";
	for(int i=1;i<=k;i++)
	cout<<a[i]<<" ";
	smax(a,k);
	cout<<"\nNumber of comparisons :  "<<c;
	cout<<endl;
	return 0;
}
