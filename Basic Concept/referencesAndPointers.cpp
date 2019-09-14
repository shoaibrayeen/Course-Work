#include <iostream>
using namespace std;

int main () {
    // declare simple variables
    int i = 15;
    double d = 9.2002;
    
    // declare reference variables
    int& r = i;
    double& s = d;
    
    // declare Pointer Variables and assign them to references
    int *ip1;
    double *ip2;
    ip1 = &r;
    ip2 = &s;
    
    cout << "Value of i\t\t\t\t:\t" << i << endl;
    cout << "Value of i reference\t:\t" << r  << endl;
    cout << "Value of i pointer\t\t:\t" << *ip1  << endl;
    cout << "Value of d\t\t\t\t:\t" << d << endl;
    cout << "Value of d reference\t:\t" << s  << endl;
    cout << "Value of d pointer\t\t:\t" << *ip2  << endl;
    
    return 0;
}

// Output
/*
Value of i		:	15
Value of i reference	:	15
Value of i pointer	:	15
Value of d		:	9.2002
Value of d reference	:	9.2002
Value of d pointer	:	9.2002
*/
