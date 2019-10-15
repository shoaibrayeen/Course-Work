#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
    struct node* node = (struct node*)
                           malloc(sizeof(struct node));
 
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return(node);
}
 
/*  This function traverses tree in post order to 
    to delete each and every node of the tree */
void deleteTree(struct node* node) 
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
   
    /* then delete the node */
    printf("\n Deleting node: %d", node->data);
    free(node);
} 
 
 
/* Driver program to test deleteTree function*/   
int main()
{
    struct node *root = newNode(1); 
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5); 
   
    deleteTree(root);  
    root = NULL;
 
    printf("\n Tree deleted ");
   
    getchar();
    return 0;
}
