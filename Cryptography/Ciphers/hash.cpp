#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
char atob[10][8],msg[10], a;
int n;

void lrc() {	
	int cost=0,k=6;
	for(int i=0;i<7;i++) {
		int c=0;
		for(int j=0;j<n;j++) {
			if(atob[j][i]=='1') {
				c++;
			}
		}
		if(c%2==1) {
			atob[n][i]='0';
		}
		else {
			cost+=pow(2,k);
			atob[n][i]='1';
		}
		k--;
	}
	cout << "\nThe LRC Value is\t:\t" << cost;
}


void hrc() {
	int cost=0,k=n-1;
	for(int i=0;i<n;i++) {
		int c=0;
		for(int j=0;j<7;j++) {
			if(atob[i][j]=='1') {
				c++;
			}
		}
		if(c%2==1) {
			atob[i][7]='0';
		}
		else {
			cost+=pow(2,k);
			atob[i][7]='1';
		}
		k--;
	}
	cout << "\nThe HRC Value is\t:\t" << cost;
}

void Display(int l,int m) {
	cout << "\nThe Binary Matrix\n";
	for(int i=0;i<m;i++) {
		for(int j=0;j<l;j++) {
			cout<<atob[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main() {
	cout << "\nEnter the word(lemgth should be less than 10)\t:\t";
	gets(msg);
	n=strlen(msg);
	msg[n]='\0';
	for(int k=0;k<n;k++) {
		int j=0,l=0;
		for(int i=msg[k];i!=0;i=i/2) {
			if(i%2==0) {
				atob[k][j++]='0';
			}
			else {
				atob[k][j++]='1';
			}
			l++;
		}
		while(l<7) {
			atob[k][j++]='0';
			l++;	
		}
		atob[k][j]='\0';
		char temp;
		for(j=0;j<3;j++) {
			temp=atob[k][j];
			atob[k][j]=atob[k][l-j-1];
			atob[k][l-j-1]=temp;
		}	
	}
	Display(7,n);
	cout << "\n-----------------------For Odd Parity-------------------------------\n";
	lrc();
	Display(7,n+1);
	hrc();
	Display(8,n);
	return 0;
}
