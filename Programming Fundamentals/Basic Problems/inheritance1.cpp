#include<iostream>

using namespace std;
class Base {
	public:
   		void f() {
      			cout << "Base\n";
   		}
};

class Derived:public Base {
	public:
   	void f() {
      		cout << "Derived\n";
   	}
};

main() { 
   Derived obj; 
   obj.Base::f();
}


/*
  output : Base
  
  The method f() inherited from Base is referred using :: operator.
 

*/
