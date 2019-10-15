// A C program to demonstrate deletion of last
// Node in singly linked list
#include <stdio.h>
#include <stdlib.h>
 
// A linked list Node
struct Node {
    int data;
    struct Node* next;
};
 
// Function to delete the last occurrence
void deleteLast(struct Node* head, int x)
{
    struct Node *temp = head, *ptr = NULL;
    while (temp) {
 
        // If found key, update
        if (temp->data == x) 
            ptr = temp;        
        temp = temp->next;
    }
 
    // If the last occurrence is the last node
    if (ptr != NULL && ptr->next == NULL) {
        temp = head;
        while (temp->next != ptr) 
            temp = temp->next;       
        temp->next = NULL;
    }
 
    // If it is not the last node
    if (ptr != NULL && ptr->next != NULL) {
        ptr->data = ptr->next->data;
        temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }
}
 
/* Utility function to create a new node with
given key */
struct Node* newNode(int x)
{
    struct Node* node = malloc(sizeof(struct Node*));
    node->data = x;
    node->next = NULL;
    return node;
}
 
// This function prints contents of linked list
// starting from the given Node
void display(struct Node* head)
{
    struct Node* temp = head;
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
/* Drier program to test above functions*/
int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next = newNode(4);
    printf("Created Linked list: ");
    display(head);
    deleteLast(head, 4);
    printf("List after deletion of 4: ");
    display(head);
    return 0;
}
