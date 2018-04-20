//
//  symbol_table.cpp
//  Project-DS
//
//  Created by Mohd Shoaib Rayeen on 19/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

#define CHAIN_LENGTH 29
#define M 64

struct symbol_info {
    char *name;
    char *classtype;
    struct symbol_info *next;
} *block[CHAIN_LENGTH];

int Hash(char* name){
    int idx = 0;
    for(int i = 0; name[i]; ++i){
        idx = idx + name[i];
    }
    return (idx % CHAIN_LENGTH);
}


void Insert(char* name, char* classtype){
    int pos = Hash(name);
    block[pos] = new symbol_info;
    block[pos]->name = name;
    block[pos]->classtype = classtype;
    block[pos]->next = NULL;   
}

bool Search(char* name, char* classtype){
    int pos = Hash(name);
    symbol_info* temp = block[pos];
    while( temp != NULL ){
        if( !strcmp( temp->name, name ) && !strcmp( temp->classtype, classtype ) ){
            return true;
        }
        temp = temp->next;
    }
    return false;
}


void Delete(char* name, char* classtype){
    int pos = Hash(name);
    
    symbol_info* temp = block[pos];
    if(temp == NULL) return;
    if( temp->next == NULL && !strcmp( temp->name, name ) && !strcmp( temp->classtype, classtype ) ){
        block[pos] = NULL;
    }
    else if( !strcmp( temp->name, name ) && !strcmp( temp->classtype, classtype ) ){
        block[pos] = temp->next;
    }
    else{
        
        while( temp->next != NULL ){
            if ( !strcmp( temp->next->name, name ) && !strcmp( temp->next->classtype, classtype ) ){
                printf("FOUND IT %s : %s\n", temp->name, temp->classtype );
                break;
            }
            temp = temp->next;
        }
        if( temp != NULL ){
            symbol_info* found = temp->next;
            temp->next = found->next;
            delete(found);
        }
        
        
    }
}

void Update(char* name, char* classtype, char* updatedClasstype){
    int pos = Hash(name);
    symbol_info* temp = block[pos];
    while( temp != NULL ){
        if( !strcmp( temp->name, name ) && !strcmp( temp->classtype, classtype ) ){
            temp->classtype = updatedClasstype;
            return;
        }
        temp = temp->next;
    }
}


void showSymbolTable(){
    printf("\nSymbol Table\n");
    printf("\n--------------------------------");
    printf("\nClass\t|\tVariable Name\n");
    symbol_info* temp;
    for(int i = 0; i < CHAIN_LENGTH;i++){
        temp = block[i];
        if ( temp!= NULL ) {
            printf("%s\t\t|\t%s\n", temp->classtype , temp->name);
            temp = NULL;
        }
    }
}




int main() {
    int choice;
    bool done = true;
    char *name = new char[M];
    char *classtype = new char[M];
    initialize();
    while(done) {
        string message = "1.insert(name, class type)\n"
        "2.update(name, class type, new class type)\n"
        "3.search(name, class type)\n"
        "4.delete(name, class type)\n"
        "5.Display symbol table\n"
        "6.Exit\n";
        cout << message << "\n";
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice;
        switch( choice ) {
            case 1  :   scanf("%s%s", name, classtype);
                        printf("%s %s\n", name, classtype);
                        printf("%d\n", Hash(name) );
                        Insert(name, classtype);
                        break;
                
            case 2  :   {
                            char* updatedClasstype = new char[M];
                            scanf("%s%s%s", name, classtype, updatedClasstype);
                
                            printf("%s %s\n", name, classtype);
                            printf("%d\n", Hash(name) );
                            Update(name, classtype, updatedClasstype);
                        }
                        break;
            case 3  :   scanf("%s%s", name, classtype);
                        printf("%s %s\n", name, classtype);
                        printf("%d\n", Hash(name) );
                        if( Search(name, classtype) ){
                            printf("FOUND\n");
                        }
                        else {
                            printf("NOT FOUND\n");
                        }
                        break;
            case 4  :   scanf("%s%s", name, classtype);
                        printf("%s %s\n", name, classtype);
                        printf("%d\n", Hash(name) );
                        Delete(name, classtype);
                        break;
            case 5  :   showSymbolTable();
                        break;
            case 6  :   done = false;
                        break;
            default :   cout << "\nInvalid Choice\n";
        }
    }
    return 0;
}
