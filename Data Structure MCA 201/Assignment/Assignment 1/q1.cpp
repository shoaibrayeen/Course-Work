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
     
     objective : creating a class for checking the growth of stack
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines two functions which can be accessed publicly such as :-
                     check_stack() which checks external stacks.
                     main_q1() which calls check_stack().
     
     ------------------------------------------------------------------------------------------------
     */
    
public:
    bool check_stack();
    void main_q1();
};



bool stack_grow :: check_stack() {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : checking stack grows up or down.
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : "true" if stack grows up otherwise "false"
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  The function performs following operations :-
                    1. initializing two elements with constants
                    2. comparing the addresses of variables and returning true/false accordingly
     
     ------------------------------------------------------------------------------------------------
     */
    int a , b ;
    cout << "\nAddress of 1st Variable\t:\t" << &a;
    cout << "\nAddress of 2nd Variable\t:\t" << &b;
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
     
     approach    :   This function calls member functions.
     
     ------------------------------------------------------------------------------------------------
     */
    if( check_stack()) {
        cout << "\n\nStack is growing up.\n";
    }
    else {
        cout << "\n\nStack is growing down.\n";
    }
}

