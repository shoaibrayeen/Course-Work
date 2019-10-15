//
//  stack_as_array.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 07/02/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
class stack {
    /*
     objective : class for stack using array
     input parameter : none
     output parameter : none
     approach : using array
     */
    int *arr;       // dynamic array
    int top;        // top of stack
    public :
    stack();
    ~stack();
    void push(int &);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    void display();
};

stack :: stack() {
    arr=new int[MAXSIZE];
    top=-1;
}
stack :: ~stack() {
    delete[] arr;
}

void stack :: push( int & newValue) {
    if(isFull()) {
        cout << "\nStack is full.\n";
    }
    else  {
        top++;
        arr[top]=newValue;
        display();
    }
}

int stack :: pop() {
    if(isEmpty()) {
        return -1;
    }
    else {
        return arr[top--];
    }
}

int stack :: peek() {
    if(isEmpty()) {
        cout << "\nStack is Empty.\n";
        return -1;
    }
    else {
        return arr[top];
    }
}

int stack:: size() {
    return top+1;
    
}

bool stack::isFull() {
    if(top==MAXSIZE-1) {
        return true;
    }
    return false;
}
bool stack::isEmpty() {
    if(top==-1) {
        return true;
    }
    return false;
}

void stack:: display() {
    cout << "\nStack Elements\n\n";
    for ( int i = top ; i != -1 ; --i) {
        cout << "| " << arr[i] << " | " ;
        cout << "\n-----\n";
    }
}
int main() {
    stack obj;
    int temp;
    while(1) {
        cout << "\n1.Push\n2.Pop\n3.Top Element of Stack\n4.Size of Stack\n5.Exit\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        obj.push(temp);
                        break;
            case 2 :    temp=obj.pop();
                        if(temp==-1) {
                            cout << "\nStack is Empty.\n";
                        }
                        else {
                            cout << "\nPopped Element\t:\t" << temp;
                            obj.display();
                        }
                        break;
            case 3 :    temp=obj.peek();
                        if(temp==-1) {
                            cout << "\nStack is Empty.\n";
                        }
                        else {
                            cout << "\nTop Element of Stack\t:\t" << temp;
                        }
                        break;
            case 4 :    cout << "\nSize of Stack\t:\t" << obj.size();
                        break;
            case 5 :    exit(0);
                        break;
            default:    cout << "\nInvalid Input\n";
        }
    }
    return 0;
}
