#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int index(char *random,char a) {
	for(int i=0;i<26;i++) {
		if(random[i]==a)
			return i;
	}
	return -1;
}
void encrypt(char *mes,char *random,char *enc) {
	int i,in,l=strlen(mes);
	for(i=0;i<l;i++) {
		in=((int)toupper(mes[i])-65);
		if(in>=0 &&in<=25)
			enc[i]=random[in];
		else
			enc[i]=mes[i];
	}
	cout<<endl;
	enc[i]='\0';
}

void decrypt(char *enc,char *random,char *dec) {
	int i,j,l=strlen(enc);
	for(i=0;i<l;i++) {
		j=index(random,enc[i]);
		if(j==-1)
			dec[i]=enc[i];
		else
			dec[i]=char(j+97);
	}
	dec[i]='\0';
}

int search(char *sub,char b,int size) {
	for(int i=0;i<size;i++) {
		if(sub[i]==b)
			return 1;
	}
	return 0;
}

int main() {
	char mes[100],enc[100],dec[100],key[100],sub[27];
	cout<<"Enter the message to be encrypted :";
	gets(mes);
	cout<<"Enter the key :";
	cin>>key;
	int i,size=0,l=strlen(key),s;
	for(i=0;i<l;i++) {
		char a=key[i];
		a=toupper(a);
		s=search(sub,a,size);
		if(s==0)
			sub[size++]=a;
	}
	char b='A';
	while(size<=25) {
		s=search(sub,b,size);
		if(s==0)
			sub[size++]=b++;
		else
			b++;
	}
	sub[size]='\0';
	cout<<"The substitution alphabets are as follows"<<endl;
	for(b='A';b<='Z';b++)
		cout<<b<<"  ";
	cout<<endl;
	for(i=0;i<size;i++)
		cout<<sub[i]<<"  ";
	cout<<endl;
	encrypt(mes,sub,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	decrypt(enc,sub,dec);
	cout<<"The decrypted message is :"<<dec<<endl;
	return 0;
}
