#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int r,c,l,b=0,a=0,m=0,round;
char pt[50],ct[50],temp[50],ec[10][10],dc[10][10];

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
	for(int q=0;q<round;q++) {	
		b=0,a=0;
		if(q!=0) {
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
			   		ec[i][j]=temp[b++];
				}
			}
		}
		cout << "\n\nThe Plain Text Matrix\n";
		cout << "\n" << q+1 << " Iteration\n";
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {	
				cout << ec[i][j] << "\t";
			}	
			cout << "\n";
		}
		for(int i=0;i<c;i++) {
			for(int j=0;j<r;j++) {
				ct[a++]=ec[j][i];
			}
		}	
		strcpy(temp,ct);
	}
	cout << "\nThe Encrypted code is\t\t:\t";	
	ct[a]='\0';
	for(int i=0;i<a;i++) {
		if(ct[i]>='a' && ct[i]<='z' || ct[i]>='A' && ct[i]<='Z')  {
			ct[i]=ct[i]-32;
		}
	}
	for(int i=0;i<strlen(ct);i++) {
		if(i%5==0) {
			cout << " ";
		}
		cout << ct[i];
	}	
}


void decrypt() {
	for(int q=0;q<round;q++) {
		a=0;
		for(int i=0;i<c;i++) {
    			for(int j=0;j<r;j++) {
				dc[j][i]=ct[a++];
			}
		}
		cout << "\n\nThe Cipher Text Matrix\n";
		cout << "\nFor " << q+1 << " Iteration\n";
		for(int i=0;i<c;i++) {
			cout << "\n";
    			for(int j=0;j<r;j++) {
					cout << dc[j][i] << "\t";
			}
		}
		a=0;
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				temp[a++]=dc[i][j];
			}
		}
		strcpy(ct,temp);
		ct[a]='\0';
	}
	l=strlen(ct);
	cout << "\nThe Decrypted code is\t\t:\t";
	for(int i=0;i<l;i++) {
		if(ct[i]>='a' && ct[i]<='z' || ct[i]>='A' && ct[i]<='Z') {
			ct[i]=ct[i]+32;
		}
		else if(ct[i]=='$') {
			ct[i]='\0';
		}
	}
	for(int i=0;i<strlen(ct);i++) {
		if(i%5==0) {
			cout << " ";
		}
		cout << ct[i];
	}	
}

int main() {
	cout << "\nEnter the Plain Text\t\t:\t";
	gets(pt);
	cout << "\nEnter the Number of Column\t:\t";
	cin >> c;
	cout << "\nEnter Number of Round\t\t:\t";
	cin >> round;
	l=0;
	for(int i=0;pt[i]!='\0';i++) {
		if(pt[i]!=' ') {
			temp[l++]=pt[i];
		}
	}
	temp[l]='\0';
	encrypt();
	decrypt();
	return 0;
}
