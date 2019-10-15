

// C++ implementation to merge k sorted linked lists

// | Using MIN HEAP method

#include <bits/stdc++.h>

using namespace std;

 

struct Node {

    int data;

    struct Node* next;

};

 

// 'compare' function used to build up the

// priority queue

struct compare {

    bool operator()(struct Node* a, struct Node* b)

    {

        return a->data > b->data;

    }

};

 

// function to merge k sorted linked lists

struct Node* mergeKSortedLists(struct Node* arr[], int k)

{

    struct Node* head = NULL, *last;

 

    // priority_queue 'pq' implemeted as min heap with the

    // help of 'compare' function

    priority_queue<Node*, vector<Node*>, compare> pq;

 

    // push the head nodes of all the k lists in 'pq'

    for (int i = 0; i < k; i++)

        pq.push(arr[i]);

 

    // loop till 'pq' is not empty

    while (!pq.empty()) {

 

        // get the top element of 'pq'

        struct Node* top = pq.top();

        pq.pop();

 

        // check if there is a node next to the 'top' node

        // in the list of which 'top' node is a member

        if (top->next != NULL)

            // push the next node in 'pq'

            pq.push(top->next);

 

        // if final merged list is empty

        if (head == NULL) {

            head = top;

 

            // points to the last node so far of

            // the final merged list

            last = top;

        }

 

        else {

            // insert 'top' at the end of the merged list so far

            last->next = top;

 

            // update the 'last' pointer

            last = top;

        }

    }

 

    // head node of the required merged list

    return head;

}

 

// function to print the singly linked list

void printList(struct Node* head)

{

    while (head != NULL) {

        cout << head->data << " ";

        head = head->next;

    }

}

 

// Utility function to create a new node

struct Node* newNode(int data)

{

    // allocate node

    struct Node* new_node = new Node();

 

    // put in the data

    new_node->data = data;

    new_node->next = NULL;

 

    return new_node;

}

 

// Driver program to test above

int main()

{

    int k = 3; // Number of linked lists

    int n = 4; // Number of elements in each list

 

    // an array of pointers storing the head nodes

    // of the linked lists

    Node* arr[k];

 

    // creating k = 3 sorted lists

    arr[0] = newNode(1);

    arr[0]->next = newNode(3);

    arr[0]->next->next = newNode(5);

    arr[0]->next->next->next = newNode(7);

 

    arr[1] = newNode(2);

    arr[1]->next = newNode(4);

    arr[1]->next->next = newNode(6);

    arr[1]->next->next->next = newNode(8);

 

    arr[2] = newNode(0);

    arr[2]->next = newNode(9);

    arr[2]->next->next = newNode(10);

    arr[2]->next->next->next = newNode(11);

 

    // merge the k sorted lists

    struct Node* head = mergeKSortedLists(arr, k);

 

    // print the merged list

    printList(head);

 

    return 0;
} 
