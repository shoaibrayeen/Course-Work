#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

char table[26][26];
char pt[50],key1[30],key[50],ct[50];
int l;

void encrypt() {
	for(int i=0;i<l;i++) {
		if( isalpha(pt[i]) ) {
			int temp=table[key[i]-97][pt[i]-97]-32;
		   	ct[i]=char(temp);
	    	}
	    	else {
	    		ct[i]=pt[i];
	    	}
	}
	ct[l]='\0';
	cout << "\nEncrypted Code\t\t:\t";	
	for(int i=0;i<strlen(ct);i++) {
		if(i%5==0) {
			cout << " ";
		}
		cout << ct[i];
	}	
}

void decrypt() {
	int k;
	for(int i=0;i<l;i++) {
		if(isalpha(ct[i])) {
		   	for(int j=0;j<26;j++) {
				if(table[key[i]-97][j]==ct[i]+32) {
			      		k=j;
		      			break;
		      		}
		   	}
		  	pt[i]=char(k+97);
	    	}
	    	else {
	      		pt[i]=ct[i];
		}
	}
	cout << "\nThe Decrypted Code\t:\t";
	for(int i=0;i<strlen(pt);i++) {
		if(i%5==0) {
			cout<<" ";
		}
		cout<<pt[i];
	}
}

int main() {
	cout << "\nEnter the Plain Text\t:\t";
	gets(pt);
	cout << "\nEnter the Key\t\t:\t";
	gets(key1);
	int a=0,b=0;
	l=strlen(pt);
	int k=0;
	char temp[50];
	for(int i=0;i<l;i++) {
		if(pt[i]!=' ') {
			temp[k++]=pt[i];
		}
	}
	temp[k]='\0';
	strcpy(pt,temp);
	l=strlen(pt);
	for(int i=0;i<l;i++) {
		if(key1[b]!=' ') {
			key[a++]=key1[b++];
			if(b%strlen(key1)==0)
		   	b=0;
		}
		else {
			b++;
		}
	}
	for(int i=0;i<26;i++) {
		for(int j=0;j<26;j++) {
			table[i][j]=char((i+j)%26+97);
		}
	}
	cout << "\n-----------------The Vignere Table------------------------\n";
	cout << "\n------------------------------------------------------------------------------------------------------------------\n";
	cout << "\t";
	for(int i=0;i<26;i++) {
		cout << char(97+i) << "   ";
	}
	cout << "\n------------------------------------------------------------------------------------------------------------------\n";
	for(int i=0;i<26;i++) {
		cout << char(65+i) << "\t";
		for(int j=0;j<26;j++) {
			cout << table[i][j] << "   ";
		}
		cout << "\n";
	}
	cout << "\nThe Plain Text\t\t:\t";
	for(int i=0;i<strlen(pt);i++) {
		if(i%5 == 0) {
			cout << " ";
		}
		cout << pt[i];
	}
	cout << "\nUser Key\t\t:\t";
	for(int i=0;i<strlen(key);i++) {
		if(i%5==0) {
			cout<<" ";
		}
		cout << key[i];
	}
	encrypt();
	decrypt();
	return 0;
}
