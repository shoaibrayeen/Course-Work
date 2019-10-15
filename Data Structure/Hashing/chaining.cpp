//
//  hash_table.cpp
//  Project-DS
//
//  Created by Mohd Shoaib Rayeen on 16/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>


/* Node for storing an item in a Linked List */
struct node {
    int key;
    int value;
    node *next;
};

/* For storing a Linked List at each index of Hash Table  */
struct arrayitem {
    
    node *head;
    /* head pointing the first element of Linked List at an index of Hash Table */
    
    node *tail;
    /* tail pointing the last element of Linked List at an index of Hash Table */
    
};

arrayitem *array;
int size = 0;         /* Determines the no. of elements present in Hash Table */
int max = 10;          /* Determines the maximum capacity of Hash Table array */

/* This function creates an index corresponding to the every given key */
int hashcode(int key) {
    return (key % max);
}

node* get_element(node *list, int find_index);
void remove_element(int key);
void rehash();
void init_array();
int find(node *list, int key);

void insert(int key, int value) {
    float n = 0.0;
    /* n => Load Factor, keeps check on whether rehashing is required or not */
    
    int index = hashcode(key);
    
    /* Extracting Linked List at a given index */
    node *list = (node*) array[index].head;
    
    /* Creating an item to insert in the Hash Table */
    node *item = (node*) malloc(sizeof(node));
    item->key = key;
    item->value = value;
    item->next = NULL;
    
    if (list == NULL) {
        /* Absence of Linked List at a given Index of Hash Table */
        
        printf("Inserting %d(key) and %d(value) \n", key, value);
        array[index].head = item;
        array[index].tail = item;
        size++;
        
    }
    else {
        /* A Linked List is present at given index of Hash Table */
        
        int find_index = find(list, key);
        if (find_index == -1) {
            /*
             *Key not found in existing linked list
             *Adding the key at the end of the linked list
             */
            
            array[index].tail->next = item;
            array[index].tail = item;
            size++;
            
        }
        else {
            /*
             *Key already present in linked list
             *Updating the value of already existing key
             */
            
            node *element = get_element(list, find_index);
            element->value = value;
            
        }
        
    }
    
    //Calculating Load factor
    n = (1.0 * size) / max;
    if (n >= 0.75) {
        //rehashing
        
        printf("going to rehash\n");
        rehash();
        
    }
    
}

void rehash() {
    arrayitem *temp = array;
    /* temp pointing to the current Hash Table array */
    
    int i = 0, n = max;
    size = 0;
    max = 2 * max;
    
    /*
     *array variable is assigned with newly created Hash Table
     *with double of previous array size
     */
    array = (struct arrayitem*) malloc(max * sizeof(struct node));
    init_array();
    
    for (i = 0; i < n; i++) {
        
        /* Extracting the Linked List at position i of Hash Table array */
        node* list = (node*) temp[i].head;
        
        if (list == NULL) {
            
            /* if there is no Linked List, then continue */
            continue;
            
        }
        else {
            /*
             *Presence of Linked List at i
             *Keep moving and accessing the Linked List item until the end.
             *Get one key and value at a time and add it to new Hash Table array.
             */
            
            while (list != NULL)
            {
                insert(list->key, list->value);
                list = list->next;
            }
            
        }
        
    }
    temp = NULL;
}

/*
 *This function finds the given key in the Linked List
 *Returns it's index
 *Returns -1 in case key is not present
 */
int find(struct node *list, int key) {
    int retval = 0;
    struct node *temp = list;
    while (temp != NULL) {
        if (temp->key == key) {
            return retval;
        }
        temp = temp->next;
        retval++;
    }
    return -1;
    
}
/* Returns the node (Linked List item) located at given find_index  */
node* get_element(node *list, int find_index) {
    int i = 0;
    node *temp = list;
    while (i != find_index) {
        temp = temp->next;
        i++;
    }
    return temp;
}

/* To remove an element from Hash Table */
void remove_element(int key) {
    int index = hashcode(key);
    node *list = (node*) array[index].head;
    
    if (list == NULL) {
        printf("This key does not exists\n");
    }
    else {
        int find_index = find(list, key);
        
        if (find_index == -1) {
            printf("This key does not exists\n");
            
        }
        else {
            node *temp = list;
            if (temp->key == key){
                array[index].head = temp->next;
                printf("This key has been removed\n");
                return;
            }
            
            while (temp->next->key != key) {
                temp = temp->next;
            }
            
            if (array[index].tail == temp->next) {
                temp->next = NULL;
                array[index].tail = temp;
                
            }
            else {
                temp->next = temp->next->next;
                
            }
            
            printf("This key has been removed\n");
            
        }
        
    }
    
}

/* To display the contents of Hash Table */
void display() {
    int i = 0;
    for (i = 0; i < max; i++) {
        node *temp = array[i].head;
        if (temp == NULL) {
            printf("array[%d] has no elements\n", i);
            
        }
        else {
            printf("array[%d] has elements-: ", i);
            while (temp != NULL) {
                printf("key= %d  value= %d\t", temp->key, temp->value);
                temp = temp->next;
            }
            printf("\n");
            
        }
    }
}

/* For initializing the Hash Table */
void init_array() {
    int i = 0;
    for (i = 0; i < max; i++) {
        array[i].head = NULL;
        array[i].tail = NULL;
    }
    
}

/* Returns size of Hash Table */
int size_of_array() {
    return size;
}

int main() {
    int key, value, n;
    char choice;
    array = (struct arrayitem*) malloc(max * sizeof(struct arrayitem*));
    init_array();
    bool done = true;
    do {
        printf("\n\nImplementation of Hash Table in C++ chaining with Singly Linked List \n\n");
        printf("\n1.Inserting item in the Hash Table"
               "\n2.Removing item from the Hash Table"
               "\n3.Check the size of Hash Table"
               "\n4.To display a Hash Table"
               "\n5.Exit"
               "\n\nEnter your choice\t:\t");
        scanf("%s", &choice);
        switch(choice) {
                
            case '1':   printf("Inserting element in Hash Table\n");
                        printf("Enter key and value-:\t");
                        scanf("%d %d", &key, &value);
                        insert(key, value);
                        break;
            case '2':   printf("Deleting in Hash Table \nEnter the key to delete-:");
                        scanf("%d", &key);
                        remove_element(key);
                        break;
            case '3':   n = size_of_array();
                        printf("Size of Hash Table is-:%d\n", n);
                        break;
            case '4':   display();
                        break;
            case '5':   done = false;
                        break;
            default:    printf("Wrong Input\n");
        }
        
    }while(done);
    return 0;
}
