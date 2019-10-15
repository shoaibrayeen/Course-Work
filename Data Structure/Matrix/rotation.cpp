//
// rotation.cpp
//  Problems
//
//  Created by Mohd Shoaib Rayeen on 08/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;
//Inplace rotate square matrix by 90 degrees without using extra spacs
int main(int argc, const char * argv[]) {
    int n;
    cout << "\nEnter Size of Square Matrix\t:\t";
    cin >> n;
    int matrix[n][n];
    // Input of Matrix
    cout << "\nEnter Elements\n";
    for ( int i = 0 ; i < n; ++i) {
        for ( int j = 0; j < n; ++j ) {
            cin >> matrix[i][j];
        }
    }
    //Transpose of Matrix
    for ( int i = 0 ; i < n; ++i) {
        for ( int j = 0; j < n; ++j ) {
            if ( i < j ) {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }
    //reversing each column
    int k = n-1;
    for ( int i = 0 ; i < n/2; ++i) {
        for ( int j = 0; j < n; ++j ) {
            if ( i < k ) {
                swap(matrix[i][j] , matrix[k][j]);
            }
        }
        k --;
    }
    //Display Resultant Matrix
    for ( int i = 0 ; i < n; ++i) {
        for ( int j = 0; j < n; ++j ) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
