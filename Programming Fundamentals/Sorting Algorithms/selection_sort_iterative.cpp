#include <iostream>
using namespace std ;

class sort {
	private :
		int array[10] , number ;
	public :
		sort() ;
		void input() ;
		void display() ; 
		void selection() ;
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

void sort :: selection() {
	for ( int i = 0 ; i < number - 1 ; ++i ) {
		int min = i ;
		for ( int j = i+1 ; j < number ; ++j ) {
			if ( array[min] > array[j] ) {
				min = j ;
			} 
		}
		if ( min != i ) {
			int local = array[i] ;
			array[i] = array[min] ;
			array[min] = local ;
		}
		cout << "\nIterations\t\t:\t" ;
		display();
	}
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
	object.selection() ;
	cout << "\nSorted Elements \t:\t" ;
	object.display() ;
	return 0;
}
