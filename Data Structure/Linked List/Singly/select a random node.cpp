/* C program to randomly select a node from a singly
   linked list */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
 
/* Link list node */
struct Node
{
    int key;
    struct Node* next;
};
 
// A reservoir sampling based function to print a
// random node from a linked list
void printRandom(struct Node *head)
{
    // IF list is empty
    if (head == NULL)
       return;
 
    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));
 
    // Initialize result as first node
    int result = head->key;
 
    // Iterate from the (k+1)th element to nth element
    struct Node *current = head;
    int n;
    for (n=2; current!=NULL; n++)
    {
        // change result with probability 1/n
        if (rand() % n == 0)
           result = current->key;
 
        // Move to next node
        current = current->next;
    }
 
    printf("Randomly selected key is %d\n", result);
}
 
/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST  */
 
/* A utility function to create a new node */
struct Node *newNode(int new_key)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the key  */
    new_node->key  = new_key;
    new_node->next =  NULL;
 
    return new_node;
}
 
 
/* A utility function to insert a node at the beginning
  of linked list */
void push(struct Node** head_ref, int new_key)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the key  */
    new_node->key  = new_key;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
 
// Driver program to test above functions
int main()
{
    struct Node *head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
 
    printRandom(head);
 
    return 0;
}
