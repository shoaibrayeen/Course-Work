//
//  CTR.cpp
//  Information Secuirty
//
//  Created by Mohd Shoaib Rayeen on 17/04/19.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
#include <cctype>
#include "des.h"

using namespace std;

string toBinary(string message, int length);
string counter(string message,string key);

string conv_table[23]={
   		"0000",
        "0001",
   		"0010",
   		"0011",
   		"0100",
   		"0101",
   		"0110",
   		"0111",
   		"1000",
   		"1001",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
        "1010",
   		"1011",
   		"1100",
   		"1101",
   		"1110",
   		"1111"
   };

   string hex_table[23]={
   		"0",
   		"1",
   		"2",
   		"3",
   		"4",
   		"5",
   		"6",
   		"7",
   		"8",
   		"9",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"A",
   		"B",
   		"C",
   		"D",
   		"E",
   		"F"
   };



int main() {
    cout<<"\nBlock Modes of Operation  -> DES\n\n";
    cout <<  "\nCounter Mode\n\n";
    string input = "0123456789ABCDEFFEDCBA9876543210" , key="133457799BBCDFF1", iv = "2819F59C1D58D750", result;
   	cout << "\n\nEnter message in Hexa Decimal\t:\t";
   	cin >> input;
   	cout << "\nPlain Text\t:\t" << input << endl;
    cout << "\nKey\t:\t" << key << endl;
    cout << "\nInitialzation Vector\t:\t" << iv << endl;
    cout << endl;
    result = counter(input, key);
    cout << "\nCipher Text\t:\t" << result << endl;
    cout << endl;
    return 0;
}

string toBinary(string message, int length) {
    string input;
    for(int i = 0; i < length; i++) { 
        int a = message[i] - '0';
        input = input + conv_table[a];
    }
    return input;
}

string counter(string message, string key) {
	string block;
    string encrypted_block;
    
	message = toBinary(message, message.length());
	
	int length = message.length();

    int rounds = static_cast<int>(ceil(message.length() / 64.0));
	int pad_num = 64 - (message.length() % 64);
	string pad;
	for(int i =  0; i < pad_num; i++)
        pad.append("0");
    if(!pad.empty())
        message = message.append(pad);


    for( int i = 0; i < rounds; i++) {
        block = message.substr(i*64,64);
        //block = xored_msg(block, iv);
        encrypted_block=des_process(block,key,true);
        encrypted_block = xored_msg(encrypted_block,block);
        //iv = encrypted_block;
    }
    string hex_resadue=hex_conversion(encrypted_block,conv_table,hex_table);


	return 	hex_resadue;
}

