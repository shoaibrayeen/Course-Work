#include <iostream>

using namespace std;

// Time Complexity :  O(n)

/*
	Objective : This program reverses the element of an array.
	input parameter of function sum():
		n : size of array
		array : contains element of array
	return value to main(): reverse of array
*/

int * reverse(int * , int );

int main() {
	int n;
	cout << "\nEnter Size of Array\t:\t";
	cin >> n;
	cout << endl;
	int * result;
	int* array= new int[n];
	for ( int i = 0; i < n ; ++i ) {
		cout << "Enter " << i + 1 << " element\t\t:\t";
		cin >> array[i];
	}
	result = reverse(array , n );
	for ( int i = 0; i < n ; ++i ) {
		cout << "\n" << i + 1 << " element\t\t:\t" << result[i];
	}
	cout << endl;
	delete[] array;
	return 0;
}

int *reverse( int * array , int n ) {
	int j = n-1;
	int temp;
	for ( int i = 0; i < n/2; ++i ) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		--j;
	}
	return array;
}
