#include <iostream>
using namespace std ;

void function1();
void function2();
 
static int count = 10;
 
int main() {
   while(count--) {
      function1();
   }
   cout << "\n\n" ;
   int count = 10;
   while(count--) {
      function2();
      cout << " & Local count is " << count << endl;
   }
   return 0;
}

void function1() {
   static int i = 5; // static Int
   i++;
   cout << "i is " << i ;
   cout << " & Global count is " << count << endl;
}

void function2() {
   int j = 5;	// j updates to 5 every time when function2() calls.
   j++;
   cout << "j is " << j ;
}
