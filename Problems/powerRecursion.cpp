#include <iostream>
using namespace std;

double pow ( double , int);

int main() {
    
    double base ;
    int power;
    cout << "\n Enter Base \t : \t " ;
    cin >> base;
    cout << "\n Enter Power \t : \t " ;
    cin >> power;
    cout << "\n Result is \t : \t " << pow(base,power) << "\n" ;
    return 0;
}

double pow  (   double base , int power )   {
    if  ( power   ==  0 ) {
         return 1;
    }
    else if ( power < 0 ) {
	
	return  ( 1 / base ) * pow ( base , power + 1 ) ;
    }
    else {
         return base * pow ( base , power - 1 ) ;
    }
}

