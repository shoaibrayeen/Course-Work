// C++ program to remove all 
// occurrences of duplicates 
// from a sorted linked list.
#include <bits/stdc++.h>
using namespace std;
 
// A linked list node
struct Node
{
    int data;
    struct Node *next;
};
 
// Utility function 
// to create a new Node
struct Node *newNode(int data)
{
Node *temp = new Node;
temp -> data = data;
temp -> next = NULL;
return temp;
}
 
// Function to print nodes 
// in a given linked list.
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node -> data);
        node = node -> next;
    }
}
 
// Function to remove all occurrences
// of duplicate elements
void removeAllDuplicates(struct Node* &start)
{
    // create a dummy node 
    // that acts like a fake
    // head of list pointing
    // to the original head
    Node* dummy = new Node;
 
    // dummy node points
    // to the original head
    dummy -> next = start;
     
    // Node pointing to last 
    // node which has no duplicate.
    Node* prev = dummy;
     
    // Node used to traverse
    // the linked list.
    Node* current = start;
 
    while(current != NULL)
    {
        // Until the current and 
        // previous values are 
        // same, keep updating current
        while(current -> next != NULL &&
              prev -> next -> data == current -> next -> data)
            current = current -> next;
 
        // if current has unique value 
        // i.e current is not updated, 
        // Move the prev pointer to 
        // next node
        if (prev -> next == current)
            prev = prev -> next;
 
        // when current is updated 
        // to the last duplicate 
        // value of that segment, 
        // make prev the next of current
        else
            prev -> next = current -> next;
 
        current = current -> next;
    }
 
    // update original head to 
    // the next of dummy node 
    start = dummy -> next;
}
 
// Driver Code
int main() 
{
    // 23->28->28->35->49->49->53->53
    struct Node* start = newNode(23);
    start -> next = newNode(28);
    start -> next -> next = newNode(28);
    start -> next -> 
     next -> next = newNode(35);
    start -> next -> 
    next -> next -> next = newNode(49);
    start -> next -> 
    next -> next -> 
    next -> next = newNode(49);
    start -> next -> 
    next -> next -> 
    next -> next -> next = newNode(53);
    start -> next -> 
    next -> next -> 
    next -> next -> 
    next -> next = newNode(53);
    cout << "List before removal " <<
                  "of duplicates\n";
    printList(start);
     
    removeAllDuplicates(start);
     
    cout << "\nList after removal " << 
                   "of duplicates\n";
    printList(start);
    return 0;
}
 
// This code is contributed 
// by NIKHIL JINDAL
