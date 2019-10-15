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

bool checking_palindrome(string str) {
    stack<char> s;
    queue<char> q;
    int length = str.length();
    for ( int i = 0 ; i < length ; ++i) {
        s.push(str[i]);
        q.push(str[i]);
    }
    while (!s.empty()) {
        if(s.top() == q.front()){
            s.pop();
            q.pop();
        }
        else {
            return false;
        }
    }
    return true;
}
int main() {
    string str;
    cout << "\nEnter String\t:\t";
    getline(cin,str);
    if(checking_palindrome(str)) {
        cout << "\nString is Palindrom.\n";
    }
    else {
        cout << "\nString is not Palindrom.\n";
    }
    return 0;
}
