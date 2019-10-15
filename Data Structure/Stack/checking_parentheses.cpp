//
//  checking_parentheses.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 07/02/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    /*
     objective : to check parentheses
     return value : none
     approach : using stack
     */
    
    stack<char> object;
    string str;
    cout << "\nEnter Parentheses\t:\t";
    getline(cin , str);
    int length=str.length();
    for ( int i=0 ; i < length ; ++i) {
        if(str[i]=='(') {
            object.push(str[i]);
        }
        else if (str[i]==')') {
            if(object.empty()) {
                cout << "\nParentheses are not balanced. \n";
                goto exit;
            }
            object.pop();
        }
    }
    if(object.empty()) {
        cout << "\nParentheses are balanced. \n";
    }
    else {
        cout << "\nParentheses are not balanced. \n";
    }
exit:
    return 0;
}
