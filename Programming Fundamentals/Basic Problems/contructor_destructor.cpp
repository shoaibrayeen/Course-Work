#include <iostream>

class A {
	public:
  	A() { 
		std::cout << "a"; 
	}
  	~A() { 
		std::cout << "A";
 	}
};

class B {
	public:
  	B() { 
		std::cout << "b"; 
	}
  	~B() { 
		std::cout << "B"; 
	}
};

class C {
	public:
  	C() { 
		std::cout << "c"; 
	}
  	~C() { 
		std::cout << "C"; 
	}
};

A a;
int main() {
  	C c;
  	B b;
}

/*
  output : acbBCA
  
  "It is implementation-defined whether the dynamic initialization of a non-local variable with static storage duration is done before the first statement of main. If the initialization is deferred to some point in time after the first statement of main, it shall occur before the first odr-use (3.2) of any function or variable defined in the same translation unit as the variable to be initialized."

Since A() is not constexpr, the initialization of a is dynamic. There are two possibilities:
- a is initialized before main() is called, i.e. before b or c are initialized.
- a is not initialized before main(). It is however guaranteed to be initialized before the the use of any function defined in the same translation unit, i.e. before the constructors of b and c are called.

Then, b and c are initialized in order.

Before main() exits, b and c are destructed in the reverse order of their construction. Then, when main() returns, a is destructed as per §3.6.3 in the standard:
"Destructors for initialized objects (...) with static storage duration are called as a result of returning from main."
