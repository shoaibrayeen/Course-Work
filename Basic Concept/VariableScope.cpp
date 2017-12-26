#include <iostream>
using namespace std;
int g = 50;
 
int main () {
	int g = 100;
 	cout << "\nGlobal Value\t:\t" << ::g;
	cout << "\nLocal Value\t:\t" << g << endl;
   	return 0;
}
