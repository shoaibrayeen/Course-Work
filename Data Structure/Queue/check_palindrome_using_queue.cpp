//
//  check_palindrome_using_queue.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 09/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool checking_palindrome(string str) {
    queue<char> q;
    int length = str.length();
    int i;
    for (i = 0 ; i < length/2 ; ++i) {
        q.push(str[i]);
    }
    i = length - 1;
    while (!q.empty()) {
        if(q.front() == str[i] ){
            q.pop();
            --i;
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

