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
    vector <int> temp = {1 , 2 , 3}; //Initilizing
    temp.push_back(5);  //increasing size
    for ( int i = 0; i < 4; i++ ) {
        cout << temp[i] << " ";
    }
    cout << temp[6];   // can access any index using []
    cout << "\nSize of Vector\t:\t" << temp.size();
    cout << endl;
    return 0;
}

