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
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating a class for checking that stack is containing consecutive pair or not.
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines two member functions which can be accessed publicly such as :-
                     consecutive_pair() which checks consecutive pair in the stack using queue.
                     main_q2() which calls member functions.
     
     ------------------------------------------------------------------------------------------------
     */
    public:
    bool consecutive_pair(stack<int>);
    void main_q2();
};

bool check_pair::consecutive_pair(stack<int> s){
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : checking stack is containing consecutive_pair or not
     
     ------------------------------------------------------------------------------------------------
     input parameter : external stack
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : 'true' if stack contains consecutive pair otherwise 'false'
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  The function performs following operations :-
                    1. if size of stack is odd ,then pop top of stack.
                    2. Pushing top of stack into queue.
                    3. popping one element from stack
                    4. Now comparing element at top of stack to element at front of queue
                    5. if they are either in increasing order or decreasing order , then pop from stack
                       and dequeue from queue
                    6. repeat step 1 to 5 if they are either in increasing order or decreasing order till
                       stack is not empty and return true otherwise return false
     
     ------------------------------------------------------------------------------------------------
     */
    
    queue <int> q;
    if(s.empty()) {
        return false;
    }
    while(!s.empty()) {
        if( (s.size() % 2 ) != 0 ) {
            s.pop();
            if(s.empty()) {
                return false;
            }
        }
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
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective :    inserting element in stack and calling member function
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  The function performs following operations :-
                    1. using external stack for insertion
                    2. calling member functions except this function
                    3. exiting from the program
     
     ------------------------------------------------------------------------------------------------
     */
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
            case '1' :  cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        s.push(temp);
                        break;
            case '2' :   if(consecutive_pair(s)) {
                            cout << "\nStack contains consecutive numbers.\n";
                        }
                        else {
                            cout << "\nStack does not contain consecutive numbers.\n";
                        }
                        while(!s.empty()) {
                            s.pop();
                        }
                        break;
            case '3' :  done = false;
                        break;
            case '4' :  exit(0);
            default:    cout << "\nInvalid Input\n";
        }
    }
}

