/* C program to pairwise swap elements in a given linked list */

#include<stdio.h>

#include<stdlib.h>

 

/* A linked list node */

struct Node

{

    int data;

    struct Node *next;

};

 

/*Function to swap two integers at addresses a and b */

void swap(int *a, int *b);

 

/* Function to pairwise swap elements of a linked list */

void pairWiseSwap(struct Node *head)

{

    struct Node *temp = head;

 

    /* Traverse further only if there are at-least two nodes left */

    while (temp != NULL && temp->next != NULL)

    {

        /* Swap data of node with its next node's data */

        swap(&temp->data, &temp->next->data);

 

        /* Move temp by 2 for the next pair */

        temp = temp->next->next;

    }

}

 

/* UTILITY FUNCTIONS */

/* Function to swap two integers */

void swap(int *a, int *b)

{

    int temp;

    temp = *a;

    *a = *b;

    *b = temp;

}

 

/* Function to add a node at the begining of Linked List */

void push(struct Node** head_ref, int new_data)

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

    while (node != NULL)

    {

        printf("%d ", node->data);

       node = node->next;

    }

}

 

/* Driver program to test above function */

int main()

{

    struct Node *start = NULL;

 

    /* The constructed linked list is:

     1->2->3->4->5 */

    push(&start, 5);

    push(&start, 4);

    push(&start, 3);

    push(&start, 2);

    push(&start, 1);

 

    printf("Linked list before calling  pairWiseSwap()\n");

    printList(start);

 

    pairWiseSwap(start);

 

    printf("\nLinked list after calling  pairWiseSwap()\n");

    printList(start);

 

    return 0;

} 
