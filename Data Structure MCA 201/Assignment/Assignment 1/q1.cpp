//
//  q1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
class stack_grow {
    public:
    bool check_external();
    bool check_internal();
    void main_q1();
};
bool stack_grow :: check_external() {
    stack<int> s;
    s.push(3);
    s.push(2);
    int *add1 = &s.top();
    s.pop();
    int *add2 = &s.top();
    cout << add1<<"\t"<< add2;
    if( add1 > add2 ) {
        return true;
    }
    return false;
}
bool stack_grow :: check_internal() {
    int a = 5;
    int b = 6;
    //int *add1 = &a;
    //int *add2 = &b;
    cout << &a <<"\t"<< &b;
    if( &a < &b ) {
        return true;
    }
    return false;
}
void stack_grow :: main_q1() {
    cout << "\n--------Checking Internal & External Stack---------\n";
    if( check_external()) {
        cout << "\nExternal Stack is growing up.\n";
    }
    else {
        cout << "\nExternal Stack is growing down.\n";
    }
    if( check_internal()) {
        cout << "\nInternal Stack is growing up.\n";
    }
    else {
        cout << "\nInternal Stack is growing down.\n";
    }
}

