#include<iostream>
#include<stdlib.h>
#include<time.h> 
#include<sys/unistd.h>
#include<string.h>

using namespace std;

time_t beg,after,second;
int frame_expected=0;

struct Packet	
{
	string data;
};
	
typedef enum{data} frame_kind;
typedef enum {frame_arrival,ack,timeout,error} event_type;
	
struct Frame
{
	Packet info;
	int seq_nr;
	frame_kind kind;
	int ack;
};
	
bool isframeatphysical=false;
bool iserror=false;
int  no_of_frame_sent=0;
bool isackreceived=false;
    
	
void wait_for_event_for_ack(event_type &event)
{
	if(isackreceived)
		event=ack;
	else
		event=timeout; 	       
}
	
void wait_for_event_for_frame(event_type &event)
{
	int r=rand()%2,r1=rand()%3;
	if(r==0)
		sleep(3);	

	after=time(NULL);
	second=difftime(after,beg);
	if(second>=2)
	{	event=timeout;	
		cout<<"\ntimeout\n";
		cout<<"\nResend Started\n";
	}

	else if(isframeatphysical)
	{
		if(r1==0)
		{	
			event=error;
			cout<<"\nChecksum Error \n";
			cout<<"\nResend Started \n";
		}
		else
		{		
		event=frame_arrival;
		}
	}
}
	
void from_NL(Packet &buffer)
{	
	cout<<"Enter the data\n";
	cin>>buffer.data;
}
	
Frame pl_data;
	
void to_PL(Frame &s)
{	
	pl_data=s;
	isframeatphysical=true;
}
	
void To_PL(Frame &s)
{
	pl_data=s;
	isackreceived=true;
}
	
	
void from_PL(Frame &r)
{
	if(isframeatphysical)
		r=pl_data;
}
	
void to_NL(Packet &r)
{
        cout<<"Received Data is \n";
	cout<<r.data<<"\n";  	
}

void Receiver()
{
	Frame r;
	Frame s;
	event_type event;
		
	wait_for_event_for_frame(event);
	
	if(event==frame_arrival)
	{
	
		from_PL(r);
				
		if(r.seq_nr==frame_expected)		
		{	
			
			cout<<"\nMessage Received with frame no :"<<frame_expected<<"\n";
			to_NL(r.info);
			frame_expected=1-frame_expected;
		}
		s.ack=1-frame_expected;
		To_PL(s);
	}

}
	
void Sender()
{
	Frame s;
	Packet buffer;
	event_type event; 
	int next_frame_to_send=0;
	char ch;

	from_NL(buffer);
		
	while(true)
	{

		s.info=buffer;
		s.seq_nr=next_frame_to_send;
		to_PL(s);
		
		beg=time(NULL);
		cout<<"\nSending frame with frame no : "<<next_frame_to_send<<"\n";
		
		Receiver();
		
		wait_for_event_for_ack(event);

		if(event==ack)
		{
			from_PL(s);

			if(s.ack==next_frame_to_send)
			{	
				cout<<"\nAcknowledgement Received of Frame no : "<<next_frame_to_send<<"\n";
				cout<<"\n\nWant to Send more (Y or y for yes) \n";				
				cin>>ch;
				if(ch=='y'||ch=='Y')
				{			
					from_NL(buffer);
					next_frame_to_send=1-next_frame_to_send;
				}
				else
					exit(0);		
			}

		}
	}
	
}
	
	
int main()
{
	char ch;
	srand(time(NULL));	

	while(true)
	{
		Sender();
	}		   
}
