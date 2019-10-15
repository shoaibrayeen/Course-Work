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

node *T,*top,*temp;

class stack {
	public:
	/*
	objective : class definition for stack
	input parameter : None
	output parameter  : None
	approach :  using LL
	*/
		stack() {
			top = NULL ;
		}
		void push(int) ;
		void  pop() ;
		int isempty() ;
		void display() ;
};

void stack::push(int value) {
	/*
	objective : push function()
	input parameter : new value which has to inserted
	output parameter  : None
	approach :  using insertion at the beginning
	*/
	temp = new node ;
	temp->data = value ;
	temp->next = NULL ;
	temp->next = top ;
	top = temp ;
}
void stack::pop() {
	/*
	objective : pop()
	input parameter : None
	output parameter  : None
	approach :  using deletion at the beginning
	*/
	if(!isempty()) {
		T = top;
		cout << "\n Deleted Element  " << T->data ;
		if ( top->next == NULL ) {
			top = NULL ;
		}
		else {
			top = top->next ;
			delete T ;
		}
	}
	else {
		cout << "\n Stack is empty" ;
	}
}
int stack:: isempty() {
	/*
	objective : isempty()
	input parameter : None
	output parameter  : None
	approach :  comparing top with NULL
	*/
	if( top == NULL ) {
		return 1;
	}
	else {
		return 0;
	}
}
void stack::display() {
	/*
	objective : displaying stack
	input parameter : None
	output parameter  : None
	approach :  sequentially accessing ll from top to end of ll
	*/
	if ( top == NULL ) {
		return;
	}
  	cout << "\n Stack\n" ;
  	node *t = top ;
  	while( t != NULL ) { 
  		cout << t->data << "\n" ;
  		t = t->next ;
  	}
  	delete t ;
}

int main() {
	int choice,value;
	stack object;
	bool done = true;
	while(done) {
		cout << "\n\n\t\t Menu" ;
		cout << "\n 1. push" ;
		cout << "\n 2. pop" ;
		cout << "\n 3. Exit\n";
		cout << "\n Enter Your choice\t:\t";
		cin >> choice;
		switch ( choice ) {
			case 1 : cout << "\n Enter the value :" ;
			         cin >> value ;
				 object.push(value) ;
				 object.display() ;
			         break ;
			case 2 : object.pop() ;
			         object.display() ;
			         break ;
			case 3	: done = false;
				break;
			default : cout << "\n Invalid Choice \n " ;
				  break;
		}
	}
	return 0 ;
}
