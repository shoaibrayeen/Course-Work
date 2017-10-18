#include<iostream>
using namespace std ;

class queue {
	public:
		class node {
		    public:
				    int data ;
				    node * next ;
				    node() {
					      next = NULL ;
				    }
		};
    
		node *top , *temp , *t ;
    queue() {
			top = temp = t = NULL ;
		}
		void push( int ) ;
		void move2() ;
		int pop() ;
	  void display() ;
	  void move1() ;
} object1 , object2 , object3 ;

void queue::push( int value ) {
	temp = new node ;
	temp->data = value ;
	temp->next = NULL ;
	if( top == NULL ) {
	    top = temp ;
  }
	else {
		  temp->next = top ;
	    top = temp ;
	}
}

int queue::pop() {
	if( top == NULL ) {
	    cout << "\n Queue is Empty " ;
  }
	else {
		t = top ;
		int d = t->data ;
		if( top->next == NULL ) {
			top = NULL ;
		}
		else {
			top = top->next ; 
			delete t ;
		}
		return d ;
	}
}

void queue :: move1() {
	 int value;
	 while( object1.top != NULL ) {
	    value = object1.pop() ;
		  object2.push( value ) ;
	 }
}

void queue::move2() {
	int value;
	while(object2.top!=NULL) {
		  value = object2.pop() ;
		  object1.push( value ) ;
	}
}

void queue::display() { 
	t = object2.top ;
	if( object2.top == NULL ) {
		  cout << "\n Queue is empty " ;
		  return ;
	}
	while( t->next != NULL) {
		  cout << t->data << "->" ;
		  t = t->next ;
	}
	cout << t->data ;
}

int main() {
	int value , choice ;
	while(1) {
		cout << "\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n" ;
		cin >> choice ;
		switch( choice ) {
			case 1 : cout << "\n Enter the element " ;
			         cin >> value ;
			         object1.push( value ) ;
					     break ;
			case 2 : object1.move1() ;
			         object2.pop() ;
			         object1.move2() ;
			         break ;
			case 3 : object1.move1() ;
			         object3.display() ;
			         object1.move2() ;
			         break ;
			case 4 : exit(0) ;
			         break ;
			default :cout << "\n Wrong choice " ;
		}
	}
	return 0 ;
}
