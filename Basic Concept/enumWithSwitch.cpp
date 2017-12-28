#include <iostream>
#include <stdlib.h>
using namespace std;

enum alphabet {
	A=1,
	B,
	C,
	D,
	E,
	F
};

int main()
{
	int choice;
	cout << "\nEnter your choice\t:\t" ;
	cin >> choice ;
	alphabet alphaTest;
	switch ( choice )
	{
		case A : alphaTest = A;
			cout << "\nValue of A\t\t:\t" << alphaTest;
		case B : alphaTest = B;
			 cout << "\nValue of B\t\t:\t" << alphaTest;
		case C : alphaTest = C;
			 cout << "\nValue of C\t\t:\t" << alphaTest;
		case D : alphaTest = D;
			 cout << "\nValue of D\t\t:\t" << alphaTest;
		case E : alphaTest = E;
			 cout << "\nValue of E\t\t:\t" << alphaTest;
		case F : alphaTest = F;
			 cout << "\nValue of F\t\t:\t" << alphaTest;
 			 break;
		default : cout << "\nWrong Choice\n";
			  exit(0);
	}
	cout << endl;
	return 0;
}
