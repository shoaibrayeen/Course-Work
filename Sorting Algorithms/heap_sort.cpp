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
        
	int largest=i;
	int l=left(i);
	int r=right(i);
    	if(++c && (l<=hsize && a[l]>a[i]))
		largest=l;
	if (++c && (r<=hsize && a[r]>a[largest]))
		largest=r;
       	if(++c && largest!=i)
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
void heap(int a[])
{
	buildmaxheap(a);
	for(int i=hsize;i>1;i--)
	{
		int temp=a[i];
               	a[i]=a[1];
		a[1]=temp;
		hsize--;
		maxheap(a,1);
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
	heap(a);
	cout<<"\n Number of Comparisons : "<<c;
	cout<<"\n\n after sorting\n-----------------------------------------------------------\n";
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
