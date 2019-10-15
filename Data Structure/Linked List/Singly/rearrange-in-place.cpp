// C++ program to rearrange a linked list in-place
#include<bits/stdc++.h>
using namespace std;
 
// Linkedlist Node structure
struct Node
{
    int data;
    struct Node *next;
};
 
// Function to create newNode in a linkedlist
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// Function to reverse the linked list
void reverselist(Node **head)
{
    // Initialize prev and current pointers
    Node *prev = NULL, *curr = *head, *next;
 
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 
    *head = prev;
}
 
// Function to print the linked list
void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        if(head->next) cout << "-> ";
        head = head->next;
    }
    cout << endl;
}
 
// Function to rearrange a linked list
void rearrange(Node **head)
{
    // 1) Find the muddle point using tortoise and hare method 
    Node *slow = *head, *fast = slow->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
 
    // 2) Split the linked list in two halves
    // head1, head of first half    1 -> 2
    // head2, head of second half   3 -> 4
    Node *head1 = *head;
    Node *head2 = slow->next;
    slow->next = NULL;
 
    // 3) Reverse the second half, i.e.,  4 -> 3
    reverselist(&head2);
 
    // 4) Merge alternate nodes
    *head = newNode(0); // Assign dummy Node
 
    // curr is the pointer to this dummy Node, which will
    // be used to form the new list
    Node *curr = *head;
    while (head1 || head2)
    {
        // First add the element from list
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
 
        // Then add the element from second list
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
 
    // Assign the head of the new list to head pointer
    *head = (*head)->next;
}
 
// Driver program
int main()
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    printlist(head);    // Print original list
    rearrange(&head);       // Modify the list
    printlist(head);    // Print modified list
    return 0;
}
