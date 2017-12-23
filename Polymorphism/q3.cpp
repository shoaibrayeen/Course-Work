// C++ program for function overriding
 
#include <bits/stdc++.h>
using namespace std;
// Base class
class Parent {
    public:
    	void print() {
        	cout << "The Parent print function was called" << endl;
    	}
};
 
// Derived class
class Child : public Parent {
    public: 
    // definition of a member function already present in Parent
    	void print() {
        	cout << "The child print function was called" << endl;
    	}  
};
 
//main function
int main()  {
    //object of parent class
    Parent obj1;
  //object of child class
    Child obj2 = Child();
	// obj1 will call the print function in Parent
    obj1.print();
    // obj2 will override the print function in Parent
    // and call the print function in Child
    obj2.print();
    return 0;
} 
