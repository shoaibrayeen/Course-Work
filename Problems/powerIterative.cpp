#include <iostream>
using namespace std;

void pow ( double , int);

int main() {
    
    double base ;
    int power;
    cout << "\n Enter Base \t : \t " ;
    cin >> base;
    if ( base == 0 ) {
	cout << "\n Base can't be zero. \n" ;
   	return 0;
    }
    cout << "\n Enter Power \t : \t " ;
    cin >> power;
    pow ( base , power ) ;
    return 0;
}

void pow  (   double base , int power ) {
    double temp = 1;
    bool flag = false ;
    if ( power < 0 ) {
 	flag = true;
	power += ( -1 ) * ( 2 ) * power ; 
    }
    for ( int i = power ; i > 0 ; --i ) {
        temp *= base  ;
    
    }
    if ( flag == true ) {
   	temp = 1 / temp ;
    }
    cout << "\n Result is \t : \t " << temp  << "\n";   
}

