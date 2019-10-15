

//
//  code_1.cpp
//  Quiz
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int getRemainder(int num, int divisor) {
    return (num - divisor * (num / divisor));
}

int main() {
    int num , div;
    cout << "\nEnter Number\t:\t";
    cin >> num;
    cout << "\nEnter Divisor\t:\t";
    cin >> div;
    cout << "\nReminder\t:\t" << getRemainder(num, div) << "\n";
    return 0;
}
