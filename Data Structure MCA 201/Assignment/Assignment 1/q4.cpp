//
//  q4.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

struct cslnode {
    int data;
    cslnode *next;
};

class csll {
public:
    cslnode *head , *head1 , *head2;
    csll();
    void insert(int);
    void display(cslnode*);
    void split();
    void main_q4();
};
csll::csll() {
    head = NULL;
    head1 = NULL;
    head2 = NULL;
}
void csll::insert(int value) {
    cslnode* temp=new cslnode;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
        head->next=head;
    }
    else {
        cslnode *T=head;
        while(T->next!=head) {
            T=T->next;
        }
        T->next=temp;
        temp->next=head;
    }
    cout << "\n List\t:\t";
    display(head);
}
void csll::display(cslnode* head) {
    if(head==NULL) {
        cout << "\n\n List is Empty....!!!!!!!";
    }
    else {
        cslnode *T=head;
        while(T->next!=head) {
            cout << T->data << "->";
            T=T->next;
        }
        cout << T->data;
    }
}
void csll::split() {
    if ( head == NULL || head->next == head ) {
        cout << "\nCan't Split Circular Linked List into two halves\n";
        return;
    }
    cslnode* slow = head;
    cslnode* fast = head;
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
        if(head->next->next != head ) {
            slow->next = head1;
            fast->next->next = head2;
        }
        else  {
            head1->next = head1;
            head2->next = head2;
        }
    }
    head = NULL;
    cout << "\n\n List1\t:\t";
    display(head1);
    cout << "\n\n List2\t:\t";
    display(head2);
}
void csll :: main_q4() {
    int value;
    char choice;
    bool done  =  true;
    while(done) {
        cout << "\n\n\t----------Split Circular Linked List in Two Halves---------\n";
        cout << "\n 1. Insertion";
        cout << "\n 2. Split Linked List";
        cout << "\n 3. Go to Main Menu \n 4. Exit\n";
        cout << "\n Enter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case '1'  : cout << "\n Enter the element\t:\t";
                        cin >> value;
                        insert(value);
                        break;
            case '2'  : split();
                        break;
            case '3'  : done  = false;
                        break;
            case '4'  : exit(0);
            default :   cout << "\n Invalid Choice\n ";
        }
    }
}

