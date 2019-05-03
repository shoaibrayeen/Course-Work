//
//  RSA.cpp
//  Information Secuirty
//
//  Created by Mohd Shoaib Rayeen on 17/04/19.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
 
using namespace std;
 
long int p, q, n, t, e[100], d[100], temp[100], m[100], en[100];
char msg[100];
bool prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

bool prime(long int pr) {
    int j = sqrt(pr);
    for (int i = 2; i <= j; i++) {
        if (pr % i == 0)
            return false;
    }
    return true;
}
int main() {
    cout << "\nEnter Prime Number - P\t:\t";
    cin >> p;
    if (!prime(p)) {
        cout << "\nInvalid Input. Please Try Again.\n";
        exit(1);
    }
    cout << "\nEnter Another Prime Number - Q\t:\t";
    cin >> q;
    if (!prime(q)) {
        cout << "\nInvalid Input. Please Try Again.\n";
        exit(1);
    }
    cout << "\nEnter Message To be Encrypted(WITHOUT SPACE)\t:\t";
    fflush(stdin);
    cin >> msg;
    for (int i = 0; i < strlen(msg); i++) {
        m[i] = msg[i];
    }
    n = p * q;
    t = (p - 1) * (q - 1);
    cout << "\nValue of P\t:\t" << p;
    cout << "\nValue of Q\t:\t" << q;
    cout << "\nValue of N = (P*Q)\t:\t" << n;
    cout << "\nValue of Phi(N)\t:\t" << t;
    ce();
    cout << "\nAll Possible Values of E and D\n";
    for (int i = 0; i < sqrt(t) - 1; i++) {
        cout << e[i] << "\t" << d[i] << "\n";
    }
    encrypt();
    cout << endl;
    decrypt();
    cout << endl;
    return 0;
}

void ce() {
    int k = 0;
    for (int i = 2; i < t; i++) {
        if (t % i == 0) {
            continue;
        }
        if (prime(i) && i != p && i != q) {
            e[k] = i;
            int flag = cd(e[k]);
            if (flag > 0) {
                d[k] = flag;
                k++;
            }
            if (k == 99) {
                break;
            }
        }
    }
}
long int cd(long int x) {
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0) {
            return (k / x);
        }
    }
}

void encrypt() {
    long int pt, ct, key = e[0], k, len;
    int i = 0;
    len = strlen(msg);
    while (i != len) {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (int j = 0; j < key; j++) {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nCipher Text\t:\t";
    for (int i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
}

void decrypt() {
    long int pt, ct, key = d[0], k;
    int i = 0;
    while (en[i] != -1) {
        ct = temp[i];
        k = 1;
        for (int j = 0; j < key; j++) {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\nPlain Text\t:\t";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);
}
