#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
class sr
{
	public:
		int a[30],c[10],n,w,i,sw,rw,j;
		void input();
		void sender();
		//void sender2();
		void reciever();
};
void sr::input()
{
	
	cout<<"\nEnter Number of bit\t\t\t\t:\t";
	cin>>i;
	w=(pow(2,i))/2;
	cout<<"\nEnter Total Number of Frame You Want to Sent\t:\t";
	cin>>n;
	cout<<"\nWindow Size\t\t\t\t\t:\t"<<w;
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	j=sw=rw=0;
}
void sr::sender()
{
	if(j>0)
	{
		for(i=0;i<j;i++)
		{
			cout<<"\nSender : Frame "<<c[i]<<" is Sent\n";
			
		}
		for(i=0;i<j;i++)
		{
			sleep(1);
			cout<<"\nReciever : Frame "<<c[i]<<" is recieved correctly";
			cout<<"\nSender : Acknowledge has recieved\n";
		}
		j=0;
	}
	for(i=0;sw<n && i<w;i++)
			cout<<"\nSender : Frame "<<a[sw++]<<" is Sent\n";
	reciever();
}
void sr::reciever()
{
	if(rw<n)
	{
		for(i=0;i<w && rw<n;i++)
		{	
			srand(time(0));
			int k=rand()%10;
			if(k==1)
			{
				cout<<"\nReciever : Frame "<<a[rw++]<<" acknowledgement has been lost\n";
				cout<<"\nNegative Acknowledgement Generated\n\n";
				c[j++]=rw-1;
			}
			else if(k==2)
			{
				cout<<"\nReciever : Frame "<<a[rw++]<<" has been Lost\n";
				c[j++]=rw-1;
			}
			else
			{
				sleep(1);
				cout<<"\nReciever : Frame "<<a[rw++]<<" is recieved correctly";
				cout<<"\nSender : Acknowledge has recieved\n";
			}
		}
		if(j>0)
			sender();
	}
	else
		return;
	sender();
}
int main()
{
	system("clear");
	sr o;
	o.input();
	o.sender();
	cout<<"\nAll Frame Successfully Recieved!!!!!!!!!!!!!!\n";
	return 0;
}
