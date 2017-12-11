#include<iostream>
using namespace std ;

class queue {   
    int front , rear ;
    public:
        queue() {
    	      front = rear = -1 ;
        }
	  int array[10] ;
	  int enqueue( int ) ;
	  int dequeue() ;
	  void display() ;
};

int queue::enqueue(int value) {
	if( front == ( rear + 1 ) % 10 ) {
	    cout << "\nIt's acted as circular queue." ;
  }
  rear = ( rear + 1 ) % 10 ;
  array[rear] = value ;
  if( front == -1 ) {
	    front = ( front + 1 ) % 10 ;
	}
}
int queue::dequeue() {
	if( ( front == -1 )  &&  ( rear == -1 ) ) {
	    cout << "\n Queue is Empty. " ;
  }
	else {
		  cout << "\n Element Deleted : "<< array[front] << "\n" ;
		  front = ( front + 1 ) % 10 ;
	}
}

void queue::display() {
	if( front == ( rear + 1 ) % 10 ) {
	    cout << "\nIt's acted as circular queue." ;
  }
	else {
	    int i = front ;
	    if( front == -1 ) {
	        cout << "\nQueue is Empty. " ;
      }
	    else {
		      for( i = front ; i != rear ; i = (i+1) % 10 ) {
		          cout << " " << array[i] << " " ;
           }
		       cout << array[i]  ;
	    }	
	}
}

int main()
{
	queue object ;
	int choice, value ;
	while(1) {
		cout << "\n\n\t\tMENU" ;
		cout << "\n 1. Enqueue" ;
		cout << "\n 2. Dequeue" ;
		cout << "\n Enter your choice : " ;
		cin >> choice ;
		switch( choice ) {
		    case 1  : cout << "\n enter the element : " ;
	                cin >> value ;
			            object.enqueue( value ) ;
			            object.display() ;
			            break ;
			  case 2  : object.dequeue() ;
			            object.display() ;
			            break ;
			  default : exit(0) ;
		}
	}
	return 0 ;
}
