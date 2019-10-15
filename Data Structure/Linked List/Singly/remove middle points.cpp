// C program to remove intermediate points in a linked list 
// that represents horizontal and vertical line segments
#include <stdio.h>
#include <stdlib.h>
 
// Node has 3 fields including x, y coordinates and a pointer
// to next node
struct Node
{
    int x, y;
    struct Node *next;
};
 
/* Function to insert a node at the beginning */
void push(struct Node ** head_ref, int x,int y)
{
    struct Node* new_node = 
           (struct Node*) malloc(sizeof(struct Node));
    new_node->x  = x;
    new_node->y  = y;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
 
/* Utility function to print a singly linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("(%d,%d)-> ", temp->x,temp->y);
        temp = temp->next;
    }
    printf("\n");
 
}
 
// Utility function to remove Next from linked list 
// and link nodes after it to head
void deleteNode(struct Node *head, struct Node *Next)
{
    head->next = Next->next;
    Next->next = NULL;
    free(Next);
}
 
// This function deletes middle nodes in a sequence of
// horizontal and vertical line segments represented by
// linked list.
struct Node* deleteMiddle(struct Node *head)
{
    // If only one node or no node...Return back
    if (head==NULL || head->next ==NULL || head->next->next==NULL)
        return head;
 
    struct Node* Next = head->next;
    struct Node *NextNext = Next->next ;
 
    // Check if this is a vertical line or horizontal line
    if (head->x == Next->x)
    {
        // Find middle nodes with same x value, and delete them
        while (NextNext !=NULL && Next->x==NextNext->x)
        {
            deleteNode(head, Next);
 
            // Update Next and NextNext for next iteration
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    else if (head->y==Next->y) // If horizontal line
    {
        // Find middle nodes with same y value, and delete them
        while (NextNext !=NULL && Next->y==NextNext->y)
        {
            deleteNode(head, Next);
 
            // Update Next and NextNext for next iteration
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    else  // Adjacent points must have either same x or same y
    {
        puts("Given linked list is not valid");
        return NULL;
    }
 
    // Recur for next segment
    deleteMiddle(head->next);
 
    return head;
}
 
// Driver program to tsst above functions
int main()
{
    struct Node *head = NULL;
 
    push(&head, 40,5);
    push(&head, 20,5);
    push(&head, 10,5);
    push(&head, 10,8);
    push(&head, 10,10);
    push(&head, 3,10);
    push(&head, 1,10);
    push(&head, 0,10);
    printf("Given Linked List: \n");
    printList(head);
 
    if (deleteMiddle(head) != NULL);
    {
        printf("Modified Linked List: \n");
        printList(head);
    }
    return 0;
}
