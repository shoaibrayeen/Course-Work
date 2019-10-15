
// pointer pointing to a function
#include <iostream>
using namespace std;
int addition (int a, int b) {
	return (a+b); 
}
int subtraction (int a, int b) { 
	return (a-b); 
}
int operation (int x, int y, int (*functocall)(int,int)) {
	int g;
	g = (*functocall)(x,y);
	return (g);
}

int main () {
	int m,n;
	int (*minus)(int,int) = subtraction;
	m = operation (7, 5, addition);
	cout << "\nAfter Addition\t\t:\t" << m;
	n = operation (20, m, minus);
	cout << "\nAfter Substraction\t:\t" << n <<endl;
	return 0;
}
