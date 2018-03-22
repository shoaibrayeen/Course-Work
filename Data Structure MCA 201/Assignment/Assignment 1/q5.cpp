//
//  q5.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

struct csllnode {
    int data;
    csllnode *next;
};

class csl {
public:
    csllnode *head;
    csl();
    void insert(int);
    void display();
    void eliminate(int);
    void main_q5();
};
csl::csl() {
    head=NULL;
}
void csl::insert(int value) {
    int i = 1;
    while( i <= value ) {
        csllnode* temp=new csllnode;
        temp->data=i;
        temp->next=NULL;
        if(head==NULL) {
            head=temp;
            head->next=head;
        }
        else {
            csllnode *T=head;
            while(T->next!=head) {
                T=T->next;
            }
            T->next=temp;
            temp->next=head;
        }
        i++;
    }
}
void csl::display() {
    cout << "\nRemaining Person\t:\t";
    csllnode *T=head;
    while(T->next!=head) {
        cout << T->data << "->";
        T=T->next;
    }
    cout << T->data;
}
void csl::eliminate(int m ) {
    int i = 0;
    csllnode* temp = head;
    while ( head->next != head ) {
        csllnode* p = head;
        while ( i < ( m-1 ) ) {
            i++;
            if( i < (m-1)) {
                temp = temp->next;
            }
            p = temp->next;
        }
        if ( p == head ) {
            csllnode* t  = head;
            while ( t->next != head ) {
                t = t->next;
            }
            head = head->next;
            t->next = head;
        }
        temp->next = p->next;
        cout << "\nEliminated Person\t:\t" << p->data;
        delete p;
        i = 0;
        temp = temp->next;
        display();
    }
}
void csl::main_q5() {
    cout << "\n---------Eliminating mth people in a circular LL----------\n";
    int n , m;
    cout << "\nNumber of Persons\t\t:\t";
    cin >> n;
    cout << "\nEliminating position\t:\t";
    cin >> m;
    insert(n);
    eliminate(m);
    cout << endl;
}



