#include<iostream>
using namespace std;

int isempty() ;

struct node {
	int data;
	node *next;
};

node *T,*top,*temp;

class stack {
	public:
		stack() {
			top = NULL ;
		}
		void push(int) ;
		int  pop() ;
		void display() ;
};

void stack::push(int value) {
	temp = new node ;
	temp->data = value ;
	temp->next = NULL ;
	temp->next = top ;
	top = temp ;
}
int stack::pop() {
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
int isempty() {
	if( top == NULL ) {
		return 1;
	}
	else {
		return 0;
	}
}
void stack::display() {
  	cout << "\n Data After operation  " ;
  	node *t = top ;
  	while( t != NULL ) { 
  		cout << t->data << "\n" ;
  		t = t->next ;
  	}
  	delete t ;
}

int main() {
	int choice,value;
	stack o;
	while(1) {
		cout << "\n\n\t\t Menu" ;
		cout << "\n 1. push" ;
		cout << "\n 2. pop\n" ;
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
			default : cout << "\n Invalid Choice \n " ;
		}
	}
	return 0;
}
