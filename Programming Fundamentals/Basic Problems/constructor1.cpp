#include <iostream>
using namespace std;

class C {
public:
  explicit C(int) {
    std::cout << "i";
  };
  C(double) {
    std::cout << "d";
  };
};

int main() {
  C c1(7);
  C c2 = 7;
}



/* output : id
	These are two examples of initialization. The first form, C c1(7), is called direct-initialization, the second, C c2 = 7, is called copy-initialization. In most cases they are equivalent, but in this example they are not, since the int constructor is explicit.
  "An explicit constructor constructs objects just like non-explicit constructors, but does so only where the direct-initialization syntax (8.5) or where casts (5.2.9, 5.4) are explicitly used."

And how is direct-initialization defined?

"The initialization that occurs in the forms
T x(a);
T x{a};
(...) is called direct-initialization."

So the int constructor is not even considered for initialization in the second case. Instead, a standard conversion sequence is used to convert the integer literal to a double, and the double constructor (the only candidate) is used.

*/
