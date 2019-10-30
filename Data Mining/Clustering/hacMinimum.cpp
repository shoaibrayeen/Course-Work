#include<iomanip>
#include<iostream>
#include<math.h>
using namespace std;

float data[10][2],n,itr=0;
float dist[6][6],dist1[5][5];
int l,m;

void display() {
	cout << "\nEntered Data\n";
	cout << "\nSr.\t|\t(X,Y)\n";
	for(int i=0;i<n;i++) {
		cout << i << "\t|\t(" << data[i][0] << "," << data[i][1] << ")\n";
	}
}

int search(int * a,int q,int s) {
	for(int i=0;i<q;i++) {
		if(a[i]==s) {
			return 0;
		}
	}
	return 1;
}

void distance() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i!=j) {
				dist[i][j]=sqrt(pow((data[i][0]-data[j][0]),2) + pow((data[i][1]-data[j][1]),2));
			}
			else {
				dist[i][j]=0;
			}
		}
	}
}

void min1() {
	
	int p;
	float c[7];
	int ind[12];
	l=0,m=1;
	int q=0,r=5,f=0;
	for(int i=0;i<n;i++) {
		c[i]=0;ind[i]=-1;
	}
	for(int k=0;k<n-1;k++) {
		float min=dist[0][1];
		for(int i=0;i<n;i++) {
			for(int j=2;j<n;j++) {
				if(i<j) {
					if(dist[i][j]==0) {
						j++;
					}
					else {
						if(min>dist[i][j]) {	
							min=dist[i][j];
							l=i;
							m=j;
						}
					}
				}
			}
		}
		cout << "\nJoining Value is\t" << setprecision(2) << fixed << min << endl;
		cout << "\nConnected Nodes are\t:\t";
		if(q==0) {
			ind[q]=l;
			ind[q+1]=m;
			q=q+2;
			for(int i=0;i<q;i++) {
				cout << ind[i] << "\t";
			}
			cout << endl;
		}
		else {
			int a1=search(ind,q,l);
			int a2=search(ind,q,m);
			int a3=search(ind,r,l);
			int a4=search(ind,r,m);
			if(a1==1 && a2==1 && a3==1 && a4==1) {
				ind[r]=l;
				ind[r+1]=m;
				r=r+2;
				for(int i=5;i<r;i++) {
					cout << ind[i] << "\t";
				}
				cout << endl;
			}
			else {
				if(a1==1 || a2==1) {
					if(a1==1) {
						ind[q]=l;
						q=q+1;
					}
					if(a2==1) {
						ind[q]=m;
						q=q+1;
					}
					for(int i=0;i<q;i++) {
						cout << ind[i] << "\t";
					}
					cout << endl;
				}
				else if(a3==1 || a4==1) {
					if(f==0) {
						if(a3==1) {
							ind[r]=l;
							r=r+1;
						}
						if(a4==1) {
							ind[r]=m;
							r=r+1;
						}
						for(int i=5;i<r;i++)
						cout << ind[i] << "\t";
						cout << endl;
					}
					else {
						if(a3==1) {
							ind[q]=l;
							q=q+1;
						}
						if(a4==1) {
							ind[q]=m;
							q=q+1;
						}
						for(int i=0;i<q;i++) {
							cout << ind[i] << "\t";
						}
						cout << endl;
					}
				}
				else if(a1==1 || a2==1 & a3==1 || a4==1) {
					for(int i=5;i<r;i++) {
						ind[q++]=ind[i];
					}
					for(int i=0;i<q;i++) {
						cout << ind[i] << "\t";
					}
					cout << endl;
					f=1;
				}
			}
		}
		cout << endl;
		dist[l][m]=0;
	}	
}

void display1() {
	cout << "\nDissimilarity Matrix\n";
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i<=j) {
				cout << setprecision(2) << fixed << dist[i][j] << "\t";
			}
			else {
				cout<<"\t";
			}	
		}
		cout << "\n";
	}
}

int main() {
		
	cout << "\n\n\t\t-------------------Single Linkage-HAC------------------\t\t\n";
	cout << "\nEnter Number of data\t:\t";
	cin >> n;
	for(int i=0;i<n;i++) {
		cout << "\nEnter (X,Y) Coordinates for ";
		cout << i << "\n";
		cin >> data[i][0];
		cin >> data[i][1];
	}
	display();
	distance();
	display1();
	min1();
	return 0;
}
