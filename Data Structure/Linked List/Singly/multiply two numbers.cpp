// C program to Multiply two numbers

// represented as linked lists

#include<stdio.h>

#include<stdlib.h>

// Linked list node

struct node

{

    int data;

    struct node* next;

};

// Function to create a new node 

// with given data

struct node *newNode(int data)

{

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = data;

    new_node->next = NULL;

    return new_node;

}

// Function to insert a node at the 

// beginning of the Linked List

void push(struct node** head_ref, int new_data)

{

    // allocate node 

    struct node* new_node = newNode(new_data);

    // link the old list off the new node 

    new_node->next = (*head_ref);

    // move the head to point to the new node 

    (*head_ref) = new_node;

}

// Multiply contents of two linked lists

long multiplyTwoLists (struct node* first, struct node* second)

{

    int num1 = 0, num2 = 0;

    

    // Generate numbers from linked lists

    while (first || second)

    {

        if (first)

        {

            num1 = num1*10 + first->data;

            first = first->next;

        }

        if (second)

        {

            num2 = num2*10 + second->data;

            second = second->next;

        }

    }

    // Return multiplication of 

    // two numbers

    return num1*num2;

}

// A utility function to print a linked list

void printList(struct node *node)

{

    while(node != NULL)

    {

        printf("%d", node->data);

        if(node->next)

            printf("->");

        node = node->next;

    }

    printf("\n");

}

// Driver program to test above function

int main(void)

{

    struct node* first = NULL;

    struct node* second = NULL;

    // create first list 9->4->6

    push(&first, 6);

    push(&first, 4);

    push(&first, 9);

    printf("First List is: ");

    printList(first);

    // create second list 8->4

    push(&second, 4);

    push(&second, 8);

    printf("Second List is: ");

    printList(second);

    // Multiply the two lists and see result

    printf("Result is: ");

    printf("%ld", multiplyTwoLists(first, second));

    return 0;

}
