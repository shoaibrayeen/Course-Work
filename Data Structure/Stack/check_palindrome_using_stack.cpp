//
//  check_palindrome_using_stack.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 09/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checking_palindrome(string str) {
    stack<char> s;
    int length = str.length();
    int i;
    for (i = 0 ; i < length/2 ; ++i) {
        s.push(str[i]);
    }
    i = length/2;
    if (length % 2 != 0) {
        i++;
    }
    while (!s.empty()) {
        if(s.top() == str[i] ){
            s.pop();
            ++i;
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

