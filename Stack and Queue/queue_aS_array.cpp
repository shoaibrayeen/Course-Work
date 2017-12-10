#include<iostream>
using namespace std ;

class queue {   
    int front , rear ;
    public:
    	queue() {
    	    front=rear=-1;
    	}
	int array[20] ;
	int enqueue( int ) ;
	int dequeue() ;
	void display() ;
};

int queue::enqueue(int value) {
	if( front == ( rear + 1 ) % 20 ) {
	        cout << "\nNow it's circular queue " ;
		front = ( rear + 1 ) % 20 ;
	}
	else {
		rear++;
		if( front == -1 ) {
	    		front++ ;
			array[rear] = value ;
		}
		else {
			array[rear]=value;
		
		}
	}	
}

int queue::dequeue() {
	if( ( front == -1 )  &&  ( rear == -1) ) {
		cout << "\n Queue is Empty :" ;
	}
	else {
		cout << "\n Element Deleted : " << array[front++] << "\n" ; 
	}
}

void queue::display() {
	if( ( front == ( rear + 1 ) % 20 ) ) {
		cout << "\nQueue is full " ;
	}
	else {
		if( front == -1 ) {
			cout << "\nQueue is Empty." ;
		}
		else {
			for( int i = front ; i <= rear ; i++ ) {
				cout<<" "<<array[i]<<" ";
			}
		}	
	}
}
int main() {
	queue object ;
	int choice , value ;
	while( 1 ) {
		cout << "\n\n\t\tMENU" ;
		cout << "\n 1. Enqueue" ;
		cout << "\n 2. Dequeue" ;
		cout << "\n Enter your choice :" ;
		cin >> choice ;
		switch( choice ) {
			case 1 : cout << "\n enter the element : " ;
	               		 cin>>value ;
				 object.enqueue(value) ; 
				 object.display() ;
				 break ;

			case 2 : object.dequeue() ;
			         object.display() ;
			         break ;

			default : exit ( 0 ) ;
		}
	}
	return 0 ;
}
