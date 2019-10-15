// C++ program to find pair with given sum in a singly
// linked list in O(n) time and no extra space.
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
 
    /* also constains XOR of next and
    previous node after conversion*/
    struct Node* next;
};
 
/* Given a reference (pointer to pointer) to the head
    of a list and an int, push a new node on the front
    of the list. */
void insert(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* returns XORed value of the node addresses */
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
 
// Utility function to convert singly linked list
// into XOR doubly linked list
void convert(struct Node *head)
{
    // first we store address of next node in it
    // then take XOR of next node and previous node
    // and store it in next pointer
    struct Node *next_node;
 
    // prev node stores the address of previously
    // visited node
    struct Node *prev = NULL;
 
    // traverse list and store xor of address of
    // next_node and prev node in next pointer of node
    while (head != NULL)
    {
        // address of next node
        next_node = head->next;
 
        // xor of next_node and prev node
        head->next = XOR(next_node, prev);
 
        // update previous node
        prev = head;
 
        // move head forward
        head = next_node;
    }
}
 
// function to Find pair whose sum is equal to
// given value x
void pairSum(struct Node *head, int x)
{
    // initialize first
    struct Node *first = head;
 
    // next_node and prev node to calculate xor again
    // and find next and prev node while moving forward
    // and backward direction from both the corners
    struct Node *next_node = NULL, *prev = NULL;
 
    // traverse list to initialize second pointer
    // here we need to move in forward direction so to
    // calculate next address we have to take xor
    // with prev pointer because (a^b)^b = a
    struct Node *second = head;
    while (second->next != prev)
    {
        struct Node *temp = second;
        second = XOR(second->next, prev);
        prev = temp;
    }
 
    // now traverse from both the corners
    next_node = NULL;
    prev = NULL;
 
    // here if we want to move forward then we must
    // know the prev address to calculate next node
    // and if we want to move backward then we must
    // know the next_node address to calculate prev node
    bool flag = false;
    while (first != NULL && second != NULL &&
            first != second && first != next_node)
    {
        if ((first->data + second->data)==x)
        {
            cout << "(" << first->data << ","
                 << second->data << ")" << endl;
 
            flag = true;
 
            // move first in forward
            struct Node *temp = first;
            first = XOR(first->next,prev);
            prev = temp;
 
            // move second in backward
            temp = second;
            second = XOR(second->next, next_node);
            next_node = temp;
        }
        else
        {
            if ((first->data + second->data) < x)
            {
                // move first in forward
                struct Node *temp = first;
                first = XOR(first->next,prev);
                prev = temp;
            }
            else
            {
                // move second in backward
                struct Node *temp = second;
                second = XOR(second->next, next_node);
                next_node = temp;
            }
        }
    }
    if (flag == false)
        cout << "No pair found" << endl;
}
 
// Driver program to run the case
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    int x = 17;
 
    /* Use insert() to construct below list
    3-->6-->7-->8-->9-->10-->11 */
    insert(&head, 11);
    insert(&head, 10);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 3);
 
    // convert singly linked list into XOR doubly
    // linked list
    convert(head);
    pairSum(head,x);
    return 0;
}
