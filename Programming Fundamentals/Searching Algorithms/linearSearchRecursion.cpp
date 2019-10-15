#include <iostream>
using namespace std ;

class search {
	private :
		int array[100] , number ;
	public :
		search() ;
		void input() ;
		void display() ; 
		int linearSearch(int , int) ;
};

search :: search () {
	for ( int i = 0 ; i < 100 ; ++i ) {
		array[i] = 0;
	}
	number = 0 ;
}

void search :: input() {
	cout << "\nEnter number of elemnets\t:\t" ;
	cin >> number ;
	cout << "\nEnter Elements\n" ;
	for ( int i = 0 ; i < number ; ++i ) {
		cout << "\nEnter " << ( i + 1 ) << " element\t:\t" ;
		cin >> array[i] ;
		cout << endl ;
	}
}

int search :: linearSearch(int element,int i = 0) {
	if( array[i] == element ) {
		return (i + 1);
	}
	else  if ( i >= number ) {
		return -1;
	}
	else {
		return linearSearch( element , ++i ) ;
	}
}

void search :: display() {
	for ( int i = 0 ; i < number ; ++i ) {
		cout << array[i] <<"\t" ;
	}
	cout << endl ;
}

int main() {
	search object;
	object.input() ;
	cout << "\nEntered Elements\t:\t" ;
	object.display() ;
	int element ;
	cout << "\nEnter the elemnt which you want to search\t:\t" ;
	cin >> element ;
	int res = object.linearSearch( element ) ;
	if ( res == -1 ) {
		cout << "\nElement " << element << " is not found.\n " ;
	}
	else {
		cout << "\nElement " << element << " found at " << res << " position.\n" ;
	}
 	return 0;
}
