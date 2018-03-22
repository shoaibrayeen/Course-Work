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
    stack_grow obj;
    obj.main_q1();
}
void mainloop::q2() {
    check_pair obj;
    obj.main_q2();
}

void mainloop::q3() {
    sll obj;
    obj.main_q3();
}

void mainloop::q4() {
    csll obj;
    obj.main_q4();
}

void mainloop::q5() {
    csl obj;
    obj.main_q5();
}
void mainloop::q6() {
    btree obj;
    obj.display();
}
void mainloop::q7() {
    tree obj;
    obj.display();
}
void mainloop::display() {
    while(1) {
        cout << "\n\n\n\t\t---------Main Menu--------------\n";
        cout << "\n1.Check Stack Grow\n2.Check Consecutive Pair\n3.Reverse Linked List in Pair\n4.Split Circular Linked List\n5.Eliminate mth People\n6.Print Path\n7.Existence of Path\n8.Exit\n";
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
            case '8' :    exit(0);
                break;
            default:    cout << "\nInvalid Input\n";
        }
    }
}


int main() {
    mainloop obj;
    obj.display();
    return 0;
}
