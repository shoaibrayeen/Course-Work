#include<iostream>
using namespace std;

int i = 5 ;
int main() {
	cout << "\nNested Loops\n";

	//Accessing Global Variable
	cout << "\n Value of i (Global)\t:\t" << ::i << "\n";
	cout << "-----------------------------------------------------------------------------------------";
	for( i = 0 ; i < 3 ; ++i ) {
		cout << "\n Value of i (Outside)\t:\t" << i <<"\n";
		for( int i = 0 ; i < 5 ; ++i ) {
			cout << "\n Value of i (Inside)\t:\t" << i;
		}
		cout << endl;
	}
	// The i within 1st for loop has to declare again for executing both loop 15 times.

	/* 
		If inside i is not redeclared , then ouside i will not run 2nd time 
		because after becoming the value of inside i to 5 when the pointer returns to outside loop 
		then the value of outside i intializes to 5 which breaks the boundary condition of outside for loop.
	
	*/
	return 0;
}
