// C program to find n'th 
// node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
// Link list node
struct Node
{
    int data;
    struct Node* next;
};
 
/* Given a reference (pointer to 
   pointer) to the head of a list
   and an int, push a new node on
   the front of the list. */
void push(struct Node** head_ref, 
                    int new_data)
{
     
    // allocate node
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    // put in the data
    new_node->data = new_data;
 
    // link the old list 
    // off the new node 
    new_node->next = (*head_ref);
 
    // move the head to point
    // to the new node 
    (*head_ref) = new_node;
}
 
// Takes head pointer of 
// the linked list and index
// as arguments and return
// data at index
int GetNth(struct Node* head, 
                  int index)
{
     
    struct Node* current = head;
     
     // the index of the 
     // node we're currently
     // looking at
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
 
    /* if we get to this line, 
       the caller was asking
       for a non-existent element
       so we assert fail */
    assert(0);             
}
 
// Driver Code
int main()
{
     
    // Start with the 
    // empty list 
    struct Node* head = NULL;
 
    // Use push() to construct
    // below list
    // 1->12->1->4->1 
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1); 
 
    // Check the count
    // function
    printf("Element at index 3 is %d", 
                     GetNth(head, 3)); 
    getchar();
}
