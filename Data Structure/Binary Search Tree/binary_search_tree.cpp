//
//  binary_search_tree.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 10/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<stdlib.h>
using namespace std;


struct node
{
    int key;
    node *left, *right;
};

// A utility function to create a new BST node
node *newNode(int item)
{
    node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout <<  root->key << "\t";
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        cout <<  root->key << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout <<  root->key << "\t";
    }
}
/* A utility function to insert a new node with given key in BST */
node* insert(node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key <= node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) node pointer */
    return node;
}

node * minValueNode(struct node* node)
{
    struct node* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    
    return current;
}

node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        /*if (root->key == key)
        {
            root = NULL;
            //free(root);
            return root;
        }
        else */if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = minValueNode(root->right);
        
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

bool Search(node *root, int key)
{
    // Traverse untill root reaches to dead end
    while (root != NULL)
    {
        // pass right subtree as new tree
        if (key > root->key)
            root = root->right;
        
        // pass left subtree as new tree
        else if (key < root->key)
            root = root->left;
        else
            return true;// if the key is found return 1
    }
    return false;
}
// Driver Program to test above functions
int main()
{
    node *root = NULL;
    int value;
    char choice;
    bool done = true;
    while(done) {
        cout << "\n\n\t\t--------Binary Search Tree-------";
        cout << "\n 1. Insertion";
        cout << "\n 2. Displaying Tree";
        cout << "\n 3. Delete a node";
        cout << "\n 4. Search in the Tree";
        cout << "\n 5. Exit ";
        cout << "\n Enter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case '1'  : cout << "\n Enter the element\t:\t";
                        cin >> value;
                        if(root == NULL ) {
                            root = insert(root, value);
                        }
                        else {
                            insert(root , value);
                        }
                    break;
            case '2'  :
                        if(root == NULL ) {
                            cout << "\n Tree is Empty\n";
                            break;
                        }
                        cout << "\n Inorder\t:\t";
                        inorder(root);
                        cout << "\n Preorder\t:\t";
                        preorder(root);
                        cout << "\n Postorder\t:\t";
                        postorder(root);
                        break;
            case '3'  :
                        if(root == NULL ) {
                            cout << "\n Tree is Empty\n";
                            break;
                        }
                        cout << "\n Enter the element\t:\t";
                        cin >> value;
                        if(!Search(root , value)) {
                            cout << "\n" << value << " is not in the Tree\n";
                            break;
                        }
                        root = deleteNode(root , value);
                        break;
            case '4'  :
                        if(root == NULL ) {
                            cout << "\n Tree is Empty\n";
                            break;
                        }
                        cout << "\n Enter the element\t:\t";
                        cin >> value;
                        if(!Search(root , value)) {
                            cout << "\n" << value << " is not available in the Tree\n";
                        }
                        else {
                            cout << "\n" << value << " is available in the Tree\n";
                        }
                        break;
            case '5'  : done = false;
                         break;
            default :   cout << "\n Invalid Choice\n ";
        }
    }
    return 0;
}
