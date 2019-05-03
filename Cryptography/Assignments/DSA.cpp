//
//  DSA.cpp
//  Information Secuirty
//
//  Created by Mohd Shoaib Rayeen on 17/04/19.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

long long gcd(long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long find_inverse(long long P, long long K) {
    long long a = K, b = P - 1, x, y;
    gcd(a, b, x, y);
    return x;
}


struct Signature {
    long long a, b;

    Signature() {}
    Signature(long long _a, long long _b): a(_a), b(_b) {}
};


long long pow_mod(long long x, long long y, long long m) {
    long long res = 1;

    while (y != 0) {
        res *= x;
        res %= m;

        y--;
    }
    return res;
}


long long get_mod() {
    int P;
    cin >> P;
    return P;
}

long long get_rand_numb() {
    int G;
    cin >> G;
    return G;
}

long long get_secret_key() {
    long long X;
    cin >> X;
    return X;
}

long long generate_public_key(long long P, long long G, long long X) {
    return pow_mod(G, X, P);
}


long long get_message() {
    long long m;
    cin >> m;
    return m;
}

long long generate_hash(long long m) {
    return m;
}

long long get_session_key() {
    long long K;
    cin >> K;
    return K;
}


Signature generate_signature(long long P, long long G, long long K, long long M, long long X) {
	cout<<"\nSignature Generation\n\n";
    long long K_ = find_inverse(P, K); 
    long long a = pow_mod(G, K, P);
    long long b = (M - X * a) * K_ % (P - 1);
    if (b < 0) {
        b += P - 1;
    }
    return Signature(a, b);
}

bool check_signed_message(long long P, long long G, long long m, Signature S, long long Y) {
	cout << "\n-----------------------Verification----------------------------------\n\n";
    long long M = generate_hash(m);

    long long a = (pow_mod(Y, S.a, P) * pow_mod(S.a, S.b, P)) % P;
    long long b = pow_mod(G, M, P);

    return a == b;
}


void task_generate_public_key(long long &P , long long &G , long long &X , long long &Y ) {
	cout<<"\n----------------------------Key Generation---------------------------\n\n";
    cout << "\nEnter P(Mod Number)\t:\t";
    P = get_mod();

    cout << "\nEnter Random Number G < P\t:\t";
    G = get_rand_numb();

    cout << "\nEnter Secret Key X. 1 < X < (P - 1)\t:\t";
    X = get_secret_key();
    Y = generate_public_key(P, G, X);
    cout << "\nValue of P(Mod)\t:\t" << P << endl
         << "Value of Random Number\t:\t" << G << endl
         << "Secret Key\t:\t " << X << endl
         << "Public Key\t:\t" << Y << endl;
}

void task_generate_signature(long long& P , long long &G , long long &X) {
	cout<<"\n\n---------------------Signature Generation---------------------------\n\n";
    /*
    cout << "\nEnter P(Mod Number)\t:\t";
    P = get_mod();
    cout << "\nEnter Random Number G < P\t:\t";
    G = get_rand_numb();
    */
    cout << "\nEnter Session Key K. 1 < K < (P - 1).\nK and P-1 are relatively prime\t:\t";
    long long K = get_session_key();
    /*
    cout << "\nEnter Secret Key X. 1 < X < (P - 1)\t:\t";
    X = get_secret_key();
    */
    cout << "\nEnter Message in Integer\n";
    long long m = get_message();

    long long M = generate_hash(m);
    cout << "\nPrime Number , Random Number and Secret key are same which You have Entered in Key Generation Phase.\n";
    cout << "\nYou can take User Input for them. Just to go Function and Remove Comments.\n\n";

    Signature S = generate_signature(P, G, K, M, X);
    cout << "\nValue of P(Mod)\t:\t" << P << endl
         << "Value of Random Number\t:\t" << G << endl
         << "Secret Key\t:\t " << X << endl
         << "Session Key\t:\t " << K << endl
         << "Message\t:\t" << m << endl
         << "Signature (A, B)\t:\t" << S.a << "\t" << S.b << endl;
}

void task_check_signature(long long& P , long long &G , long long& Y) {
    cout << "\nPrime Number , Random Number and Public key are same which You have Entered in Key Generation Phase.\n";
    cout << "\nYou can take User Input for them. Just to go Function and Remove Comments.\n\n";
    /*
    cout << "\nEnter P(Mod Number)\t:\t";
    P = get_mod();

    cout << "\nEnter Random Number G < P\t:\t";
    G = get_rand_numb();

    cout << "\nEnter Public Key\t:\t";
    cin >> Y;
    */

    cout << "\nEnter Message\t:\t";
    long long m;
    cin >> m;
    cout << "\nEnter signature (A, B)\t:\t";
    Signature S;
    cin >> S.a >> S.b;

    bool check = check_signed_message(P, G, m, S, Y);
    if (check) {
        cout << "For message " << m << " signature " << S.a << " " << S.b << " is confirmed\n";
    }
    else {
        cout << "For message " << m << " signature " << S.a << " " << S.b << " is not confirmed\n";
    }
}


int main() {
    int act = 1;
    long long P , G , X , Y;
	cout<<"\n\t\t\tDSA Algorithm\n\n";
    while (act != 0) {
        cout << "\n\t\tMenu\n"
             << "1. Generate public key\n"
             << "2. Generate signature\n"
             << "3. Check signature\n"
             << "0. Exit\n\n"
             << "Enter Your Choice\t:\t";

        cin >> act;
        cout << endl;

        if (act == 1) {
            task_generate_public_key(P , G , X , Y );
        }
        else if (act == 2) {
            task_generate_signature(P , G , X);
        }
        else if (act == 3) {
            task_check_signature(P , G , Y);
        }
        else if (act == 0) {
            continue;
        }
        else {
            cout << "\nInvalid Choice\n";
        }
        cout << endl;
    }

    return 0;
}
