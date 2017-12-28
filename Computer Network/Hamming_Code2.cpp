#include<iostream>
#include<string.h>
#include<cstdlib>
#include<ctime>
using namespace std;
void addRem(char msg[], char gen[]){
	int m=strlen(msg);
	int r=strlen(gen);
	int i=0;
	msg[m]='\0';
	while(m>=r){
		while(msg[i]=='0'){ i++; m--; }
		if(m>=r)
		for(int z=0; z<r; z++){
			if(msg[i+z]==gen[z])
				msg[i+z]='0';
			else	msg[i+z]='1';
		}
		i++; m--;
	}
}

void checkError(char msg[], char gen[]){
	addRem(msg, gen);
	cout<<"\nRemainder\t:\t"<<msg;
	int m=strlen(msg);
	for(int i=m-1; i>=0; i--)
		if(msg[i]=='1'){
			cout<<"\terror.";
			return;
		}
	cout<<"\tno error.";
}

int main(){
	cout<<"Enter message\t:\t";
	char msg[50], gen[20], rem[50];
	cin>>msg;
	cout<<"Enter generator\t:\t";
	cin>>gen;
	int m=strlen(msg);
	int r=strlen(gen) - 1;
	for(int z=0; z<r; z++)
		msg[m++]='0';
	msg[m]='\0';
//	cout<<msg;
	int k=0;
	strcpy(rem, msg);
	addRem(rem, gen);
	int l=m;
	for(int k=0; k<r; k++){
		l--;
		msg[l]=rem[l];
	}
	cout<<"Remainder\t:\t"<<rem;
	cout<<"\nCodeword\t:\t"<<msg;
	cout<<"\n----------------------------------------\n";
	srand(time(0));
	int ra=rand()%m;
	cout<<"\nNo Err Codeword\t:\t"<<msg;
	strcpy(rem, msg);
	checkError(rem, gen);
	cout<<"\n----------------------------------------\n";

	strcpy(rem, msg);
	rem[ra]=char((!(int(rem[ra])-48))+48);
	cout<<"\nCodeword\t:\t"<<msg;
	cout<<"\nSingle bit error:\t"<<rem;
	checkError(rem, gen);
	cout<<"\n----------------------------------------\n";

	strcpy(rem, msg);
	int r1=rand()%m;
	int r2=rand()%m;
	rem[r1]=char((!(int(rem[r1])-48))+48);
	rem[r2]=char((!(int(rem[r2])-48))+48);
	cout<<"\nCodeword\t:\t"<<msg;
	cout<<"\nTwo bit error\t:\t"<<rem;
	checkError(rem, gen);
	cout<<"\n----------------------------------------\n";

	strcpy(rem, msg);
	r1=rand()%m;
	r2=rand()%m;
	if(r2<r1){int temp=r1; r1=r2; r2=temp;}
	cout<<"\nSize of burst\t:\t"<<r2-r1+1;
	rem[r1]=char((!(int(rem[r1])-48))+48);
	rem[r2]=char((!(int(rem[r2])-48))+48);
	for(int i=r1+1; i<r2; i++){
		int b=rand()%2;
		if(b==1)
		rem[i]=char((!(int(rem[i])-48))+48);
	}
	cout<<"\nCodeword\t:\t"<<msg;
	cout<<"\nMsg with burst\t:\t"<<rem;
	checkError(rem, gen);
	cout<<"\n----------------------------------------\n";

	cout<<"\n";
	return 0;
}
