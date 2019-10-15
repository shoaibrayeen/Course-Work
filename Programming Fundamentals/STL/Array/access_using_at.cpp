//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<array> // for array, at()

using namespace std;
int main() {
    array < int , 5 > ar = {1, 2, 3, 4, 5};  //initializing STL Array
    cout << "The array elemets are (using at())\t:\t";
    for ( int i = 0; i < 5; i++ ) {
        cout << ar.at(i) << " ";
    }
    cout << endl;
    //Now Accessing Index greater than length using at()
    cout << ar.at(7);
    cout << endl;
    return 0;
    
}
