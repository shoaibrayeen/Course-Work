#include <iostream>
#include <stdlib.h>
using namespace std;

enum alphabet {
	A=2,
	B,
	C,
	D=100,
	E,
	F
};

int main()
{
	alphabet alphaTest;
	alphaTest=A ;
	cout << "\nValue of A\t\t:\t" << alphaTest ;
	alphaTest=B ;
	cout << "\nValue of B\t\t:\t" << alphaTest ;
	alphaTest=C ;
	cout << "\nValue of C\t\t:\t" << alphaTest ;
	alphaTest=D ;
	cout << "\nValue of D\t\t:\t" << alphaTest ;
	alphaTest=E ;
	cout << "\nValue of E\t\t:\t" << alphaTest ;
	alphaTest=F ;
	cout << "\nValue of F\t\t:\t" << alphaTest ;
	cout << endl ;
	return 0;
}
