#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define Max 10
int n;
using namespace std;

int r=0;

int receiver(int seq)
{
	srand(time(0));
	sleep(2);
    int x=rand()%Max;			//x=0 for correct frame   x=1 for lost frame     else for lost ack
    if(x==1)
    {      
        cout<<"\n\t\tFrame lost!! Resending.......\n";
        return -1;
    }
    else if(x==2)
    {
    	cout<<"\n\n\t\tTimeout!!!";
        cout<<"\n\t\tAcknowledgement lost!! Resending......\n";
        return -1;   
    }
    else 
    {
        cout<<"\nReceived frame with sequence no :: "<<seq<<endl;
	cout<<"\nAcknowledgement has been received\n";
        r=(r+1)%Max;
        return r;
    }
}

void sender()
{
     int seq=1;
     cout<<"\n*****Sender*******\n";
     cout<<"\nEnter the number of frames :: ";
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
     {
                   arr[i]=i%Max;
      }
     
     for(int i=0;i<n;i++)
     {
     	    cout<<"\nSending frame with sequence number "<<arr[i]<<" .\n";
            int ack=receiver(arr[i]);
		if(ack==-1)
                 i--;
     }
     cout<<"\nSent All Frames Succesfully!\n";
}

int main()
{
	system("clear");
    sender();
    return 1;
}
