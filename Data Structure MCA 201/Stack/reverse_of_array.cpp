#include<iostream>
#include<stack>
using namespace std;

int main() {
	/*
		objective : to reverse a sequence of numbers
		input paramter:
			size : size of sequence
		return value : reverse of the sequence of numbers
		approach : using stack
	*/
	int size;
	stack<int> object;
	cout << " Enter size of list\t:\t";
	cin >> size;
	int temp;
	for ( int i=0 ; i < size ; ++i) {
		cin >> temp;
		object.push(temp);
	}
	cout << "\n Reversing.....\n";
	while(!object.empty()) {
		cout << object.top()<<"\t";
		object.pop();
	}
	cout << endl;
	return 0;
}
