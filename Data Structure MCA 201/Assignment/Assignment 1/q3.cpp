//
//  q3.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include <stack>
using namespace std;
struct slnode {
    int data;
    slnode *next;
};

class sll {
public:
    slnode *head;
    sll();
    void insert(int);
    void display();
    void reverse();
    void main_q3();
};
sll::sll() {
    head=NULL;
}
void sll::insert(int value) {
    slnode* temp=new slnode;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
    }
    else {
        slnode *T=head;
        while(T->next!=NULL) {
            T=T->next;
        }
        T->next=temp;
    }
    cout << "\n List\t:\t";
    display();
}

void sll::display() {
    if(head==NULL) {
        cout << "\n\n List is Empty....!!!!!!!";
    }
    else {
        slnode * T = head;
        while(T->next != NULL) {
            cout << T->data << "->";
            T=T->next;
        }
        cout << T->data;
    }
}

void sll:: reverse() {
    stack<slnode*> s;
    slnode* current = head;
    slnode* prev = NULL;
    while (current != NULL) {
        s.push(current);
        current = current->next;
        if(current != NULL ) {
            s.push(current);
            current = current->next;
        }
        while (!s.empty()) {
            if (prev == NULL) {
                prev = s.top();
                head = prev;
                s.pop();
            } else {
                prev->next = s.top();
                prev = prev->next;
                s.pop();
            }
        }
    }
    prev->next = NULL;
    display();
}
void sll::main_q3() {
    int value;
    char choice;
    bool done = true;
    while(done) {
        cout << "\n\n\t\t--------Reverse Linked List Menu-------";
        cout << "\n 1. Insertion";
        cout << "\n 2. Reverse Linked List";
        cout << "\n 3. Go to Main Menu  \n 4. Exit ";
        cout << "\n Enter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case '1'  : cout << "\n Enter the element\t:\t";
                        cin >> value;
                        insert(value);
                        break;
            case '2'  : cout << "\n List\t:\t";
                        reverse();
                        break;
            case '3'  : done = false;
                        break;
            case '4'  : exit(0);
            default :   cout << "\n Invalid Choice\n ";
        }
    }
}

