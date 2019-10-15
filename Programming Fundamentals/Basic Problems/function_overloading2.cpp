//Part 1 : 

#include <iostream>

void print(char const *str) { std::cout << str; }
void print(short num) { std::cout << num; }

int main() {
  print("abc");
  print(1);
  print('A');
}

// output : abc165

// Part 2 :

/*
#include <iostream>

void print(char const *str) { std::cout << str; }
void print(short num) { std::cout << num; }

int main() {
  print("abc");
  print(0);
  print('A');
}
*/

/*
Sneaky ambiguous function call.

The statement print(0); is ambiguous due to overload resolution rules. Both print functions are viable, but for the compiler to pick one, one of them has to have a better conversion sequence than the other. §13.3.3¶2: "If there is exactly one viable function that is a better function than all other viable functions, then it is the one selected by overload resolution; otherwise the call is ill-formed".

(a) Because 0 is a null pointer constant[1], it can be converted implicitly into any pointer type with a single conversion.

(b) Because 0 is of type int, it can be converted implicitly to a short with a single conversion too.

In our case, both are standard conversion sequences with a single conversion of "conversion rank". Since no function is better than the other, the call is ill-formed.

[1] §4.10¶1 A null pointer constant is an integral constant expression (5.19) prvalue of integer type that evaluates to zero(...) A null pointer constant can be converted to a pointer type.
*/
