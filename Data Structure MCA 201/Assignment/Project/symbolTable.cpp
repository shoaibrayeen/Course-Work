//
//  symbolTable.cpp
//  Project-DS
//
//  Created by Mohd Shoaib Rayeen on 23/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 29
//MAXLEN value should be prime. If it's prime , there is less chance for collision.

struct node {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating structure node for hash
     
     ------------------------------------------------------------------------------------------------
     
     input parameters: none
     
     ------------------------------------------------------------------------------------------------
     
     output value: none
     
     ------------------------------------------------------------------------------------------------
     
     approach: Defines a node structure which contains:-
                1. type for type of variable
                2. variable_name for name of variable
                3. attribute for attribute of varibale
                4. next for storing address of next pointer
     
     ------------------------------------------------------------------------------------------------
     */
    string type;
    string variable_name;
    string attribute;
    node *next;
};

class symboltable{
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : symbol table class
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines constructor and functions which can be accessed publicly such as :-
                    1. defining head pointer
                    2. symboltable() for initializing the pointer
                    3. hash() for calculating hash value
                    4. insert() for inserting new record in symbol table
                    5. del() for deleting variable in symbol table
                    6. search() for searching variable in symbol table
                    7. checkType() for checking type of symbol
                    8. isEmpty() for checking hash is empty or not
                    9. display() for displaying [Lookup] of hash
                    10. mainloop() for calling member functions
     
     ------------------------------------------------------------------------------------------------
     */
    public:
    node *head[MAXLEN];
    symboltable();
    int hash(string name);
    void insert(string , string);
    void del(string);
    bool search(string);
    bool checkType(string);
    bool isEmpty();
    void display();
    void mainloop();
};

symboltable::symboltable(){
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : initializing each pointer as NULL
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   assigning NULL to each pointer of hash
     
     ------------------------------------------------------------------------------------------------
     */
    for(int i = 0; i < MAXLEN; ++i){
        head[i] = NULL;
    }
}

