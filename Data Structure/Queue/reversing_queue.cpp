//
//  reversing_queue.cpp
//  Problems
//
//  Created by Mohd Shoaib Rayeen on 04/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue <int> q;
void insert(int value) {
    q.push(value);
}

void Print()
{
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

void reverse(){
    stack <int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    Print();
}

void mainloop() {
    char choice;
    int value;
    bool done = true;
    while ( done ) {
        cout << "\n\t\tMenu";
        cout << "\n1. Insertion in Queue";
        cout << "\n2. Reversing Queue";
        cout << "\n3. Exit";
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice;
        switch (choice) {
            case '1':   cout << "\nEnter Value\t:\t";
                        cin >> value;
                        insert(value);
                        break;
            case '2':   reverse();
                        break;
            case '3':   done = false;
                        break;
            default:    cout << "\nWrong Input\n";
                break;
        }
    }
}
int main() {
    mainloop();
    return 0;
}
