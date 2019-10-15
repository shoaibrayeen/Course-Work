#include <iostream>

using namespace std;

class A {
public:
  A() { cout << "a"; }
  ~A() { cout << "A"; }
};

int i = 1;

int main() {
label:
  A a;
  if (i--)
    goto label;
}

/* Output : aAaA
The Standard says this about jump statements:

Transfer [...] back past an initialized variable with automatic storage duration involves 
the destruction of variables with automatic storage duration that are in scope at the point 
transferred from but not at the point transferred to.

*/
