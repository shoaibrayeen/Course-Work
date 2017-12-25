#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
void dtob(int n , char *msg) {
	int j=0;
	for(int i=n;i!=0;i=i/2) {
		if(i%2==0)
			msg[j++]='0';
		else
			msg[j++]='1';
	}
	msg[j]='\0';
	int l=strlen(msg);
	char temp;
	for(j=0;j<l/2;j++) {
		temp=msg[j];
		msg[j]=msg[l-j-1];
		msg[l-j-1]=temp;
	}
}

void btod(int n,char *msg) {
	int l=strlen(msg);
	int j=0;
	n=0;
	for(int i=l-1;i>=0;i--) {
		if(msg[i]=='1') {
			n=n+pow(2,j);
		}
		j++;
	}
}

void encrypt(char *msg,char *key,char *enc) {
	int i,l=strlen(msg);
	for(i=0;i<l;i++) {
		if((msg[i]=='0' && key[i]=='0') ||(msg[i]=='1' && key[i]=='1'))
			enc[i]='0';
		else 
			enc[i]='1';
	}
	enc[i]='\0';
}

void decrypt(char *enc,char *key,char *dec) {
	int i,l=strlen(enc);
	for(i=0;i<l;i++) {
		if((enc[i]=='0' && key[i]=='0') ||(enc[i]=='1' && key[i]=='1'))
			dec[i]='0';
		else 
			dec[i]='1';
	}
	dec[i]='\0';
}

int main() {
	int n,k;
	char msg[20],enc[20],dec[20],key[20],temp[20];
	cout<<"\nEnter the Number\t:\t";
	cin>>n;
	cout<<"\nEnter the key\t\t:\t";
	cin>>k;
	dtob(n,msg);
	dtob(k,key);
	cout<<"\nThe Plain Text\t\t:\t"<<msg;
	int l1=strlen(msg);
	int l2=strlen(key);
	while(l1!=l2) {
		strcpy(temp,key);
		strcat(key,temp);
		l2=strlen(key);
		if(l2>l1) {
			key[l1]='\0';
			l2=l1;
		}
	}
	cout<<"\nThe Key\t\t\t:\t"<<key;
	encrypt(msg,key,enc);
	cout<<"\nThe binary cipher text\t:\t"<<enc<<endl;
	btod(n,enc);
	cout<<"\nThe encrypted number\t:\t"<<n<<endl;
	decrypt(enc,key,dec);
	btod(n,dec);
	cout<<"\nThe decrypted message\t:\t"<<dec<<endl;
	cout<<"\nThe decrypted Number\t:\t"<<n<<endl;
	cout<<endl;
	return 0;
}
