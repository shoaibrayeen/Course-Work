//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include<iostream>
#include<forward_list>
using namespace std;
int main() {
    forward_list<int> list1;                                // Declaring forward list
    forward_list<int> list2;                                // Declaring another forward list
    list1.assign( { 1 , 2, 3 , 4 ,5 , 6 } );                // Assigning values using assign()
    list1.push_front(7);                                    // Inserts 7 at front
    list1.emplace_front(8);                                 // Inserts 8 at front
    list1.pop_front();                                      // deletes 8 from front
    // Assigning repeating values using assign()
    list2.assign(6, 2);                                     // (para1 = number of times , para2 = elements)
    cout << "\nThe first forward list\t:\t";                // Output -> 7 , 1 , 2 , 3 , 4 , 5 , 6
    for (int&i : list1) {
        cout << i << " \t";
    }
    cout << "\nThe second forward list\t:\t";               // Output -> 2 , 2 , 2 , 2 , 2 , 2
    for (int&j : list2) {
        cout << j << "\t";
    }
    cout << endl;
    return 0;
}


/*
    Operations on Forward List ->
    1. assign() :- This function is used to assign values to forward list, its another variant is used to assign repeated elements.
    2. push_front() :- This function is used to insert the element at the first position on forward list.
    3. emplace_front() : This function is similar to the previous function but in this no copying operation 
       occurs, the element is created directly at the memory before the first element of the forward list.
    4. pop_front() :- This function is used to delete the first element of list.
    5. insert_after() This function gives us a choice to insert elements at any position in forward list.
       The arguments in this function are copied at the desired position.
    6. emplace_after() This function also does the same operation as above function but the elements are
       directly made without any copy operation.
    7. erase_after() This function is used to erase elements from a particular position in the forward list.
    8. remove() :- This function removes the particular element from the forward list mentioned in its argument.
    9. remove_if() :- This function removes according to the condition in its argument.
    10. splice_after() :- This function transfers elements from one forward list to other.
*/
