#include <iostream>
 
using namespace std;
 
int main () {
   // declare simple variables
   int    i;
   double d;
 
   // declare reference variables
   int&    r = i;
   double& s = d;
	
   int *ip1;
   double *ip2;
   ip1 = &r;
   ip2 = &s;
   
   i = 100;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
   cout << "Value of i pointer : " << *ip1  << endl;
 
   d = 110.78;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
   cout << "Value of d pointer : " << *ip2  << endl;
   
   return 0;
}
