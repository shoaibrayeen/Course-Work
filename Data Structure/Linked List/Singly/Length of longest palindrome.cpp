// C++ program to find longest palindrome
// sublist in a list in O(1) time.
#include<bits/stdc++.h>
using namespace std;
 
//structure of the linked list
struct Node
{
    int data;
    struct Node* next;
};
 
// function for counting the common elements
int countCommon(Node *a, Node *b)
{
    int count = 0;
 
    // loop to count coomon in the list starting
    // from node a and b
    for (; a && b; a = a->next, b = b->next)
 
        // increment the count for same values
        if (a->data == b->data)
            ++count;
        else
            break;
 
    return count;
}
 
// Returns length of the longest palindrome
// sublist in given list
int maxPalindrome(Node *head)
{
    int result = 0;
    Node *prev = NULL, *curr = head;
 
    // loop till the end of the linked list
    while (curr)
    {
        // The sublist from head to current
        // reversed.
        Node *next = curr->next;
        curr->next = prev;
 
        // check for odd length palindrome
        // by finding longest common list elements
        // beginning from prev and from next (We
        // exclude curr)
        result = max(result,
                     2*countCommon(prev, next)+1);
 
        // check for even length palindrome
        // by finding longest common list elements
        // beginning from curr and from next
        result = max(result,
                     2*countCommon(curr, next));
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
    return result;
}
 
// Utility function to create a new list node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
/* Drier program to test above functions*/
int main()
{
    /* Let us create a linked lists to test
       the functions
    Created list is a: 2->4->3->4->2->15 */
    Node *head = newNode(2);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(15);
 
    cout << maxPalindrome(head) << endl;
    return 0;
}
