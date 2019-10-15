//
//  search_node_ll.cpp
//  Problems
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

class sll {
public:
    node *head;
    sll();
    void insert(int);
    void display();
    void search(int);
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
    display();
}

void sll::display() {
    if(head==NULL) {
        cout << "\n\n List is Empty....!!!!!!!";
    }
    else {
        cout << "\n List\t:\t";
        node *T=head;
        while(T->next!=NULL) {
            cout << T->data << "->";
            T=T->next;
        }
        cout << T->data;
    }
}
void sll:: search(int value) {
    node* temp = head;
    while(temp!=NULL && temp->data!=value) {
        temp = temp->next;
    }
    if ( temp == NULL ) {
        cout << "\nElement not found\n";
        return;
    }
    cout << "\nElement found\n";
}
int main() {
    int choice,value;
    sll obj;
    while(1) {
        cout << "\n\n\t     MENU";
        cout << "\n1. Insertion";
        cout << "\n2. Search";
        cout << "\n3. Exit ";
        cout << "\nEnter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case 1  :   cout << "\nEnter the element\t:\t";
                        cin >> value;
                        obj.insert(value);
                        break;
            case 2  :   cout << "\nEnter the element\t:\t";
                        cin >> value;
                        obj.search(value);
                        break;
            case 3  :   exit(0);
                        break;
            default :   cout << "\nInvalid Choice\n ";
        }
    }
    return 0;
}
