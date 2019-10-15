#include <iostream>
using namespace std;


// first name space

namespace first_space {
	void func() {
		cout << "Inside first space" << endl;
	}
	
	// second name space
	namespace second_space {
		void func() {
			cout << "Inside second space" << endl;
		}
	}
}

using namespace first_space::second_space;

int main () {
	// This calls function from second name space.
	func();
	return 0;
}
