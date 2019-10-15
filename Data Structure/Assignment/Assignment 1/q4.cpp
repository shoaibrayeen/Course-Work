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
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating structure for circular singly linked list node
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  structure defines a node structure which contains data ( int type ) and
                    next ( cslnode types for storing address of next pointer )
     
     ------------------------------------------------------------------------------------------------
     */
    int data;
    cslnode *next;
};

class csll {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : circular singly linked list class
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines constructor and functions which can be accessed publicly such as :-
                     1. csll() for initializing the pointer
                     2. insert() for inserting variable into linked list
                     3. display() for displaying circular linked list
                     4. split() for spliting Linked list into two halves
                     5. main_q4() for calling member functions
                     6. declaring 3 pointers head , head1 and head2
     ------------------------------------------------------------------------------------------------
     */

public:
    cslnode *head , *head1 , *head2;
    csll();
    void insert(int);
    void display(cslnode*);
    void split();
    void main_q4();
};
csll::csll() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : initializing pointers as NULL
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   assigning NULL to each pointer which is declared in class
     
     ------------------------------------------------------------------------------------------------
     */
    
    head = NULL;
    head1 = NULL;
    head2 = NULL;
}
void csll::insert(int value) {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : inseting element to linked list
     
     ------------------------------------------------------------------------------------------------
     input parameter : value which has to inserted into linked list
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   This function performs following operations :-
                     1. creating a newnode of cslnode type
                     2. if head is NULL , then newnode is assigned as head.
                     3. if head is not NULL , then with the help of another pointer inserting newnode
                        at the end of linked list
                     4. the next of newnode points to head.
                     5. calling display() function after every insertion
     ------------------------------------------------------------------------------------------------
     */
    cslnode* newnode=new cslnode;
    newnode->data=value;
    newnode->next=NULL;
    if(head == NULL) {
        head = newnode;
        head->next = head;
    }
    else {
        cslnode *temp=head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    cout << "\n List\t:\t";
    display(head);
}


void csll::display(cslnode* head) {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying linked list
     
     ------------------------------------------------------------------------------------------------
     input parameter :  head of linked list
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this function displays current list with the help of another pointer
     
     ------------------------------------------------------------------------------------------------
     */
    
    if(head==NULL) {
        cout << "\n\n List is Empty....!!!!!!!";
    }
    else {
        cslnode *temp = head;
        while(temp->next != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data;
    }
}


void csll::split() {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : split circular linked list into two halves
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this functions performs following operations :-
                     1. if linked list contains no elements or single element , then it can't split
                        linked list into two halves.
                     // using floyd algorithm
                     2. declaring two pointer named slow and fast and intialize them as head
                     3. updating slow as next of slow and fast as next of next of fast till next of fast
                        is not equal to head and next of next of fast is not equal to head
                     4. the head of 1st halves if head and head of 2nd halves is next of slow.
                     5. if next of fast is head , then the next of slow contains address of 1st head
                        and the next of fast contains address of 2nd head.
                     6. if next of next of fast is head , thenthe next of slow contains address of 1st head
                        and the next of next of fast contains address of 2nd head.
                     7. head is assigned as NULL .
                     8. displaying 1st half and 2nd half with the help of head1 and head2.
     ------------------------------------------------------------------------------------------------
     */
    
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
    head1 = head;
    head2 = slow->next;
    if(fast->next == head) {
        slow->next = head1;
        fast->next = head2;
    }
    if( fast->next->next == head ) {
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
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling each function except this function
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this functions performs following operations :-
                     1. inserting in linked list
                     2. split linked list into two halves
                     3. exit from program
     
     ------------------------------------------------------------------------------------------------
     */
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

