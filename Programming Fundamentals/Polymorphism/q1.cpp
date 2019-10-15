// C++ program for function overloading
 
#include <bits/stdc++.h>
using namespace std;
class TRY {
    public:
     
    // function with 1 int parameter
    void func(int x) {
        cout << "value of x is " << x << endl;
    }
     
    // function with same name but 1 double parameter
    void func(double x) {
        cout << "value of x is " << x << endl;
    }
     
    // function with same name and 2 int parameters
    void func(int x, int y) {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};
 
int main() {
     
    TRY obj1;
     
    // Which function is called will depend on the parameters passed
    // The first 'func' is called 
    obj1.func(7);
     
    // The second 'func' is called
    obj1.func(9.132);
     
    // The third 'func' is called
    obj1.func(85,64);
    return 0;
} 
