#include <iostream>

struct A {
  A() { std::cout << "A"; }
};
struct B {
  B() { std::cout << "B"; }
};

class C {
public:
  C() : a(), b() {}

private:
  B b;
  A a;
};

int main()
{
    C();
}
/*
	output : BA
	The initialization order of member variables is determined by their order of declaration, not their order in the initialization list.
*/
