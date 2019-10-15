/*Program to alternatively split a linked list into two halves */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 
/* pull off the front node of the source and put it in dest */
void MoveNode(struct Node** destRef, struct Node** sourceRef) ;
 
/* Given the source list, split its nodes into two shorter lists.
  If we number the elements 0, 1, 2, ... then all the even elements
  should go in the first list, and all the odd elements in the second.
  The elements in the new lists may be in any order. */
void AlternatingSplit(struct Node* source, struct Node** aRef, 
                            struct Node** bRef) 
{
  /* split the nodes of source to these 'a' and 'b' lists */
  struct Node* a = NULL; 
  struct Node* b = NULL;
   
  struct Node* current = source;
  while (current != NULL) 
  {
    MoveNode(&a, &current); /* Move a node to list 'a' */
    if (current != NULL) 
    {
       MoveNode(&b, &current); /* Move a node to list 'b' */
    }
  }
  *aRef = a;
  *bRef = b;
}
 
/* Take the node from the front of the source, and move it to the front of the dest.
   It is an error to call this with the source list empty. 
    
   Before calling MoveNode():
   source == {1, 2, 3}   
   dest == {1, 2, 3}
       
   Affter calling MoveNode():
   source == {2, 3}      
   dest == {1, 1, 2, 3}      
*/
void MoveNode(struct Node** destRef, struct Node** sourceRef) 
{
  /* the front source node  */
  struct Node* newNode = *sourceRef; 
  assert(newNode != NULL);
   
  /* Advance the source pointer */
  *sourceRef = newNode->next;
   
  /* Link the old dest off the new node */
  newNode->next = *destRef; 
   
  /* Move dest to point to the new node */
  *destRef = newNode; 
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct node** head_ref, int new_data)
{
  /* allocate node */
  struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*head_ref);     
 
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
} 
 
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct Node* head = NULL;
  struct Node* a = NULL;
  struct Node* b = NULL;  
 
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 0->1->2->3->4->5 */
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);                                    
  push(&head, 0);  
 
  printf("\n Original linked List:  ");
  printList(head); 
 
  /* Remove duplicates from linked list */
  AlternatingSplit(head, &a, &b); 
 
  printf("\n Resultant Linked List 'a' ");
  printList(a);            
 
  printf("\n Resultant Linked List 'b' ");
  printList(b);            
 
  getchar();
  return 0;
}
