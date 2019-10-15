// C++ implementation to find the sum of

// last 'n' nodes of the Linked List

#include <bits/stdc++.h>

using namespace std;

 

/* A Linked list node */

struct Node {

    int data;

    struct Node* next;

};

 

// function to insert a node at the

// beginning of the linked list

void push(struct Node** head_ref, int new_data)

{

    /* allocate node */

    struct Node* new_node = new Node;

 

    /* put in the data  */

    new_node->data = new_data;

 

    /* link the old list to the new node */

    new_node->next = (*head_ref);

 

    /* move the head to point to the new node */

    (*head_ref) = new_node;

}

 

// function to recursively find the sum of last

// 'n' nodes of the given linked list

void sumOfLastN_Nodes(struct Node* head, int* n,

                                      int* sum)

{

    // if head = NULL

    if (!head)

        return;

 

    // recursively traverse the remaining nodes

    sumOfLastN_Nodes(head->next, n, sum);

 

    // if node count 'n' is greater than 0

    if (*n > 0) {

 

        // accumulate sum

        *sum = *sum + head->data;

 

        // reduce node count 'n' by 1

        --*n;

    }

}

 

// utility function to find the sum of last 'n' nodes

int sumOfLastN_NodesUtil(struct Node* head, int n)

{

    // if n == 0

    if (n <= 0)

        return 0;

 

    int sum = 0;

 

    // find the sum of last 'n' nodes

    sumOfLastN_Nodes(head, &n, &sum);

 

    // required sum

    return sum;

}

 

// Driver program to test above

int main()

{

    struct Node* head = NULL;

 

    // create linked list 10->6->8->4->12

    push(&head, 12);

    push(&head, 4);

    push(&head, 8);

    push(&head, 6);

    push(&head, 10);

 

    int n = 2;

    cout << "Sum of last " << n << " nodes = "

         << sumOfLastN_NodesUtil(head, n);

    return 0;

}
