#include<iostream>
#include<math.h>
using namespace std;
int left(int i)
{
	return i*2;
}
int right(int i)
{
	return (i*2 + 1);
}
int hsize;
int c=0;
void maxheap(int a[],int i)
{
        
	int largest;
	int l=left(i);
	int r=right(i);
    	if(l<=hsize && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if (r<=hsize && a[r]>a[largest])
		largest=r;
       	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
	        
                maxheap(a,largest);
        }
}
void buildmaxheap(int a[])
{
	for(int i=(hsize/2);i>0;i--)
        {
		maxheap(a,i);
        }
}
int main()
{
	int a[10],n;
	cout<<"\n enter size : ";
	cin>>n;
	hsize=n;
	cout<<"\n enter elements\n";
	for(int i=1;i<=n;i++)
	cin>>a[i];
	buildmaxheap(a);
	cout<<"\nLargest is : "<<a[1];
	cout<<"\nSecond Largest is : "<<a[2]; 
	cout<<endl;
	return 0;
}
