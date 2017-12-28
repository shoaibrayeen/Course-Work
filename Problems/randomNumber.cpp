#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
 
int main () {
   int i,j;
 
   // set the seed
   int a , b , number;
   srand( (unsigned)time( NULL ) );
   cout << "\nGenerate numbers in this interval [a,b]" ;
   cout << "\nEnter a for Interval\t:\t" ;
   cin >> a;
   cout << "\nEnter b for Interval\t:\t" ;
   cin >> b;	
   cout << "\nHow many Random Numbers You want\t:\t" ;
   cin >> number;
   /* generate 10  random numbers. */
   for( i = 0; i < number; i++ ) {
      // generate actual random number
      j = a + rand()%(b-a);
      cout <<" Random Number from a till b : " << j << endl;
   }

   return 0;
}
