//
//  split_cll.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 10/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class csll {
    public:
    node *head;
    csll();
    void insert(int);
    void display(node*);
    void split();
};
csll::csll() {
    head=NULL;
}
void csll::insert(int value) {
    node* temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
        head->next=head;
    }
    else {
        node *T=head;
        while(T->next!=head) {
            T=T->next;
        }
        T->next=temp;
        temp->next=head;
    }
    cout << "\n List\t:\t";
    display(head);
}
void csll::display(node* head) {
    if(head==NULL) {
        cout << "\n\n List is Empty....!!!!!!!";
    }
    else {
        node *T=head;
        while(T->next!=head) {
            cout << T->data << "->";
            T=T->next;
        }
        cout << T->data;
    }
}
void csll::split() {
    //using Floyd cycle finding algorithm
    if ( head == NULL ) {
        return;
    }
    node* head1 = NULL;
    node* head2 = NULL;
    node* slow = head;
    node* fast = head;
    while( fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next == head) {
        head1 = head;
        head2 = slow->next;
        slow->next = head1;
        fast->next = head2;
    }
    if( fast->next->next == head ) {
        head1 = head;
        head2 = slow->next;
        slow->next = head1;
        fast->next->next = head2;
    }
    cout << "\n\n List1\t:\t";
    display(head1);
    cout << "\n\n List2\t:\t";
    display(head2);
}
int main() {
    int choice,value;
    csll obj;
    while(1) {
        cout << "\n\n\t     MENU";
        cout << "\n 1. Insertion";
        cout << "\n 2. Split Linked List";
        cout << "\n 3. Exit ";
        cout << "\n Enter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case 1  :   cout << "\n Enter the element\t:\t";
                        cin >> value;
                        obj.insert(value);
                        break;
            case 2  :   obj.split();
                        break;
            case 3  :   exit(0);
                        break;
            default :   cout << "\n Invalid Choice\n ";
        }
    }
    return 0;
}
