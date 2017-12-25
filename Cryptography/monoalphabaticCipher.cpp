//mono alphabetic substitution cipher
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
void encrypt(char *msg,char *sub,char *enc) {
	int i,l=strlen(msg);
	for(i=0;i<l;i++) {
		if(msg[i]==' ' || (msg[i]>='0' && msg[i]<='9')) {
			enc[i]=msg[i];
			continue;
		}
		enc[i]=sub[((int)toupper(msg[i])-65)];
	}
	enc[i]='\0';
}

int index(char a,char *sub) {
	int l=strlen(sub);
	for(int i=0;i<l;i++) {
		if(a==sub[i]) {
			return i;
		}
	}
}

void decrypt(char *enc,char *sub,char *dec) {
	int i,l=strlen(enc);
	for(i=0;i<l;i++) {
		if(enc[i]==' ' || (enc[i]>='0' && enc[i]<='9')) {
			dec[i]=enc[i];
			continue;
		}
		dec[i]=(char)(65+index(enc[i],sub));
	}
	dec[i]='\0';
}

int search(char *sub,int k) {
	for(int i=0;i<=k;i++) {
		if(sub[i]==sub[k+1]) {
			cout<<(char)tolower(sub[k+1])<<" already substituted for "<<sub[i]<<endl;
			return -1;
		}
	}
	return 1;
}

int main() {
	char msg[100],enc[100],dec[100];
	char sub[26];
	int i=0;
	cout<<"Enter the message to be encrypted :";
	gets(msg);
	cout<<"Enter the substitution alphabets"<<endl;
	for(char a='A';a<='Z';a++) {
		do {
			cout<<a<<"    :";
			cin>>sub[i];
			sub[i]=toupper(sub[i]);
		}
		while(search(sub,i-1)!=1);
		i++;
	}
	encrypt(msg,sub,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,sub,dec);
	cout<<"The decrypted message is :"<<dec<<endl;
	return 0;
}