bool symboltable::isEmpty() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : checking hash is empty or not
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   comparing each index with NULL if all is NULL , return true else return false
     
     ------------------------------------------------------------------------------------------------
     */
    for(int i = 0; i < MAXLEN; ++i){
        if ( head[i] != NULL) {
            return false;
        }
    }
    return true;
}
int symboltable::hash(string name) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calculating hash value
     
     ------------------------------------------------------------------------------------------------
     input parameter : name [ symbol name ]
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : hash value
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   adding ASCII code of each character in name and returning reminder after dividing
                     by MAXLEN
     
     ------------------------------------------------------------------------------------------------
     */
    int index = 0;
    for(int i = 0; i < name.length(); ++i){
        index = index + name[i];
    }
    return (index % MAXLEN);
}
void symboltable::insert(string ntype , string nname) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : inserting new record in symbol table
     
     ------------------------------------------------------------------------------------------------
     input parameter :
                        ntype : symbol type
                        nname : symbol name
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   This function performs following operations :-
                     1. checking ntype that it's valid type or not
                     2. attribute contains "var"
                     3. checking nname that it's function or variable
                     4. if nname is function  , then attribute contains "proc"
                     5. calculating index for nname
                     6. if head[index] is NULL , then insert newnode at that position
                     7. if head[index] is not NULL , then insert newnode at last
     
     ------------------------------------------------------------------------------------------------
     */
    if (!checkType(ntype)) {
        cout << "\nUnknown Type Name...!\n";
        return;
    }
    string attr = "var";
    if(nname[nname.length()-2] == '(' && nname[nname.length()-1] == ')' ) {
        attr = "proc";
        nname = nname.substr(0,nname.length()-2);
    }
    if(search(nname)) {
        cout << "\nRedeclaration of Variable...!\n";
        return;
    }
    int index = hash(nname);
    if ( head[index] == NULL) {
        head[index] = new node;
        head[index]->variable_name = nname;
        head[index]->type = ntype;
        head[index]->attribute = attr;
        head[index]->next = NULL;
    }
    else {
        node* newnode = new node;
        newnode->variable_name = nname;
        newnode->type = ntype;
        newnode->attribute = attr;
        newnode->next = NULL;
        node * temp = head[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

bool symboltable::checkType(string ntype) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : checking type is valid or not
     
     ------------------------------------------------------------------------------------------------
     input parameter :  ntype :- symbol type
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : true if valid type otherwise false
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   compare with standard type , return true if matched otherwise return false
     
     ------------------------------------------------------------------------------------------------
     */
    if(ntype == "int" || ntype == "float" || ntype == "double" || ntype == "void" || ntype == "bool") {
        return true;
    }
    return false;
}
void symboltable::del(string name) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : deleting record of given symbol name
     
     ------------------------------------------------------------------------------------------------
     input parameter :  name :- symbol name
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  This function performs following operations :-
                    1. checking name that it's available or not
                    2. if name is available in symbol table , then calculating hash value
                    3. deleting node after comparing its variable_name to name
     
     ------------------------------------------------------------------------------------------------
     */
    if(!search(name)) {
        cout << name << " is not available in Hash\n";
        return;
    }
    int index = hash(name);
    node* temp = head[index];
    node * prev = temp;
    while(temp->next != NULL) {
        if(temp->variable_name == name ) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(prev==temp) {
        head[index] = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "\nElement Deleted Successfully\n";
}

bool symboltable::search(string name) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : searching record of given symbol name
     
     ------------------------------------------------------------------------------------------------
     input parameter :  name :- symbol name
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : true if find otherwise false
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  This function performs following operations :-
                    1. calculating hash value of given name
                    2. comparing name with variable_name at calculated index
                    3. return true if matched otherwise false.
     
     ------------------------------------------------------------------------------------------------
     */
    node* temp;
    int index = hash(name);
    temp = head[index];
    while ( temp!= NULL ) {
        if ( temp->variable_name == name) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void symboltable::display(){
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying symbol table
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : nonde
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  This function performs following operations :-
                    1. initializing a pointer to index of head
                    2. if pointer contains value , print record of node.
     
     ------------------------------------------------------------------------------------------------
     */
    if(isEmpty()) {
        cout << "\nSymbol table is Empty\n";
        return;
    }
    cout << "\n----------Symbol Table---------------\n";
    cout << "\n-------------------------------------";
    cout << "\n| Name\t|\tType\t|\tAttribute\t|\n";
    cout << "-------------------------------------\n";
    node* temp;
    for(int i = 0; i < MAXLEN; i++){
        temp = head[i];
        while ( temp!= NULL ) {
            cout << "|  "<< temp->variable_name << "\t|\t" << temp->type << "  \t|\t" << temp->attribute << "  \t\t|" <<endl;
            temp = temp->next;
        }
    }
    cout << "-------------------------------------\n";
}

void symboltable::mainloop() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : for calling member function
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  this function calls member functions using switch case.
     
     ------------------------------------------------------------------------------------------------
     */
    char choice;
    bool done = true;
    string name;
    string classtype;
    while(done) {
        cout << "\n-----Symbol Table Menu-----\n";
        cout << "\n1.Insert";
        cout << "\n2.Search";
        cout << "\n3.Delete";
        cout << "\n4.LookUp";
        cout << "\n5.Exit";
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice;
        switch( choice ) {
            case '1'    :   cout << "\nEnter Type\t\t:\t";
                            cin >> classtype;
                            cout << "\nEnter Symbol Name\t:\t";
                            cin >> name;
                            insert(classtype , name);
                            break;
            case '2'    :   cout << "Enter symbol name\t:\t";
                            cin >> name;
                            if(search(name)) {
                                cout << "\n " << name << "  is found in Hash";
                            }
                            else {
                                cout << "\n " << name << "  is not found in Hash";
                            }
                            break;
            case '3'    :   cout << "Enter symbol name\t:\t";
                            cin >> name;
                            del(name);
                            break;
            case '4'    :   display();
                            break;
            case '5'    :   done = false;
                            break;
            default     :   cout << "\nInvalid Choice\n";
        }
    }
}
int main() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : for calling mainloop()
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  creating object and calling mainloop using object
     
     ------------------------------------------------------------------------------------------------
     */
    symboltable object;
    object.mainloop();
    return 0;
}

