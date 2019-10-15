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
    int n;                                  // declaring variable to store size of array
    cin >> n;
    int array[n];                   // declaring array ->Store in stack area
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

