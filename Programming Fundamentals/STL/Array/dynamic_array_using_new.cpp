//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;
int main() {
    int *array;                             // declaring pointer to access array
    int n;                                  // declaring variable to store size of array
    cin >> n;
    array = new int[n];                     // declaring array with new ->Store in heap area
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cin >> array[n];
    n++;                                    // increasing size
    for (int i = 0; i < n; i++) {           // printing elements
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

