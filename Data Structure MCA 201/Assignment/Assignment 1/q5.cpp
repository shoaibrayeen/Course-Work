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
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating structure for circular singly linked list node
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  structure defines a node structure which contains data ( int type ) and
                    next ( csllnode types for storing address of next pointer )
     
     ------------------------------------------------------------------------------------------------
     */
    int data;
    csllnode *next;
};

class csl {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : circular singly linked list class
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines constructor and functions which can be accessed publicly such as :-
                     1. csl() for initializing the pointer
                     2. insert() for inserting variable into linked list from 1 to n
                     3. display() for displaying circular linked list
                     4. eliminate() for eliminating every mth person
                     5. main_q5() for calling member functions
                     6. declaring one pointer head
     ------------------------------------------------------------------------------------------------
     */
public:
    csllnode *head;
    csl();
    void insert(int);
    void display();
    void eliminate(int);
    void main_q5();
};
csl::csl() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : initializing pointer as NULL
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   assigning NULL to head pointer
     
     ------------------------------------------------------------------------------------------------
     */
    head = NULL;
}
void csl::insert(int n) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : inseting element to linked list
     
     ------------------------------------------------------------------------------------------------
     input parameter : n:- inserting from 1 to n in linked list
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   This function performs following operations :-
                     1. assigning i for iteration from 1 to n
                     2. creating a newnode of csllnode type
                     3. if head is NULL , then newnode is assigned as head.
                     4. if head is not NULL , then with the help of another pointer inserting newnode
                        at the end of linked list
                     5. the next of newnode points to head.
                     6. increasing i by one
                     7. repeating from step 3 to 6 till i is not equal to n
     ------------------------------------------------------------------------------------------------
     */
    int i = 1;
    while( i <= n ) {
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
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying linked list
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this function displays remaining person in list
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\nRemaining Person\t:\t";
    csllnode *T=head;
    while(T->next!=head) {
        cout << T->data << "->";
        T=T->next;
    }
    cout << T->data;
}
void csl::eliminate(int m ) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : eliminate every mth person till last person remaining
     
     ------------------------------------------------------------------------------------------------
     input parameter :  m :- position at which element has to deleted
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   the function perfoms following operations :-
                     1. assigning i to 0 for iteration from 0 to m-2
                     2. assigning a pointer temp to head
                     3. creating another pointer for deleting mth element
                     4. assigning i to 0 for next iteration
                     5. displaying remaining list
                     6. repeat from step 3 to 5 till next of head is not equal to head.
     
     ------------------------------------------------------------------------------------------------
     */
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
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling each function except this function
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this functions performs following operations :-
                     1. taking input for number of person
                     2. taking input for elimationg position
                     3. inserting from 1 to n in circluar linked list
                     4. eliminating every mth person till last one remaining
     
     ------------------------------------------------------------------------------------------------
     */
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



