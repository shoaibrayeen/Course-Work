#include <iostream>
using namespace std;

void counter() {
    static int count = 0;
    cout << count++ << "\t";
}

int main() {
    for(int i = 0; i < 5; i++) {
        counter();
    }
    return 0;
}

//Output
/*
  0	1	2	3	4
*/
