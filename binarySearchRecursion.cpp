#include <iostream>
using namespace std ;

class sort {
	private :
		int array[10] ;
	public :
		int number ;
		sort() ;
		void input() ;
		void display() ; 
		void binarySearch( int , int , int ) ;
};

sort :: sort () {
	for ( int i = 0 ; i < 10 ; ++i )
		array[i] = 0;
	number = 0 ;
}

void sort :: input() {
	cout << "\nEnter number of elemnets\t:\t" ;
	cin >> number ;
	cout << "\nEnter Elements in Increasing order\n" ;
	for ( int i = 0 ; i < number ; ++i ) {
		cout << "\nEnter " << ( i + 1 ) << " element\t:\t" ;
		cin >> array[i] ;
		cout << endl ;
	}
}

void sort :: binarySearch(int element,int high ,int low=0 ) {
	if ( low > high ) {
		cout << "\nElement " << element << " is not found.\n " ;
		return ;
	}
	int mid = ( low + high ) / 2 ;
	if( array[mid] == element ) {
		cout << "\nElement " << element << " found at " << ( mid + 1 ) << " position.\n" ;
		return ;
	}
	else if ( array[mid] > element ) {
		binarySearch( element , mid - 1 , low  ) ;
	}
	else if ( array[mid] < element ) {
		binarySearch( element , high , mid + 1 ) ;
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
	int element ;
	cout << "\nEnter the elemnt which you want to search\t:\t" ;
	cin >> element ;
	object.binarySearch( element , object.number - 1 ) ;
	return 0;
}
