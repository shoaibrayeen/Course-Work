#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
void reciever(int *);
int n,w,sw=0,rw=0;
void sender(int *a)
{	
	for(int i=0;i<w;i++)
	{
		if(sw<n)
		{
			cout<<"\nSender : Frame "<<a[sw]<<" is sent";
			sw++;
		}
		else{break;}
	}
	sleep(1);
	reciever(a);
}
void reciever(int *a)
{
	for(int i=0;i<w;i++)
	{
		if(rw<n)
		{
			srand(time(0));
			int k=rand()%10;
			if(k==1)
			{
				cout<<"\nReciever : Frame "<<a[rw]<<" has been Lost\n";
				sw=rw;
				sender(a);break;
			}
			else if(k==2)
			{
				cout<<"\nReciever : Frame "<<a[rw]<<" acknowledgement has been lost and All After this Lost\n";
				sw=rw;
				sender(a);break;
			}
			else
			{
				sleep(1);
				cout<<"\nReciever : Frame "<<a[rw]<<" is recieved correctly";
				sleep(1);
				cout<<"\nSender : Acknowledge has recieved\n";
				rw++;
			}
		}
		else
		{
			cout<<"\nAll Frames has been Recieved Successfully!!!!!!!!!!!!!\n";	exit(0);
		}
	}
	sender(a);
}
int main()
{
	system("clear");
	cout<<"\nEnter Number of Frames\t\t:\t";	
	cin>>n;
	cout<<"\nEnter Number of Bit for Window\t:\t";
	cin>>w;
	w=pow(2,w)-1;
	cout<<"\nWindow size\t\t:\t"<<w;
	int a[n];
	for(int i=0;i<n;i++)
		a[i]=i;
	sender(a);
	cout<<endl;
	return 0;
}
