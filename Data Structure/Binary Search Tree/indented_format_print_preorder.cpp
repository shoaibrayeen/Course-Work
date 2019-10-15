#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void print_format (struct node* root ,int height ) {
    for ( int i = 1 ; i <= 2*height ; i++ ) {
        cout << "_";
    }
    cout << root ->data << endl;
}
void print (struct node* root , int height ) {
    if ( root ) {
        print_format( root , height );
    }
    if ( root->left ) {
        print( root->left , height - 1 );
    }
    if ( root->right ) {
        print( root->right , height - 1 );
    }
    
}

int maxDepth(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}

struct node* newNode(int data) {
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    root->right->left = newNode(6);
    int temp = maxDepth(root);
    printf("Hight of tree is %d", temp);
    cout << endl;
    print( root , temp);
    return 0;
}
