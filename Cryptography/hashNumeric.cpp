#include<iostream>
using namespace std;

int reverse(int n) {
	int k=0,r;
	while(n!=0)
	{
		r=n%10;
		k=k*10+r;
		n/=10;
	}
	return k;
}

void hash(int n) {
	int i=1,r;
	while(n!=0) {
		r=n%10;
		if((i*r)%10==0) {
			i=i+r;
		}
		else if(r!=0) {
			i*=r;
		}
		n/=10;
	}
	i=i%10;
	cout<<"\nHash value is\t\t:\t"<<i<<endl;	
}

int main() {
	int n;
	cout<<"\nNumeric Hash Function\n";
	cout<<"\nEnter the number\t:\t";
	cin>>n;
	int i=reverse(n);
	hash(i);
	return 0;
}
