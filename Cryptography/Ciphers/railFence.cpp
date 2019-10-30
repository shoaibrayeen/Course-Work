#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char pt[50],ct[50],temp[50],rf[2][25];
int si[10];
int l,c,a=0,m=0;

void encrypt() {
	if(l%2==0) {
		c=l/2;
	}
	else {
		temp[l]='$';
		c=l/2 +1;
	}
	for(int j=0;j<c;j++) {
		rf[0][j]=temp[a];
		rf[1][j]=temp[a+1];	
		a=a+2;
	}
	a=0;
	cout<<"\n\nThe Plain Text Matrix\n";
	for(int i=0;i<2;i++) {
		for(int j=0;j<c;j++) {
			if(rf[i][j]!='$') {
				cout<<rf[i][j]<<"\t";
			}
		}
		cout<<"\n";
	}
	cout<<"\nThe Encrypted code is\t\t:\t";
	for(int i=0;i<2;i++) {
		for(int j=0;j<c;j++) {
			if(rf[i][j]!='$') {
				if(rf[i][j]>='a' && rf[i][j]<='z' || rf[i][j]>='A' && rf[i][j]<='Z') 
					ct[a++]=rf[i][j]-32;
				else
					ct[a++]=rf[i][j];
			}
		}
	}	
	ct[a]='\0';
	for(int i=0;i<strlen(ct);i++) {
		if(i%5==0)
			cout<<" ";
		cout<<ct[i];
	}	
}

void decrypt() {
	if(l%2!=0) {
		ct[l]='$';
	}
	a=0;
	for(int i=0;i<2;i++) {
    		for(int j=0;j<c;j++) {
			if(ct[a]>='a' && ct[a]<='z' || ct[a]>='A' && ct[a]<='Z') 
				rf[i][j]=ct[a++]+32;
			else
				rf[i][j]=ct[a++];
		}
	}
	a=0;
	int k=0;
	for(int i=0;i<c;i++) {
		for(int j=0;j<2;j++) {
			temp[a++]=rf[j][i];
		}
	}	
	if(l%2!=0)
		a=a-1;
	temp[a]='\0';
	cout<<"\nThe Decrypted code is\t\t:\t";
	for(int i=0;i<strlen(temp);i++) {
		if(i%5==0)
			cout<<" ";
		cout<<temp[i];
	}
}

int main() {
	cout<<"\nEnter the Plain Text\t\t:\t";
	gets(pt);
	l=0;
	for(int i=0;pt[i]!='\0';i++) {
		if(pt[i]!=' ')
			temp[l++]=pt[i];
	}
	temp[l]='\0';
	encrypt();
	decrypt();
	return 0;
}
