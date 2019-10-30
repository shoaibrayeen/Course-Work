#include<iostream>
#include<stdlib.h>


using namespace std;
int main() {
	int n;
	cout << "\nNumber of Processor\t:\t";
	cin >> n;
	int b[n], a[n], p[n], wt[n], tat[n], tq;
	float aw = 0, at = 0;
	for(i = 0; i < n; i++ ) {
		cout << "\nEnter Burst Time and Arrival Time for Process "<<i<<"\n";
		cin >> b[i];
		cin >> a[i];
		p[i] = i;
	}
	cout << "\nEnter Time Quantum\t:\t";	
	cin >> tq;
	for(int i = 1; i < n; i++) {
		for(int j = i; j >= 1; j--) {
			if(a[j-1] > a[j]) {
				swap(a[j] , a[j+1]);
				swap(b[j] , b[j+1]);				
				swap(p[j] , p[j+1]);
			}
			else {
				break;
			}
		}
	}
	int db[n], L = 0, S[n];
	for(int i = 0; i < n; i++ ) {
		db[i] = b[i];
		L += b[i];
		S[i] = -1;
	}

	for(int j = a[0] , i = 0; j < L; ) {
			if(db[i] != 0) {

				if(S[i] == -1) {	
					wt[i] = j - a[i];
				}
				else {
					wt[i] = wt[i] + j - S[i];
				}
	
				if(db[i] <= tq) {	
					j += db[i];
					db[i] = 0;
					tat[i] = j - a[i];
				}			
				else {	
					db[i] -= tq;
					j += tq;
					S[i] = j;
				}
				
			}
			i = (i + 1)%n;
	}
	
	cout<<"\nProcess\tBT\tAT\tWT\tTAT\n";
	for(int i = 0; i < n; i++ ) {
		aw += wt[i];
		at += tat[i];
		cout << "P" << p[i] << "\t" << b[i] << "\t" << a[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
	}
	cout << "\n\nAverage Waiting Time\t\t:\t" << (aw/n);
	cout << "\n\nAverage Turn Around Time\t:\t" << (at/n) << "\n";
	return 0;	
}
