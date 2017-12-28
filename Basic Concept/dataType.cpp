#include <iostream>
using namespace std ;

int main() {
	char charTest1;
	unsigned char  charTest2;
	signed char charTest3;
	int intTest1;
	unsigned int intTest2;
	signed int intTest3;
	short int intTest4;
	unsigned short int intTest5;
 	signed short int intTest6;
	long int intTest7;
	signed long int intTest8;
	unsigned long int intTest9;
	float floatTest;
	double doubleTest1;
	long double doubleTest2;
	wchar_t wcharTest;
	bool boolTest;

	cout << "\n Size of char\t\t\t:\t" << sizeof(char);
	cout << "\n Size of unsigned char\t\t:\t" << sizeof(unsigned char);
	cout << "\n Size of signed char\t\t:\t" << sizeof(signed char);
	cout << "\n Size of unsigned int\t\t:\t" << sizeof(unsigned int);
	cout << "\n Size of signed int\t\t:\t" << sizeof(signed int);
	cout << "\n Size of short int\t\t:\t" << sizeof(short int);
	cout << "\n Size of unsigned short int\t:\t" << sizeof(unsigned short int);
	cout << "\n Size of signed short int\t:\t" << sizeof(signed short int);
	cout << "\n Size of long\t\t\t:\t" << sizeof(long int);
	cout << "\n Size of unsigned long int\t:\t" << sizeof(unsigned long int);
	cout << "\n Size of signed long int\t:\t" << sizeof(signed long int);
	cout << "\n Size of float\t\t\t:\t" << sizeof(float);
	cout << "\n Size of double\t\t\t:\t" << sizeof(double);
	cout << "\n Size of long double\t\t:\t" << sizeof(long double);
	cout << "\n Size of wchar_t\t\t:\t" << sizeof(wchar_t);
	cout << "\n Size of bool\t\t\t:\t" << sizeof(bool) << endl;

	return 0;
}
