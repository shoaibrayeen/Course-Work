#include <iostream>
using namespace std ;

int main() {
    cout << "\n Size of bool\t\t\t\t\t:\t" << sizeof(bool);
    cout << "\n Size of char\t\t\t\t\t:\t" << sizeof(char);
    cout << "\n Size of unsigned char\t\t\t:\t" << sizeof(unsigned char);
    cout << "\n Size of signed char\t\t\t:\t" << sizeof(signed char);
    
    cout << "\n Size of wchar_t\t\t\t\t:\t" << sizeof(wchar_t);
    
    cout << "\n Size of short int\t\t\t\t:\t" << sizeof(short int);
    cout << "\n Size of unsigned short int\t\t:\t" << sizeof(unsigned short int);
    cout << "\n Size of signed short int\t\t:\t" << sizeof(signed short int);
    
    cout << "\n Size of int\t\t\t\t\t:\t" << sizeof(int);
    cout << "\n Size of unsigned int\t\t\t:\t" << sizeof(unsigned int);
    cout << "\n Size of signed int\t\t\t\t:\t" << sizeof(signed int);
    
    cout << "\n Size of float\t\t\t\t\t:\t" << sizeof(float);
    
    cout << "\n Size of long\t\t\t\t\t:\t" << sizeof(long int);
    cout << "\n Size of unsigned long int\t\t:\t" << sizeof(unsigned long int);
    cout << "\n Size of signed long int\t\t:\t" << sizeof(signed long int);
    
    
    cout << "\n Size of signed long long int\t:\t" << sizeof(signed long long int);
    cout << "\n Size of unsigned long long int\t:\t" << sizeof(unsigned long long int);
    cout << "\n Size of long long int\t\t\t:\t" << sizeof(long long int);
    
    cout << "\n Size of double\t\t\t\t\t:\t" << sizeof(double);
    cout << "\n Size of long double\t\t\t:\t" << sizeof(long double);
    cout << endl << endl;
    return 0;
}


// Output
/*
	
 Size of bool					:	1
 Size of char					:	1
 Size of unsigned char				:	1
 Size of signed char				:	1
 Size of wchar_t				:	4
 Size of short int				:	2
 Size of unsigned short int			:	2
 Size of signed short int			:	2
 Size of int					:	4
 Size of unsigned int				:	4
 Size of signed int				:	4
 Size of float					:	4
 Size of long					:	8
 Size of unsigned long int			:	8
 Size of signed long int			:	8
 Size of signed long long int			:	8
 Size of unsigned long long int			:	8
 Size of long long int				:	8
 Size of double					:	8
 Size of long double				:	16
 
*/
