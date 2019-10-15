//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> temp;
    for(int i = 0; i < 3; i++ ) {
        temp.push_back(i);
    }
    cout << "\nSize of Vector\t:\t" << temp.size();
    return 0;
} 
