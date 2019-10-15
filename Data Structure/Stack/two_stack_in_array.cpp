//
//  two_stack_in_array.cpp
//  Problems
//
//  Created by Mohd Shoaib Rayeen on 20/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXSIZE 20

class twoStacks {
    int *arr;
    int size;
    int top1, top2;
    public:
    twoStacks();
    void push1(int);
    void push2(int);
    void pop1();
    void pop2();
    void display1();
    void display2();
    
};

twoStacks::twoStacks() {
    size = MAXSIZE;
    arr = new int[MAXSIZE];
    top1 = -1;
    top2 = size;
}

void twoStacks :: push1(int x) {
    if (top1 < top2 - 1) {
        top1++;
        arr[top1] = x;
    }
    else {
        cout << "\nStack2 is full.\n";
        return;
    }
}

void twoStacks:: pop1() {
    if (top1 >= 0 ) {
        int x = arr[top1];
        top1--;
        cout << "\nPopped Element\n" << x;
    }
    else {
        cout << "\nStack1 is Empty.\n";
    }
}

void twoStacks:: push2(int x) {
    if (top1 < top2 - 1) {
        top2--;
        arr[top2] = x;
    }
    else {
        cout << "\nStack2 is full\n.";
        return;
    }
}

void twoStacks:: pop2() {
    if (top2 < size) {
        int x = arr[top2];
        top2++;
        cout << "\nPopped Element\n" << x;
    }
    else {
        cout << "\nStack2 is Empty.\n";
    }
}

void twoStacks::display1() {
    if( top1 == -1 ) {
        cout << "\nStack is Empty\n";
        return;
    }
    cout << "\n\nStack 1\n";
    for ( int i = 0; i <= top1; ++i ) {
        cout << arr[i] << "\t";
    }
}
void twoStacks::display2() {
    if( top2 == size ) {
        cout << "\nStack is Empty\n";
        return;
    }
    cout << "\n\nStack 2\n";
    for ( int i = size-1; i >= top2 ; --i ) {
        cout << arr[i] << "\t";
    }
}
int main() {
    twoStacks ts;
    bool done = true;
    char choice;
    int value;
    while(done) {
        cout << "\n\n\n\t\tTwo Stacks in one Array\n";
        cout << "\n1. Push in 1st Stack\n";
        cout << "\n2. Pop from 1st Stack\n";
        cout << "\n3. Display 1st Stack\n";
        cout << "\n4. Push in 2nd Stack\n";
        cout << "\n5. Pop from 2nd Stack\n";
        cout << "\n6. Display 2nd Stack\n";
        cout << "\n7. Exit\n";
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice;
        switch (choice) {
            case '1'    :   cout << "\nEnter Value\t:\t";
                            cin >> value;
                            ts.push1(value);
                            break;
            case '2'    :   ts.pop1();
                            break;
            case '3'    :   ts.display1();
                            break;
            case '4'    :   cout << "\nEnter Value\t:\t";
                            cin >> value;
                            ts.push2(value);
                            break;
            case '5'    :   ts.pop2();
                            break;
            case '6'    :   ts.display2();
                            break;
            case '7'    :   done = false;
                            break;
            default     :   cout << "\nInvalid Input\n";
                            break;
        }
    }
    return 0;
}
