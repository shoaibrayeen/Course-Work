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
    
    /*
        ------------------------------------------------------------------------------------------------
     
        objective : creating a class for checking the growth of internal and external stack
     
        ------------------------------------------------------------------------------------------------
        input parameter : none
     
        ------------------------------------------------------------------------------------------------
     
        output parameter : none
     
        ------------------------------------------------------------------------------------------------
     
        description :   stack_grow class defines functions to check stacks
     
        ------------------------------------------------------------------------------------------------
     
        approach    :   class defines three functions which can be accessed publicly such as :-
                        check_external() which checks external stacks.
                        check_internal() which checks internal stacks.
                        main_q1() which calls member functions.
     
        ------------------------------------------------------------------------------------------------
     */
    
    public:
    bool check_external();
    bool check_internal();
    void main_q1();
};


bool stack_grow :: check_external() {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : checking external stack grows up or down.
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : "true" if stack grows up otherwise "false"
     
     ------------------------------------------------------------------------------------------------
     
     description :   check_external() accesses external stacks to compare addresses
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  Two elements are pushed into stack and then compared their respective addresses.
     
     ------------------------------------------------------------------------------------------------
     */
    stack<int> s;
    s.push(3);
    s.push(2);
    int *add1 = &s.top();
    s.pop();
    int *add2 = &s.top();
    if( add1 > add2 ) {
        return true;
    }
    return false;
}


bool stack_grow :: check_internal() {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : checking internal stack grows up or down.
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : "true" if stack grows up otherwise "false"
     
     ------------------------------------------------------------------------------------------------
     
     description :   check_internal() accesses internal stacks to compare addresses
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  Two elements are initialized by some value and then compared their addresses
                    If address of 1st element is less than the address of 2nd element , then
                    stack grows up otherwise stack grows down.
     
     ------------------------------------------------------------------------------------------------
     */
    int a = 5;
    int b = 6;
    if( &a < &b ) {
        return true;
    }
    return false;
}


void stack_grow :: main_q1() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : to call member functions
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     description :   calling member functions and displaying messages respectively
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling member functions one by one. If functions are true , it displays that stack 
                     grows up otherwise it displays that stack grows down.
     
     ------------------------------------------------------------------------------------------------
     */
    
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

