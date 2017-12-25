#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

void encrypt(char *msg,int key,char *enc) {
	char al[26],a;
	int temp[26],i;
	for(a='A',i=0;a<='Z',i<26;a++,i++) {
		al[i]=a;
	}
	int l=strlen(msg);
	for(i=0;i<l;i++) {
		if(msg[i]==' ' || (msg[i]>='0' && msg[i]<='9')) {
			enc[i]=msg[i];
			continue;
		}
		temp[i]=(int)toupper(msg[i])-65;
		temp[i]=temp[i]+key;
		temp[i]=temp[i]%26;
		enc[i]=al[temp[i]];
	}
	enc[i]='\0';
}

void decrypt(char *enc,int key,char *dec) {
	char al[26],a;
	int temp[26],i;
	for(a='A',i=0;a<='Z',i<26;a++,i++) {
		al[i]=a;
	}
	int l=strlen(enc);
	for(i=0;i<l;i++) {
		if(enc[i]==' ' || (enc[i]>='0' && enc[i]<='9')) {
			dec[i]=enc[i];
			continue;
		}
		if(((int)enc[i]-65-key)>=0) {
			temp[i]=((int)enc[i]-65-key)%26;
		}
		else {
			temp[i]=((int)enc[i]-65-key)+26;
		}
		dec[i]=al[temp[i]];
	}
	dec[i]='\0';
}

int main() {
	int key,i;
	char a;
	char msg[100],enc[100],dec[100];
	cout<<"Enter the message to be encrypted :";
	gets(msg);
	cout<<"Enter the key :";
	cin>>key;
	encrypt(msg,key,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,key,dec);
	int l=strlen(dec);
	for(i=0;i<l;i++) {
		dec[i]=tolower(dec[i]);
	}
	cout<<"The decrypted message is :"<<(dec)<<endl;
	return 0;
}
