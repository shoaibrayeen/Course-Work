#include<iostream>
#include<string.h>
using namespace std ;

void myrev(char* array) {
      char temp ;
      int i = strlen(array) ;
      i-- ;
      int j = 0 ;
      while( j <= i ) {
             temp = array[j] ;
             array[j++] = array[i] ;
             array[i--] = temp ;
      }
      cout << "\nReverse of string is : " << array ;
}
int main() {
	char array[30] ;
	cout << "\n Enter String : " ;
	gets( array ) ;
	myrev( array ) ;
	return 0 ; 
}
