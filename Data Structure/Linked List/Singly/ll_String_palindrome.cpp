// Program to check if a given linked list of strings
// form a palindrome
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    string data;
    Node* next;
};
 
// A utility function to check if str is palindrome
// or not
bool isPalindromeUtil(string str)
{
    int length = str.length();
 
    // Match characters from beginning and
    // end.
    for (int i=0; i<length/2; i++)
        if (str[i] != str[length-i-1])
            return false;
 
    return true;
}
 
// Returns true if string formed by linked
// list is palindrome
bool isPalindrome(Node *node)
{
    // Append all nodes to form a string
    string str = "";
    while (node != NULL)
    {
        str.append(node->data);
        node = node->next;
    }
 
    // Check if the formed string is palindrome
    return isPalindromeUtil(str);
}
 
// A utility function to print a given linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    printf("NULL\n");
}
 
/* Function to create a new node with given data */
Node *newNode(const char *str)
{
    Node *new_node = new Node;
    new_node->data = str;
    new_node->next = NULL;
    return new_node;
}
 
/* Driver program to test above function*/
int main()
{
    Node *head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");
 
    isPalindrome(head)? printf("true\n"):
                        printf("false\n");
 
    return 0;
}
