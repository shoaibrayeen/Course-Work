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
    int data;
    node *left;
    node *right;
};

class tree {
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
    root = NULL;
    pathlen = 0;
    sum = 0;
    count = 0;
}
node* tree:: newNode(int value) {
    node* temp=new node;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void tree:: insert() {
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
}
void tree::display() {
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
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void tree :: preorder(node* root)
{
    if (root == NULL)
        return;
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void tree :: inorder(node* root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->data << "\t";
    preorder(root->right);
}

void tree :: path(node* root ,int pathlen) {
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
    int temp = 0;
    for (int i=0; i<len; i++) {
        temp += arr[i];
    }
    if ( sum == temp ) {
        cout << "\nPossible Path according to given sum\n";
        for (int i = 0; i < len; i++) {
            cout << arr[i] <<"\t";
            count++;
        }
    }
    cout << "\n";
}
