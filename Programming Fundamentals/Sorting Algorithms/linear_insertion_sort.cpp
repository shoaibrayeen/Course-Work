//
//  insertion sort.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 02/08/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std ;

class Isort {
    private :
    int array[10] , number ;
    public :
    Isort() ;
    void input() ;
    void display() ;
    void insertion() ;
};

Isort :: Isort () {
    for ( int i = 0 ; i < 10 ; ++i )
        array[i] = 0;
    number = 0 ;
}

void Isort :: input() {
    cout << "\nEnter number of elemnets\t:\t" ;
    cin >> number ;
    cout << "\nEnter Elements\n" ;
    for ( int i = 0 ; i < number ; ++i ) {
        cout << "\nEnter " << ( i + 1 ) << " element\t:\t" ;
        cin >> array[i] ;
        cout << endl ;
    }
}

void Isort :: insertion() {
    int key , j;
    for ( int i = 1 ; i < number ; ++i ) {
        key = array[i];
        j = i-1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
        cout << "\nIterations\t\t:\t" ;
        display();
    }
}

void Isort :: display() {
    for ( int i = 0 ; i < number ; ++i ) {
        cout << array[i] <<"\t" ;
    }
    cout << endl ;
}

int main() {
    Isort object;
    object.input() ;
    cout << "\nEntered Elements\t:\t" ;
    object.display() ;
    object.insertion() ;
    cout << "\nSorted Elements \t:\t" ;
    object.display() ;
    return 0;
}

