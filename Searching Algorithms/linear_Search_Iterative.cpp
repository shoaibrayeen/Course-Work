#include <iostream>
using namespace std ;

class sort {
	private :
		int array[10] , number ;
	public :
		sort() ;
		void input() ;
		void display() ; 
		void linearSearch(int) ;
};

sort :: sort () {
	for ( int i = 0 ; i < 10 ; ++i )
		array[i] = 0;
	number = 0 ;
}

void sort :: input() {
	cout << "\nEnter number of elemnets\t:\t" ;
	cin >> number ;
	cout << "\nEnter Elements\n" ;
	for ( int i = 0 ; i < number ; ++i ) {
		cout << "\nEnter " << ( i + 1 ) << " element\t:\t" ;
		cin >> array[i] ;
		cout << endl ;
	}
}

void sort :: linearSearch(int element) {
	for ( int i = 0 ; i < number ; ++i ) {
		if ( element == array[i] ) {
			cout << "\nElement " << element << " found at " << ( i + 1 ) << " position \n" ;
			return ;
		}
	}
	cout << "\nElement " << element << " is not found " ;
	cout << endl ;
}

void sort :: display() {
	for ( int i = 0 ; i < number ; ++i ) {
		cout << array[i] <<"\t" ;
	}
	cout << endl ;
}

int main() {
	sort object;
	object.input() ;
	cout << "\nEntered Elements\t:\t" ;
	object.display() ;
	int element ;
	cout << "\nEnter the elemnt which you want to search\t:\t" ;
	cin >> element ;
	object.linearSearch(element) ;
	return 0;
}
