//
//  q6(i).cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

struct bnode {
    int data;
    bnode *left;
    bnode *right;
};

class btree {
public:
    bnode *root;
    int arr[20] ,pathlen;
    btree();
    void insert();
    void display();
    void path(bnode* , int);
    void printpath(int* , int);
    bnode* newNode(int);
    void preorder(bnode*);
    void postorder(bnode*);
    void inorder(bnode*);
};
btree::btree() {
    root = NULL;
    pathlen = 0;
}
bnode* btree:: newNode(int value) {
    bnode* temp=new bnode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void btree:: insert() {
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
}
void btree::display() {
    insert();
    cout << "\nInorder\t\t:\t";
    inorder(root);
    cout << "\nPostorder\t:\t";
    postorder(root);
    cout << "\nPreorder\t:\t";
    preorder(root);
    cout << "\nPossible Paths\n";
    path(root , 0);
}
void btree :: postorder(bnode* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void btree :: preorder(bnode* root) {
    if (root == NULL)
        return;
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void btree :: inorder(bnode* root) {
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->data << "\t";
    preorder(root->right);
}

void btree :: path(bnode* root ,int pathlen) {
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

void btree ::printpath(int arr[], int len) {
    cout << "\n";
    
    for (int i=0; i<len; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}
