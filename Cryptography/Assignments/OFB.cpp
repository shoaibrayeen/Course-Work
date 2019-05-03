//
//  OFB.cpp
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
string outputFeedbackMode(string message, string key, string iv);

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
    cout <<  "\nOutput Feedback Mode\n\n";
    string input = "0123456789ABCDEFFEDCBA9876543210" , key="133457799BBCDFF1", iv = "2819F59C1D58D750", result;
   	cout << "\n\nEnter message in Hexa Decimal\t:\t";
   	cin >> input;
   	cout << "\nPlain Text\t:\t" << input << endl;
    cout << "\nKey\t:\t" << key << endl;
    cout << "\nInitialzation Vector\t:\t" << iv << endl;
    cout << endl;
    result = outputFeedbackMode(input, key, iv);
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


string outputFeedbackMode(string message, string key, string iv) {
    string block;
    string encrypted_msg;
    string encrypted_block;
    string hex_encrypted_msg;
	message = toBinary(message, message.length());
	iv = toBinary(iv, iv.length());
	int length = message.length();
	int iv_length = iv.length();

    int rounds = static_cast<int>(ceil(message.length() / static_cast<double>(iv_length)));
	int pad_num = iv_length - (message.length() % iv_length);
	string pad;
	for(int i =  0; i < pad_num; i++)
        pad.append("0");
    if(!pad.empty())
        message = message.append(pad);

    for( int i = 0; i < rounds; i++) {
        encrypted_block=des_process(iv,key,true);
        block = message.substr(i*iv_length,iv_length);
        iv = encrypted_block;
        encrypted_msg = xored_msg(block, encrypted_block);
        string hex_conv=hex_conversion(encrypted_msg,conv_table,hex_table);
        hex_encrypted_msg.append(hex_conv);

    }
    return hex_encrypted_msg;
}



