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
    int *array;
    array = new int[3];
    array = { 1 , 2 , 3  };
    for (int i = 0; i < 3; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < 3; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

