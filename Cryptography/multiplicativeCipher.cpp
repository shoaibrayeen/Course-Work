#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int modinverse(int a,int b) {
	for(int i=1;i<b;i++) {
		if((a*i)%b==1)
			return i;
	}
	return -1;
}

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
		temp[i]=temp[i]*key;
		temp[i]=temp[i]%26;
		enc[i]=al[temp[i]];
	}
	enc[i]='\0';
}

void decrypt(char *enc,int key,char *dec) {
	char al[26],a;
	int temp[26],i;
	int inverse=modinverse(key,26);
 
	for(a='A',i=0;a<='Z',i<26;a++,i++) {
		al[i]=a;
	}
	int l=strlen(enc);
	for(i=0;i<l;i++) {
		if(enc[i]==' ' || (enc[i]>='0' && enc[i]<='9')) {
			dec[i]=enc[i];
			continue;
		}
		temp[i]=( ( (int)enc[i]-65) *inverse  )%26;
		dec[i]=al[temp[i]] + 32;
	}
	dec[i]='\0';
}

int main() {
	int key,i;
	char a;
	char msg[100],enc[100],dec[100];
	cout<<"Enter the message to be encrypted :";
	gets(msg);
	cout<<endl<<endl<<"MULTIPLICATIVE FACTOR AND 26 SHOULD NOT HAVE A COMMON FACTOR"<<endl;
	cout<<"Enter the multiplicative key :";
	int inverse;
	cin>>key;
	inverse=modinverse(key,26);
	while(inverse==-1) {
		cout<<"Mod inverse 26 of "<<key<<" does not exist "<<endl;
		cout<<"Enter the key again :";
	 	cin>>key;
		inverse=modinverse(key,26);
	}
	encrypt(msg,key,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,key,dec);
	cout<<"The decrypted message is :"<<dec<<endl;
	int l=strlen(msg);
	return 0;
}
