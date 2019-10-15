//
//  subset.cpp
//  Problems
//
//  Created by Mohd Shoaib Rayeen on 02/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push (Node** head_ref, int new_data) {
    struct Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool isPresent (Node *head, int data) {
    Node *t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

Node *getUnion(Node *head1,Node *head2) {
    Node *result = NULL;
    Node *t1 = head1, *t2 = head2;
    while (t1 != NULL) {
        push(&result, t1->data);
        t1 = t1->next;
    }
    while (t2 != NULL) {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
    
    return result;
}

Node *getIntersection(Node *head1, Node *head2) {
    Node *result = NULL;
    Node *t1 = head1;
    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
    return result;
}


void printList (Node *node) {
    while (node->next != NULL) {
        cout << node->data <<"->";
        node = node->next;
    }
    cout << node->data;
}

void mainloop() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* intersection_head = NULL;
    Node* union_head = NULL;
    int value;
    bool done = true;
    char choice;
    while(done) {
        cout << "\n\n\t     MENU";
        cout << "\n1. Insertion in 1st list";
        cout << "\n2. Insertion in 2nd list";
        cout << "\n3. Union of Lists";
        cout << "\n4. Intersection of Lists";
        cout << "\n5. Exit";
        cout << "\nEnter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case '1'  : cout << "\nEnter Value\t:\t";
                        cin >> value;
                        push (&head1, value);
                        cout << "\nFirst list\t:\t";
                        printList (head1);
                        break;
            case '2'  : cout << "\nEnter Value\t:\t";
                        cin >> value;
                        push (&head2, value);
                        cout << "\nSecond list\t:\t";
                        printList (head2);
                        break;
            case '3'  : union_head = getUnion (head1, head2);
                        if(union_head == NULL ) {
                            cout << "\nUnion is Empty.\n";
                        }
                        else {
                            cout << "\nUnion of lists\t:\t";
                            printList (union_head);
                        }
                        break;
            case '4'  : intersection_head = getIntersection (head1, head2);
                        if(intersection_head == NULL ) {
                            cout << "\nIntersection is Empty.\n";
                        }
                        else {
                            cout << "\nIntersection of lists\t:\t";
                            printList (intersection_head);
                        }
                        break;
            case '5'  : done = false;
                        break;
            default :   cout << "\nInvalid Choice\n ";
        }
    }
}
int main() {
    mainloop();
    return 0;
}
