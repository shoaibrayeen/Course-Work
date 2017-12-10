#include<iostream>
using namespace std ;

class stack {
    public:
		    int array[50];
		    int top;
		    stack() {
			      top = -1 ;
		    }
		    void push( int ) ;
		    int pop() ;
        void display() ;
};

void stack::push( int value ) {
	top++ ;
	array[top] = value ;
}

int stack::pop() {
	if( top != -1 ) {
	    int value = array[top] ;
		  top-- ;
		  return value ;
	}
  cout << "\nStack is Empty.\n" ;
}


void stack::display() {
  	cout << "\n Data After operation  " ;
  	for( int i = top ; i >= 0 ; --i ) {
        cout << array[i] << "  " ;
    }
}

int main() {
	int choice,value;
	stack object;
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
			  default: cout << "\n Invalid Choice \n " ;
				         exit(0) ;
		}
	}
	return 0 ;
}
