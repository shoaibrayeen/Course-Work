#include<iostream>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

int code[26],l;

char pt[50],ct[50];

int search(int *a , int i,int k) {
	for(int j=0;j<i;j++) {
		if(a[j]==k) {
			return 0;
		}
	}
	return 1;
}

void encrypt() {
	cout << "\nChar\t:\tNumeric\t:\tRandom Key\n";
	for(int i=0;i<l;i++) {
		int num=pt[i]-97;
		if(pt[i]>='a' && pt[i]<='z') {
			cout << "\n" << pt[i] << "\t:\t" << num << "\t:\t" << code[num];
		}
		if(pt[i]>='a' && pt[i]<='z' ) {
			ct[i]=char(((num+code[num]) %26)+65);
		}
		else {
			ct[i]=pt[i];
		}
	}
	ct[l]='\0';
	cout << "\n\n\nEncypted Code\t:\t";
	for(int i=0;i<strlen(ct);i++) {
		if(i%5==0) {
			cout << " ";
		}
		cout<<ct[i];
	}	
}

void decrypt() {	
	for(int i=0;i<l;i++) {
		int num=ct[i]-65;
		if(ct[i]>='A' && ct[i]<='Z' ) {
			int k=num-code[pt[i]-97];
			while(k<0) {
				k+=26;
			}
			pt[i]=char(k+97);
		}
		else {
			pt[i]=ct[i];
		}
	}
	pt[l]='\0';
	cout << "\nDecrypted Code\t:\t";
	for(int i=0;i<strlen(pt);i++) {
		if(i%5==0) {
			cout<<" ";
		}
		cout<<pt[i];
	}	
}

int main() {
	cout<<"\nEnter the Plain Text\t:\t";
	gets(pt);
	l=strlen(pt);
	int p,k=0;
	char temp[50];
	for(int i=0;i<l;i++) {
		if(pt[i]!=' ') {
			temp[k++]=pt[i];
		}
	}
	temp[k]='\0';
	strcpy(pt,temp);
	for(int i=0;i<26;i++) {
		srand(time(NULL));
		k=rand()%100;
		while(search(code,i,k)==0) {
			k=rand()%100;
		}
		code[i]=k;
	}
	cout<<endl;
	encrypt();
	decrypt();
	return 0;
}
