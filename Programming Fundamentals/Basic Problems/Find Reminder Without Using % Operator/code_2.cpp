//
//  code_2.cpp
//  Quiz
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int getRemainder(int num, int divisor) {
    int i = 1;
    int product = 0;
    while (product <= num) {
        product = divisor * i;
        i++;
    }
    return num - (product - divisor);
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
