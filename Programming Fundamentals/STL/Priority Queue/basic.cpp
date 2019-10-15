//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue <int> que) {
    priority_queue <int> i = que;                       // Creating Copy of Priority Queue
    while (!i.empty()) {
        cout << i.top() << "\t";                        // Displaying Priority Queue using its copy
        i.pop();
    }
}

int main() {
    priority_queue <int> temp;                          // Declaring Priority Queue
    temp.push(9);
    temp.push(2);                                       // Insert elements in the Priority queue
    temp.push(1);
    temp.push(3);
    cout << "\nPriority Queue\t:\t";
    showpq(temp);                                       // Output -> 9 , 3 , 2 , 1
    cout << "\nSize of Queue\t:\t" << temp.size();      // Output -> 4
    cout << "\nTop Element\t\t:\t" << temp.top();       // Output -> 9
    temp.pop();                                         // Popped Element -> 9
    cout << "\nPriority Queue\t:\t";
    showpq(temp);                                       // Output -> 3 , 2 , 1
    cout << endl;
    return 0;
}




/*
  Priority queues are a type of container adapters, specifically designed such that the first element of 
  the queue is the greatest of all elements in the queue and elements are in non decreasing order(hence 
  we can see that each element of the queue has a priority{fixed order}).
  The functions associated with priority queue are:
  empty() – Returns whether the queue is empty
  size() – Returns the size of the queue
  top() – Returns a reference to the top most element of the queue
  push(g) – Adds the element ‘g’ at the end of the queue
  pop() – Deletes the first element of the queue
*/
