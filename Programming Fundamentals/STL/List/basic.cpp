//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <list>
#include <iterator>
using namespace std;
void showlist(list <int> list1) {
    list <int> :: iterator it;                        // Declaring Iterator of the list
    for(it = list1.begin(); it != list1.end(); ++it) {
        cout << *it << "\t";
    }
}

int main() {
    list <int> list1;                                 // Declaring List
    for (int i = 1; i < 4; ++i) {
        list1.push_back(i);                           // Insert at back
        list1.push_front(i*5);                        // Insert at front
    }                                                 // List after insertion -> 15    10    5    1    2    3
    cout << "\nFront Element\t\t:\t" << list1.front();// Output -> 15
    cout << "\nBack Element\t\t:\t" << list1.back();  // Output -> 3
    list1.pop_front();                                // Popped Element -> 15
    list1.pop_back();                                 // Popped Element -> 3
    list1.reverse();                                  // Output -> 2   1   5   10
    list1.sort();                                     // Output -> 1   2   5   10
    cout << "\nPrint Final List\t:\t";
    showlist(list1);
    cout << endl;                                     // Final Output -> 1 , 2 , 5 , 10
    return 0;
    
}


/*
  Functions used with List :
  front() – Returns the value of the first element in the list
  back() – Returns the value of the last element in the list
  push_front(g) – Adds a new element ‘g’ at the beginning of the list 
  push_back(g) – Adds a new element ‘g’ at the end of the list
  pop_front() – Removes the first element of the list, and reduces size of the list by 1
  pop_back() – Removes the last element of the list, and reduces size of the list by 1
  begin() – Returns an iterator pointing to the first element of the list
  end() – Returns an iterator pointing to the theoretical last element which follows the last element
  empty() – Returns whether the list is empty(1) or not(0)
  insert() – Inserts new elements in the list before the element at a specified position
  erase() – Removes a single element or a range of elements from the list
  assign() – Assigns new elements to list by replacing current elements and resizes the list
  remove() – Removes all the elements from the list, which are equal to given element
  reverse() – Reverses the list
  size() – Returns the number of elements in the list
  sort() – Sorts the list in increasing order
*/
