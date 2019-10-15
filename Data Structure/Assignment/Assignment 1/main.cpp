//
//  main.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include "q1.cpp"
#include "q2.cpp"
#include "q3.cpp"
#include "q4.cpp"
#include "q5.cpp"
#include "q6(i).cpp"
#include "q6(ii).cpp"
using namespace std;

class mainloop{
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : mainloop class for calling function of included files
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines functions which can be accessed publicly such as :-
                     1. q1() for calling function of q1.cpp
                     1. q2() for calling function of q2.cpp
                     1. q3() for calling function of q3.cpp
                     1. q4() for calling function of q4.cpp
                     1. q5() for calling function of q5.cpp
                     1. q6() for calling function of q6(i).cpp
                     1. q7() for calling function of q6(ii).cpp
                     1. display() for calling member functions
     ------------------------------------------------------------------------------------------------
     */
    public:
    void q1();
    void q2();
    void q3();
    void q4();
    void q5();
    void q6();
    void q7();
    void display();
};
void mainloop::q1() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q1.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q1.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    stack_grow obj;
    obj.main_q1();
}
void mainloop::q2() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q2.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q2.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    check_pair obj;
    obj.main_q2();
}

void mainloop::q3() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q3.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q3.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    sll obj;
    obj.main_q3();
}

void mainloop::q4() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q4.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q4.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    csll obj;
    obj.main_q4();
}

void mainloop::q5() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q5.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q5.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    csl obj;
    obj.main_q5();
}
void mainloop::q6() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q6(i).cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q6(i).cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    btree obj;
    obj.display();
}
void mainloop::q7() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q6(ii).cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q6(ii).cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    tree obj;
    obj.display();
}
void mainloop::display() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling member functions
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling member functions with while loop and switch cases
     ------------------------------------------------------------------------------------------------
     */
    bool done = true;
    while(done) {
        cout << "\n\n\n\t\t---------Main Menu--------------\n";
        cout << "\n1.Check Stack Grow\n2.Check Consecutive Pair\n3.Reverse Linked List in Pair\n4.Split Circular Linked List"
             << "\n5.Eliminate mth People\n6.Print Path\n7.Existence of Path\n8.Exit\n";
        char choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case '1' :    q1();
                break;
            case '2' :    q2();
                break;
            case '3' :    q3();
                break;
            case '4' :    q4();
                break;
            case '5' :    q5();
                break;
            case '6' :    q6();
                break;
            case '7' :    q7();
                break;
            case '8' :    done = false;
                break;
            default:    cout << "\nInvalid Input\n";
        }
    }
}


int main() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating object of this class and calling display()
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   by calling display() , the functions of included files are called.
     ------------------------------------------------------------------------------------------------
     */
    mainloop obj;
    obj.display();
    return 0;
}
