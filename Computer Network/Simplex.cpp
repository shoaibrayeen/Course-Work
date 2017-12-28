#include<iostream>
using namespace std;
//typedef enum{data,ack,nack} frame_kind;
//typedef unsigned int seq_nr;
typedef enum{frame_arrival,none} event_type;
int flag = 0 ;
event_type event;
struct packet
{
	char data[30];
};
struct frame
{
	packet info;
	//seq_nr seq;
	//frame_kind kind;
	//seq_nr ack_nr;
};

frame *pldata ;

void from_NL(packet *p)
{
	cout<<"Enter the information you want to send:\n";
	cin>>p->data;
}

void To_PL( frame *s)
{
	pldata = s ;
}

void from_PL(frame *r)
{
	r=pldata;
}
void To_NL(frame *p)
{
	cout<<"Information Received:\t"<<p->info.data;	
	cout<<endl;	
}

void wait_for_event()
{
	if(flag==1)
		event=frame_arrival;
}
void sender1()
{
	frame s;
	packet buffer;
	from_NL(&buffer);
	s.info=buffer;

	To_PL(&s);
	flag=1;
}
void receiver1()
{
	frame r;
	wait_for_event();
	if(event==frame_arrival)
	{
		from_PL(&r);
		To_NL(&r);
	}
	else
		cout<<"Error\n";
}

int main()
{
	char ch;
	do
	{
		sender1();
		receiver1();
		cout<<"Would you like to continue..?\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
return 0;
}
