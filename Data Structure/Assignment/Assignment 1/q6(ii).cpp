//
//  q6(ii).cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream>
using namespace std;

struct node {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating structure for binary tree
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  structure defines a node structure which contains data ( int type ) and
     left and right ( node types for storing address of left and right elements )
     
     ------------------------------------------------------------------------------------------------
     */
    int data;
    node *left;
    node *right;
};

class tree {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : binary tree class
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines constructor and functions which can be accessed publicly such as :-
                     1. tree() for initializing the pointer
                     2. insert() for insertion in binary tree
                     3. display() for displaying binary tree
                     4. path() for calculating path from root to every leaf node
                     5. printpath() for displaying path
                     6. newNode() for creating new node
                     7. preorder() for displaying preorder of tree
                     8. postorder() for displaying postorder of tree
                     9. inorder() for displaying inorder of tree
                     10. creating root node for binary tree
                     11. arr[] for storing path , pathlen for storing length of path for every leaf node
                         sum for user input ,count for checking that path exists or not
     ------------------------------------------------------------------------------------------------
     */
public:
    node *root;
    int arr[20] ,pathlen , sum , count;
    tree();
    void insert();
    void display();
    void path(node* , int);
    void printpath(int* , int );
    node* newNode(int);
    void preorder(node*);
    void postorder(node*);
    void inorder(node*);
};
tree::tree() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : initializing root as NULL sum , count and pathlen as zero
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   assigning NULL to root and 0 to pathlen , sum and count
     
     ------------------------------------------------------------------------------------------------
     */
    root = NULL;
    pathlen = 0;
    sum = 0;
    count = 0;
}
node* tree:: newNode(int value) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating newnode and assigning it to given value
     
     ------------------------------------------------------------------------------------------------
     input parameter : value which has to inserted into binary tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : new node which is created
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating a node type pointer and assiging its left and right as NULL and data as value
     
     ------------------------------------------------------------------------------------------------
     */
    node* temp=new node;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void tree:: insert() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insertion in binary tree
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   inserting nodes from root , then its right & left and so on
     
     ------------------------------------------------------------------------------------------------
     */
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    root->left->right->left = newNode(9);
    root->left->left->right = newNode(3);
}
void tree::display() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying binary tree and path
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling insert() , inorder() , preorder() , postorder and path() functions
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\nEnter Path Sum\t:\t";
    cin >> sum;
    insert();
    cout << "\nInorder\t\t:\t";
    inorder(root);
    cout << "\nPostorder\t:\t";
    postorder(root);
    cout << "\nPreorder\t:\t";
    preorder(root);
    path(root , 0);
    if(count == 0) {
        cout << "\nThere does not exist any path to given sum";
    }
}
void tree :: postorder(node* root)
{
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in postorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
                     - left , right and then value of pointer
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void tree :: preorder(node* root)
{
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in preorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
                     - value of pointer , left and right
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL)
        return;
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void tree :: inorder(node* root)
{
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in inorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
                     - left , value of pointer and right
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->data << "\t";
    preorder(root->right);
}

void tree :: path(node* root ,int pathlen) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calculating path from root to everyleaf node
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree and pathlen
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this function calls itself for left and right node recursively till the left
                     and right of the current node is not NULL and store the path in array .
                     When the left and right of the current node is NULL prints path for the same.
     
     ------------------------------------------------------------------------------------------------
     */
    if (root==NULL)
        return;
    arr[pathlen] = root->data;
    pathlen++;
    if (root->left==NULL && root->right==NULL) {
        printpath(arr, pathlen);
    }
    else {
        path(root->left , pathlen);
        path(root->right , pathlen);
    }
}

void tree ::printpath(int arr[], int len) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : printing path for current node
     
     ------------------------------------------------------------------------------------------------
     input parameter :  array which stores path from root to leaf node and len which stores length of
                        the path
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   prints path stored in array using for loop if sum of path is equal to given sum.
     
     ------------------------------------------------------------------------------------------------
     */
    int temp = 0;
    for (int i=0; i<len; i++) {
        temp += arr[i];
    }
    if ( sum == temp ) {
        if(count == 0 ) {
            cout << "\nPossible Path according to given sum\n\n";
        }
        for (int i = 0; i < len; i++) {
            cout << arr[i] <<"\t";
            count++;
        }
    }
    cout << "\n";
}
