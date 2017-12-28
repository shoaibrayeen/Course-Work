#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std ;

int flag = 2;

typedef enum{frame_arr , ackno , error} event_type ;
event_type event;

struct packet
{
  char info[5] ;
};
struct frame
{
  packet data ;
  int seqno ;
  int ackno ;
};

frame *plData = new frame;

void from_NL(packet *buff)
{
  cout<<"\n****************************************\n";
  cout<<"\nEnter data : ";
  cin>>buff -> info;
  
}

void to_PL(frame *s)
{
   plData = s ;
}

void from_PL(frame *r)
{
  r = plData ;
}

void to_NL(frame *r)
{
  cout<<"\nData is : ";
  cout<<r -> data.info<<" " ;
}

void wait_for_event()
{
  if(flag == 1)
  {
    event = frame_arr;
    cout<<"\nFrame has been received..!\n";
  }
  else if(flag == 2)
  {
    event = ackno ;
    cout<<"\nAcknowledgement has been received..!\n";
    cout<<"\n****************************************\n";
  }
  else
  {
    event = error ;
    cout<<"\nError during passing frame/acknowledgement..!\n";
  }
}

void sender()
{
  frame s ;
  packet buffer ;
  wait_for_event();
  if(event == ackno)
  {
    from_NL(&buffer);
    s.data = buffer ;
    to_PL(&s);
    flag = 1 ;
  }
}

void receiver()
{
  frame r ;
  wait_for_event();
  if(event == frame_arr)
  {
    from_PL(&r);
    to_NL(&r);
    flag = 2 ;		//ackno = frame received.
  }
}

int main()
{
  int packs ;
  cout<<"\nEnter the number of packets : ";
  cin>>packs;
  for(int i = 0 ; i < packs ; i++ )
  {
    sender();
    receiver();
    cout<<endl ;
  }
  cout<<endl ;
  return 0 ;
}
