
// C++ program to move all occurrences of a
// given key to end.
#include<bits/stdc++.h>
 
// A Linked list Node
struct Node
{
    int data;
    struct Node* next;
};
 
// A urility function to create a new node.
struct Node *newNode(int x)
{
   Node *temp = new Node;
   temp->data = x;
   temp->next = NULL;
}
 
// Utility function to print the elements
// in Linked list
void printList(Node *head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 
// Moves all occurrences of given key to
// end of linked list.
void moveToEnd(Node *head, int key)
{
    // Keeps track of locations where key
    // is present.
    struct Node *pKey = head;
 
    // Traverse list
    struct Node *pCrawl = head;
    while (pCrawl != NULL)
    {
        // If current pointer is not same as pointer
        // to a key location, then we must have found
        // a key in linked list. We swap data of pCrawl
        // and pKey and move pKey to next position.
        if (pCrawl != pKey && pCrawl->data != key)
        {
            pKey->data = pCrawl->data;
            pCrawl->data = key;
            pKey = pKey->next;
        }
 
        // Find next position where key is present
        if (pKey->data != key)
            pKey = pKey->next;
 
        // Moving to next Node
        pCrawl = pCrawl->next;
    }
}
 
// Driver code
int main()
{
    Node *head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(10);
    head->next->next->next = newNode(30);
    head->next->next->next->next = newNode(40);
    head->next->next->next->next->next = newNode(10);
    head->next->next->next->next->next->next = newNode(60);
 
    printf("Before moveToEnd(), the Linked list is\n");
    printList(head);
 
    int key = 10;
    moveToEnd(head, key);
 
    printf("\nAfter moveToEnd(), the Linked list is\n");
    printList(head);
 
    return 0;
}
