//
//  q5.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 11/03/18.
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
    void display();
    void eliminate(int);
};
csll::csll() {
    head=NULL;
}
void csll::insert(int value) {
    int i = 1;
    while( i <= value ) {
        node* temp=new node;
        temp->data=i;
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
        i++;
    }
}
void csll::display() {
    cout << "\nRemaining Person\t:\t";
    node *T=head;
    while(T->next!=head) {
        cout << T->data << "->";
        T=T->next;
    }
    cout << T->data;
}
void csll::eliminate(int m ) {
    int i = 1;
    node* temp = head;
    while ( head->next!=head ) {
        node* p = temp->next;
        while ( i < ( m-1 ) ) {
            i++;
            temp = temp->next;
            p = temp->next;
        }
        if ( p == head ) {
            head = p->next;
        }
        temp->next = p->next;
        cout << "\nEliminated Person\t:\t" << p->data;
        delete p;
        i = 1;
        temp = temp->next;
        display();
    }
}
int main() {
    csll obj;
    int n , m;
    cout << "\nNumber of Persons\t\t:\t";
    cin >> n;
    cout << "\nEliminating position\t:\t";
    cin >> m;
    obj.insert(n);
    obj.eliminate(m);
    cout << endl;
    return 0;
}


