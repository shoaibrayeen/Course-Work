// C program to count number of nodes in

// a circular linked list.

#include <stdio.h>

#include <stdlib.h>

 

/* structure for a node */

struct Node {

    int data;

    struct Node* next;

};

 

/* Function to insert a node at the begining

   of a Circular linked list */

void push(struct Node** head_ref, int data)

{

    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));

    struct Node* temp = *head_ref;

    ptr1->data = data;

    ptr1->next = *head_ref;

 

    /* If linked list is not NULL then set

       the next of last node */

    if (*head_ref != NULL) {

        while (temp->next != *head_ref)

            temp = temp->next;

        temp->next = ptr1;

    } else

        ptr1->next = ptr1; /*For the first node */

 

    *head_ref = ptr1;

}

 

/* Function to print nodes in a given Circular

   linked list */

int countNodes(struct Node* head)

{

    struct Node* temp = head;

    int result = 0;

    if (head != NULL) {

        do {

            temp = temp->next;

            result++;

        } while (temp != head);

    }

 

    return result;

}

 

/* Driver program to test above functions */

int main()

{

    /* Initialize lists as empty */

    struct Node* head = NULL;

    push(&head, 12);

    push(&head, 56);

    push(&head, 2);

    push(&head, 11);

 

    printf("%d", countNodes(head));

 

    return 0;

}
