#include <iostream>
using namespace std ;

class search {
	private :
		int *array ;
	public :
		int number ;
		search() ;
		void input() ;
		void display() ; 
		int binarySearch( int ) ;
};

search :: search () {
	array = new int[100];
	for ( int i = 0 ; i < 100 ; ++i ) {
		array[i] = 0;
	}
	number = 0 ;
}

void search :: input() {
	cout << "\nEnter number of elemnets\t:\t" ;
	cin >> number ;
	cout << "\nEnter Elements in Increasing order\n" ;
	for ( int i = 0 ; i < number ; ++i ) {
		cout << "\nEnter " << ( i + 1 ) << " element\t:\t" ;
		cin >> array[i] ;
		cout << endl ;
	}
}

int search :: binarySearch(int element ) {
	int low = 0 ;
	int high = number - 1 ;
	while ( low <= high ) {
		int mid = ( low + high ) / 2 ;
		if( array[mid] == element ) {
			return ( mid + 1 );
		}
		else if ( array[mid] > element ) {
			high = mid - 1 ;
		}
		else if ( array[mid] < element ) {
			low = mid + 1 ;
		}
	}
	return -1;
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
	int res = object.binarySearch( element ) ;
	if ( res == -1 ) {
		cout << "\nElement " << element << " is not found.\n " ;
	}
	else {
		cout << "\nElement " << element << " found at " << res << " position.\n" ;
	}
	return 0;
}
