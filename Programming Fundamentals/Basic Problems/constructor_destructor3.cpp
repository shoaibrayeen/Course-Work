#include <iostream>

class A {
public:
  A() { std::cout << "a"; }
  ~A() { std::cout << "A"; }
};

class B {
public:
  B() { std::cout << "b"; }
  ~B() { std::cout << "B"; }
};

class C {
public:
  C() { std::cout << "c"; }
  ~C() { std::cout << "C"; }
};

A a;

void foo() { static C c; }
int main() {
  B b;
  foo();
}


/* output : abcBCA
  "It is implementation-defined whether the dynamic initialization of a non-local variable with static storage 
  duration is done before the first statement of main. If the initialization is deferred to some point in time 
  after the first statement of main, it shall occur before the first odr-use (3.2) of any function or variable 
  defined in the same translation unit as the variable to be initialized."

  Since A() is not constexpr, the initialization of a is dynamic. There are two possibilities:
- a is initialized before main() is called, i.e. before b is initialized.
- a is not initialized before main(). It is however guaranteed to be initialized before the the use 
of any function defined in the same translation unit, i.e. before the constructor of b is called.

When execution reaches B b, it is initialized as normal. Static local variables are initialized 
the first time control passes through their declaration, so c is initialized next. As main() is exited, 
its local variable b goes out of scope, and is destroyed. Finally, 
all static variables are destroyed in reverse order of their initialization, first c, then a.

*/
