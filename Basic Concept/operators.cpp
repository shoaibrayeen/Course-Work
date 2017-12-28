#include <iostream>
using namespace std ;

int main() {
	int a = 8 ;
	int b = 5 ;
	int c =10 ;
	cout << "\n----------------------Arithmetic Operators---------------------------" ;
	cout << "\nAddition of a & b\t:\t" << a + b ;
	cout << "\nSubtraction of a & b\t:\t" << a - b ;
	cout << "\nMultiplication of a & b\t:\t" << a * b ;
	cout << "\nDivision of a & b\t:\t" << a / b ;
	cout << "\nModulus of a & b\t:\t" << a % b ;
	
	cout << "\nPreIncremnet of a\t:\t" << ++a ;
	cout << "\nPreIncremnet of b\t:\t" << ++b ;
	cout << "\nPostIncremnet of a\t:\t" << a++ ;
	cout << "\nPostIncremnet of b\t:\t" << b++ ;

	cout << "\nPreDecremnet of a\t:\t" << --a ;
	cout << "\nPreDecremnet of b\t:\t" << --b ;
	cout << "\nPostDecremnet of a\t:\t" << a-- ;
	cout << "\nPostDecremnet of b\t:\t" << b-- ;

	cout << "\n=========================Bitwise Operators============================" ;
	cout << "\nAND of a & b\t\t:\t" << ( a & b ) ;
	cout << "\nOR of a & b\t\t:\t" << ( a | b ) ;
	cout << "\nXOR of a & b\t\t:\t" << ( a ^ b ) ;
	cout << "\nNOT of a \t\t:\t" << ( ~a) ;
	cout << "\nNOT of b\t\t:\t" << ( ~b ) ;
	cout << "\nXOR of a & b\t\t:\t" << ( a ^ b ) ;
	cout << "\nLeft Shift a\t\t:\t" << ( a << 1 )  ;
	cout << "\nRight Shift a\t\t:\t" << ( a >> 1 )  ;
	cout << "\nLeft Shift b\t\t:\t" << ( b << 1 )  ;
	cout << "\nRight Shift b\t\t:\t" << ( b >> 1 )  ;
	
	cout << "\n------------------------Assignment Operators ( with a & c variables )---------------------------" ;
	c = a ;
	cout << "\nValue of c :: = operator\t:\t" << c ;
	c += a ;
	cout << "\nValue of c :: += operator\t:\t" << c ;
	c -= a ;
	cout << "\nValue of c :: -= operator\t:\t" << c ;
	c *= a ;
	cout << "\nValue of c :: *= operator\t:\t" << c ;
	c /= a ;
	cout << "\nValue of c :: /= operator\t:\t" << c ;
	c = 10 ;
	c %= a ;
	cout << "\nValue of c :: %= operator\t:\t" << c ;
	c <<= a ;
	cout << "\nValue of c :: <<= operator\t:\t" << c ;
	c >>= a ;
	cout << "\nValue of c :: >>= operator\t:\t" << c ;
	c &= a ;
	cout << "\nValue of c :: &= operator\t:\t" << c ;
	c |= a ;
	cout << "\nValue of c :: |= operator\t:\t" << c ;
	c ^= a ;
	cout << "\nValue of c :: ^= operator\t:\t" << c ;
	cout << endl;
	return 0;
}
