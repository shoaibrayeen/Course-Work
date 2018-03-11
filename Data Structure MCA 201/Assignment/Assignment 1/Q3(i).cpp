//
//  reverse_ll_pair.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 10/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<stack>
using namespace std;
struct node {
    int data;
    node *next;
};

class sll {
public:
    node *head;
    sll();
    void insert(int);
    void display();
    void reverse();
};
sll::sll() {
    head=NULL;
}
void sll::insert(int value) {
    node* temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
    }
    else {
        node *T=head;
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
        node *T=head;
        while(T->next!=NULL) {
            cout << T->data << "->";
            T=T->next;
        }
        cout << T->data;
    }
}

void sll:: reverse() {
    stack<node*> s;
    node* current = head;
    node* prev = NULL;
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
int main() {
    int choice,value;
    sll obj;
    while(1) {
        cout << "\n\n\t     MENU";
        cout << "\n 1. Insertion";
        cout << "\n 2. Reverse Linked List";
        cout << "\n 3. Exit ";
        cout << "\n Enter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case 1  :   cout << "\n Enter the element\t:\t";
                        cin >> value;
                        obj.insert(value);
                        break;
            case 2  :   cout << "\n List\t:\t";
                        obj.reverse();
                        break;
            case 3  :   exit(0);
                        break;
            default :   cout << "\n Invalid Choice\n ";
        }
    }
    return 0;
}
