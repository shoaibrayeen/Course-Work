#include<iostream>
using namespace std;



struct node {
	/*
	objective : strcuture for node;
	input parameter : None
	output parameter  : None
	*/
	int data;
	node *next;
};

node *front,*rear,*temp;

class queue {
	public:
	/*
	objective : class definition for queue
	input parameter : None
	output parameter  : None
	approach :  using LL
	*/
		queue() {
			front = NULL ;
			rear = NULL ;
		}
		void enqueue( int ) ;
		void dequeue() ;
		bool isempty();
		void display() ;
};

void queue::enqueue(int value) {
	/*
	objective : enqueue function()
	input parameter : new value which has to inserted
	output parameter  : None
	approach :  using insertion at the end and updating front and rear
	*/
	temp = new node ;
	temp->data = value;
	temp->next = NULL;
	if( ( front == rear ) && ( front == NULL ) ) {
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp ;
	rear = temp ;
	display() ;
}
void queue::dequeue() {
	/*
	objective : dequeue function
	input parameter : None
	output parameter  : None
	approach :  using deletion at the beginning
	*/
	if( !isempty() ){
		node *temp1 = front ;
		cout << "\n Deleted Element :" << front->data ;
	        if( front == rear )	{
		              front = NULL ;
		              rear = NULL ;
	        }
	        else {
		              front = front->next ;
		              delete temp1;
	        }
		display() ;
    }
    else {
    	cout << "\n queue is empty  " ;
    }
}

void queue::display() {
	/*
	objective : displaying queue
	input parameter : None
	output parameter  : None
	approach :  sequentially accessing ll from front to rear
	*/
  	if( ( front == NULL )  &&  ( rear == NULL ) ) {
  	    cout<<"\n Queue is empty ";
        }
  	else {
  	     cout << "\n  " ;
  	     temp = front ;
  	     while(temp != rear) { 
  		cout << temp->data << "->" ;
  		temp = temp->next ;
    	     }
		cout << temp->data;
   	}
 }
 
bool queue::isempty() {
	/*
	objective : isempty()
	input parameter : None
	output parameter  : None
	approach :  comparing front and rear with NULL
	*/
	if( ( front == NULL )  &&  ( rear == NULL ) ) {
	    return 1 ;
        }
	else {
	    return 0 ;
        }
}

int main() {
	int choice , value ;
	queue object ;
	bool done = true;
	while(done) {
		cout << "\n\n\t\t Menu" ;
		cout << "\n 1. Enqueue" ;
		cout << "\n 2. Dequeue" ;
		cout << "\n 3. Exit\n";
		cout << "\n Enter Your choice\t:\t";
		cin >> choice;
		switch(choice) {
			case 1 : cout << "\n Enter the value :" ;
			         cin >> value ;
				 object.enqueue( value ) ;
			         break ;
			case 2 : object.dequeue() ;
			         break ;
			case 3	: done = false;
				break;
			default : cout << "\n Invalid Choice \n " ;
				  break;
		}
	}
	return 0;
}
