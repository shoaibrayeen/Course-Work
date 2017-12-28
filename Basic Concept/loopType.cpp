#include <iostream>
using namespace std;

int main(){
	int i ;
	int endCount = 5 ; 
	for ( i = 0 ; i < endCount ; ++i ) {
		cout << "\nFor Loop :: i = " << i+1 ;
	}
	cout << endl ;

	goto doWhile ;

	whileLoop : i = 0 ;
	cout << endl ;
	while ( i < endCount ){
		cout << "\nWhile Loop :: i = " << i+1 ; 
		++i;
	}	
	cout << endl ;
	
	goto exit ;

	doWhile : i = 0 ;

	do{
		cout << "\nDo While Loop :: i = " << i+1 ;
		++i;
		
	}while ( i < endCount );
	goto whileLoop ;
	exit : return 0;	
}
