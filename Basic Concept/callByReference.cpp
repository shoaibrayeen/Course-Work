#include<iostream>
using namespace std;

int returnMin(int &,int &);

int main(){
	int num1, num2;
	int res;
	cout << "\n Enter first value\t:\t" ;
	cin >> num1 ;
	cout << "\n Enter second value\t:\t" ;
	cin >> num2 ;
	cout << "\n The Minimum of two\t:\t" << returnMin( num1, num2) << endl ;
	return 0;
}

int returnMin( int &num1, int &num2){
	if ( num1 < num2 ){
  		return num1;
	}
	else {
  		return num2;
	}
}
