//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

void showdq(deque <int> g) {
    deque <int> :: iterator it;                        // Initializing Iterator
    for (it = g.begin(); it != g.end(); ++it) {
        cout << *it << "\t";                           // Displaying using iterators
    }
}

int main() {
    deque <int> temp;                                  // Declaring Deque
    temp.push_back(1);                                 // Inserting elements at back
    temp.push_back(2);
    temp.push_front(3);                                // Inserting elements at front
    temp.push_front(5);
    cout << "\nDeque\t\t\t:\t";
    showdq(temp);                                      // Output -> 5 , 3 , 1 , 2
    cout << "\nSize of Deque\t:\t" << temp.size();     // Output -> 4
    cout << "\n3rd Element\t\t:\t" << temp.at(2);      // Output -> 1
    cout << "\nFront Element\t:\t" << temp.front();    // Output -> 5
    cout << "\nBack Element\t:\t" << temp.back();      // Output -> 2
    cout << "\nDeque\t\t\t:\t";
    temp.pop_front();                                  // Popped -> 5
    temp.pop_back();                                   // Popped -> 2
    showdq(temp);                                      // Output -> 3 , 1
    cout << endl;
    return 0;
}

/*
  deque (usually pronounced like "deck") is an irregular acronym of double-ended queue. 
  Double-ended queues are sequence containers with dynamic sizes that can be expanded or 
  contracted on both ends (either its front or its back).
*/
