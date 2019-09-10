#include <iostream>
using namespace std;

int main() {
   short int i;           // a signed short integer
   short unsigned int j;  // an unsigned short integer

   j = 50000;

   i = j;
   cout << "\nSigned Short Int\t:\t" << i;
   cout << "\nunsigned Short Int\t:\t" << j;
   cout << endl;

   return 0;
}
// Difference between signed and unsigned data types
/*
Signed Short Int	   :	-15536
unsigned Short Int	:	50000
*/
