//
//  hillCipher.cpp
//  Information Secuirty
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int ct[50],pt[50];
int det;

void encrypt_hill(char a[50],int l,int k[3][3]) {
    int ch[50];
    int a1,b,c,x,y,z;
    for(int i = 0; i < l; i++) {
        ch[i]=char(a[i]);
    }
    for(int i = 0; i < l; i += 3 ) {
        x=(ch[i]-65)%26;
        y=(ch[i+1]-65)%26;
        z=(ch[i+2]-65)%26;
        a1=x*k[0][0]+y*k[1][0]+z*k[2][0];
        b=x*k[0][1]+y*k[1][1]+z*k[2][1];
        c=x*k[0][2]+y*k[1][2]+z*k[2][2];
        a1=(a1%26)+65;
        b=(b%26)+65;
        c=(c%26)+65;
        ct[i]=a1;
        ct[i+1]=b;
        ct[i+2]=c;
        cout<<char(ct[i])<<char(ct[i+1])<<char(ct[i+2]);
    }
}

void decrypt_hill(int k[3][3],int l) {
    int ad[3][3],ads[3][3];
    int a,b,c,x,y,z,det_inv = 0;
    for(int i = 0; i < 26; i++) {
        if((det*i)%26==1) {
            det_inv = i;
            break;
        }
    }
    cout << "\nMultiplicative Inverse\t:\t" << det_inv << endl;
    ad[0][0]=((k[1][1]*k[2][2]-k[2][1]*k[1][2])*det_inv)%26;
    ad[0][1]=((-(k[1][0]*k[2][2]-k[1][2]*k[2][0]))*det_inv)%26;
    ad[0][2]=((k[1][0]*k[2][1]-k[1][1]*k[2][0])*det_inv)%26;
    ad[1][0]=((-(k[0][1]*k[2][2]-k[0][2]*k[2][1]))*det_inv)%26;
    ad[1][1]=((k[0][0]*k[2][2]-k[0][2]*k[2][0])*det_inv)%26;
    ad[1][2]=((-(k[0][0]*k[2][1]-k[0][1]*k[2][0]))*det_inv)%26;
    ad[2][0]=((k[0][1]*k[1][2]-k[0][2]*k[1][1])*det_inv)%26;
    ad[2][1]=((-(k[0][0]*k[1][2]-k[0][2]*k[1][0]))*det_inv)%26;
    ad[2][2]=((k[0][0]*k[1][1]-k[0][1]*k[1][0])*det_inv)%26;
    cout << "\nInverse of Matrix\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(ad[i][j]<0)
            ad[i][j]=ad[i][j]+26;
        }
        cout<<endl;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            ads[i][j] = ad[j][i];
            cout << ads[i][j] << "\t";
        }
        cout<<endl;
    }
    for(int i = 0; i < l; i += 3) {
        x=ct[i]-65;
        y=ct[i+1]-65;
        z=ct[i+2]-65;
        a=x*ads[0][0]+y*ads[1][0]+z*ads[2][0];
        b=x*ads[0][1]+y*ads[1][1]+z*ads[2][1];
        c=x*ads[0][2]+y*ads[1][2]+z*ads[2][2];
        a=(a%26)+65;
        b=(b%26)+65;
        c=(c%26)+65;
        pt[i]=a;
        pt[i+1]=b;
        pt[i+2]=c;
        cout << "\nDecrypted Message\t:\t";
        cout << char(pt[i]) << char(pt[i+1]) << char(pt[i+2]);
    }
    cout <<  endl;
}


int main() {
    cout << "\nEnter the key matrix of order 3*3"<<endl;
    int k[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> k[i][j];
        }
    }
    bool flag = true;
    while(flag) {
        cout << "Enter the plain text in multiples of 3 in block letters"<<endl;
        char a[50];
        cin >> a;
        int l = int(strlen(a));
        det = k[0][0]*(k[1][1]*k[2][2]-k[1][2]*k[2][1])-k[0][1]*(k[1][0]*k[2][2]-k[2][0]*k[1][2])+k[0][2]*(k[1][0]*k[2][1]-k[1][1]*k[2][0]);
        det = det%26;
        if(det < 0) {
            det += 26;
        }
        if(det != 0) {
            cout << "\nEncrypted Message\t:\t";
            encrypt_hill( a , l , k);
            decrypt_hill(k,l);
        }
        else {
            cout <<"\nDeterminant is zero. Cant't proceed further\n" << endl;
        }
        char ch;
        cout << "\nDo you want to continue - y|Y -> Yes or n|N ->No\n";
        cin >> ch;
        if ( ch == 'y' || ch == 'Y') {
            continue;
        }
        flag = false;
    }
    return 0;
}

