//
//  q2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class check_pair {
    public:
    bool consecutive_pair(stack<int>);
    void main_q2();
};

bool check_pair::consecutive_pair(stack<int> s){
    queue <int> q;
    if( (s.size() % 2 ) != 0 ) {
        s.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        if( s.top() == q.front() + 1  || s.top() + 1 == q.front()){
            s.pop();
            q.pop();
        }
        else {
            return false;
        }
    }
    return true;
}

void check_pair::main_q2() {
    stack <int> s;
    int temp;
    bool done = true;
    while(done) {
        cout << "\n\n----------Consecutive Pair Menu-----------\n";
        cout << "\n1.Push\n2.Check\n3.Go to Main Menu\n4.Exit\n";
        char choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case '1' :    cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        s.push(temp);
                        break;
            case '2' :    if(consecutive_pair(s)) {
                            cout << "\nStack contains consecutive numbers.\n";
                        }
                        else {
                            cout << "\nStack does not contain consecutive numbers.\n";
                        }
                        break;
            case '3' :  done = false;
                        break;
            case '4' :  exit(0);
            default:    cout << "\nInvalid Input\n";
        }
    }
}

