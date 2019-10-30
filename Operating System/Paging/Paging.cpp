#include<iostream>
#include<stdlib.h>
using namespace std;

int search(int n,int pid[], int p) {
	for(int i = 0; i < n; i++) {
		if( p == pid[i] ) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int ps, ms;
	cout << "\nEnter Memory Size\t:\t";
	cin >> ms;
	cout << "\nEnter Page Size\t\t:\t";
	cin >> ps;
	int ff = ms / ps;
	int pid[ff], vi[ff];
	int n = ff;
	for(int i = 0; i < n; i++) {
		pid[i] = vi[i] = 0;
	}
	cout << "\n";
	int c, psize, rp, k, j, p;
	while(true) {
		cout << "\nFree Frames\t\t:\t"<<ff;
		cout << "\n\n\t*****************Frame Table***********************\n";
		cout << "\n\nFrame No\tProcess ID\tValid/Invalid\n";
		for(int i = 0; i < n; i++ ) {
			cout << i << "\t\t   " << pid[i] << "\t\t  " << vi[i] << "\n";
		}
		cout << "\n1.Allocate\n2.Deallocate\n3.Exit\n";
		cin >> c; 
		switch(c) {
			case 1: cout << "\nEnter The Size of Process\t:\t";	
				cin >> psize;
				k = 0;
				if( psize % ps != 0 ) {
					k = 1;
				}
				rp = psize / ps + k;
				if( rp > ff ){
					cout << "\nRequired Memory Not Available\n";
					break;
				}
				cout << "\nEnter the process id\t:\t";
				cin >> p;
				if( search(n, pid, p) != 0) {
					j = 1;
					for(int i = 0; i < n && j <= rp; i++) {
						if(vi[i] == 0) {
							pid[i] = p;
							vi[i] = 1;
							j++;
						}
					}
					ff -= rp;
					cout << "\nFrame Successfully Allocated!!!!!!!!!!!\n";
				}
				else {
					cout<<"\nDuplication Not Allowed\n";
				}
				break;
			case 2: cout << "\nEnter the Process Id For Deallocate the memory\t:\t";
				cin >> p;
				if(search( n, pid, p ) == 0) {
					for(int i = 0; i < n; i++ ) {
						if(pid[i] == p) {
							vi[i] = 0;
							ff++;
						}
					}
					cout << "\nFrame Successfully Deallocated!!!!!!!!!!!!!!!!!!\n";
				}
				else {
					cout << "\nInvalid Process Id\n";
				}
				break;
			case 3: exit(0);
				
				
		}
	}
	return 0;
}
