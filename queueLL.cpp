#include<iostream>
using namespace std;

int isempty();

struct node 
	int data;
	node *next;
};

node *front,*rear,*temp;

class queue {
	public:
		queue() {
			front = NULL ;
			rear = NULL ;
		}
		void enqueue( int ) ;
		int dequeue() ;
		void display() ;
};

void queue::enqueue(int value) {
	temp = new node ;
	temp->data = value ;
	if( ( front == rear ) && ( front == NULL ) ) {
		front = temp ;
	}
	else {
		rear->next = temp ;
	}
		rear = temp ;
}
int queue::dequeue() {
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
    }
    else {
    	cout << "\n queue is empty  " ;
    }
}

void queue::display() {
  	if( ( front == NULL )  &&  ( rear == NULL ) ) {
  	    cout<<"\n Queue is empty ";
    }
  	else {
  	     cout << "\n  " ;
  	     temp = front ;
  	     cout << temp->data << "->" ;
  	     temp = temp->next ;
  	     if( front != rear) {
  	          while(temp != front) { 
  		              cout << temp->data << "->" ;
  		              temp = temp->next ;
    	         }
         }
   	}
 }
 
int isempty() {
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
	while(1) {
		cout << "\n\n\t\t Menu" ;
		cout << "\n 1. Enqueue" ;
		cout << "\n 2. Dequeue\n" ;
		cin >> choice;
		switch(choice) {
			case 1 : cout << "\n Enter the value :" ;
			         cin >> value ;
				       object.enqueue( value ) ;
				       object.display() ;
			         break ;
			case 2 : object.dequeue() ;
			         object.display() ;
			         break ;
			default: return 0 ;
		}
	}
	return 0;
} 
