//
//  checking_palindrome_using_stack_And_queue.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 09/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int main() {
    stack<char> s;
    queue<char> q;
    string str;
    cout << "\nEnter String\t:\t";
    cin >> str;
    int length = str.length();
    for ( int i = 0 ; i < length ; ++i) {
        s.push(str[i]);
        q.push(str[i]);
    }
    bool flag = false;
    while (!s.empty()) {
        if(s.top() == q.front()){
            s.pop();
            q.pop();
        }
        else {
            cout << "\nString is not Palindrom.\n";
            flag = true;
            break;
        }
    }
    if( !flag ) {
        cout << "\nString is Palindrom.\n";
    }
    return 0;
}
