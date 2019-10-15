#include <iostream>

void f(int) { std::cout << "i"; }
void f(double) { std::cout << "d"; }
void f(float) { std::cout << "f"; }

int main() {
  f(1.0);
  return 0;
}

/*output : d
  "The type of a floating literal is double unless explicitly specified by a suffix."
The best overload is therefore void f(double).

*/
