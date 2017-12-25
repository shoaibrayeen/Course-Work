#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int r,c,l,b=0,a=0,m=0;
char pt[50],ct[50],temp[50],ec[10][10],dc[10][10];
int si[10],ko[10];

void encrypt() {
	if(l%c==0) {
		r=l/c;
	}
	else {
		r=l/c +1;
	}
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(temp[b]=='\0') {
				for(;j<c;j++) {
				   ec[i][j]='$';
				}
				break;
			}
			else {
			   	ec[i][j]=temp[b++];
			}
		}
	}
	cout << "\n\nThe Plain Text Matrix before Key Order\n";
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			cout << ec[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\n\nThe Plain Text Matrix After Key Order\n";
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			cout << ec[i][ko[j]] << "\t";
		}
		cout << "\n";
	}
	cout << "\nThe Encrypted code is\t\t:\t";
	for(int i=0;i<c;i++) {
		for(int j=0;j<r;j++) {
			if(ec[j][ko[i]]>='a' && ec[j][ko[i]]<='z' || ec[j][ko[i]]>='A' && ec[j][ko[i]]<='Z') {
				ct[a++]=ec[j][ko[i]]-32;
			}
			else {
				ct[a++]=ec[j][ko[i]];
			}
		}
	}	
	ct[a]='\0';
	for(int i=0;i<strlen(ct);i++) {
		if(i%5==0) {
			cout << " ";
		}
		cout << ct[i];
	}
}


void decrypt() {
	a=0;
	for(int i=0;i<c;i++) {
    		for(int j=0;j<r;j++) {
			if(ct[a]>='a' && ct[a]<='z' || ct[a]>='A' && ct[a]<='Z') {
				dc[j][ko[i]]=ct[a++]+32;
			}
			else {
				dc[j][ko[i]]=ct[a++];
			}
		}
	}
	a=0;
	int k=0;
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(dc[i][j]=='$') {
				continue;
			}
			temp[a++]=dc[i][j];
		}
	}	
	temp[a]='\0';
	cout << "\nThe Decrypted code is\t\t:\t";
	for(int i=0;i<strlen(temp);i++) {
		if(i%5==0) {
			cout << " ";
		}
		cout << temp[i];
	}
}

int main() {
	cout << "\nEnter the Plain Text\t\t:\t";
	gets(pt);
	cout << "\nEnter the Number of Column\t:\t";
	cin >> c;
	l=0;
	for(int i=0;pt[i]!='\0';i++) {
		if(pt[i]!=' ') {
			temp[l++]=pt[i];
		}
	}
	temp[l]='\0';
	int ab;
	cout << "\nEnter the Key Order\n";
	for(int i=0;i<c;i++) {
		cin >> ab;
		ko[i]=ab-1;
		
	}
	encrypt();
	decrypt();
	return 0;
}
