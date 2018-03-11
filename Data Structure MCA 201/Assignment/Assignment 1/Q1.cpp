//
//  stack_grow.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 10/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(3);
    s.push(2);
    int *add1 = &s.top();
    s.pop();
    int *add2 = &s.top();
    cout << add1<<"\t"<< add2;
    if( add1 > add2 ) {
        cout << "\nStack is growing up.\n";
    }
    else {
        cout << "\nStack is growing down.\n";
    }
    return 0;
}
