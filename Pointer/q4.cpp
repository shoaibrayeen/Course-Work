//Accessing an array by an array of pointer
#include <iostream>
using namespace std;
const int MAX = 3;
int main () {
	int var[MAX] = {10, 100, 200};
	int *ptr[MAX];
	for (int i = 0; i < MAX; i++) {
		ptr[i] = &var[i]; // assign the address of integer.
	}
	for (int i = 0; i < MAX; i++) {
		cout << "Value of var[" << i << "] = ";
		cout << *ptr[i] << endl;
	}
	return 0;
}
