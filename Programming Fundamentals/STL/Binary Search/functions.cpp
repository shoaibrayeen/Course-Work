//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//



    //  binary_search( p1 = start address , p2 = end address , p3 = key) -> return true false
    /*
        lower_bound ( p1 = start address , p2 = end address , p3 = key)
        return Address of 1st occurence of the key if key is present
        return Address of next higher key if key is not present
    */
    /*
        upperbound ( p1 = start address , p2 = end address , p3 = key)
        return Address of next higher key after last occurence of the key if key is present
        return Address of next higher key if key is not present
     
     */
     
     
#include <algorithm>
#include <iostream>
using namespace std;

void show(int a[], int arraysize) {            // function to print array
    for (int i = 0; i < arraysize; ++i)
        cout << a[i] << " ";
}

int main() {
    int a[] = { 10 , 20 , 20 , 30 , 40 , 50 };             // Declaring and initializing the Array
    int asize = sizeof(a) / sizeof(a[0]);       // calculating Size of Array
    cout << "\nArray\t\t:\t";
    show(a, asize);                             // Output -> 10 , 20 , 20 , 30 , 40  , 50
    if ( binary_search(a, a + 6, 20) ) {         // searching 20 in the array
        cout << "\nFound at\t:\t "<< (lower_bound(a , a + 6, 20) - a);  // Output -> 1
    }
    else {
        cout << "\n2 not found";          // print if function returns False
    }
    if ( binary_search(a, a + 6, 9) ) {         // Searching 9 in the array
        cout << "\nFound at\t:\t "<< (lower_bound(a , a + 6, 9) - a);  // print if function returns True
    }
    else {
        cout << "\n9 not found\n";        // print if function returns False
    }
    cout << "\nLower Bound\t:\t" << (lower_bound(a , a + 6, 25) - a);  // Output ->  3
    cout << "\nLower Bound\t:\t" << (lower_bound(a , a + 6, 20) - a);  // Output ->  1
    cout << "\nUpper Bound\t:\t" << (upper_bound(a , a + 6, 35) - a);  // Output ->  4
    cout << "\nUpper Bound\t:\t" << (upper_bound(a , a + 6, 20) - a);  // Output ->  3
    cout << endl;
    return 0;
}
