#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdlib.h>
using namespace std;

float data[10][3],clus[3][2];
float d[2][10];
int cl[2][10],c1=0,c2=0;
int n,k;
float total,total1=1000;

float maxd(float x1,float y1, float x2, float y2) {
	float a=abs(x1-x2);
	float b=abs(y1-y2);
	if(a<b) {
		return b;
	}
	else {
		return a;
	}
}

float absd(float x1,float y1, float x2, float y2) {
	float dis=abs(x1-x2) + abs(y1-y2);
	return dis;
}

void cost() {
	float x=0,y=0;
	for(int i=0;i<c1;i++) {
		x+=absd(data[cl[0][i]][0],data[cl[0][i]][1],clus[0][0],clus[0][1]);
	}
	for(int i=0;i<c2;i++) {
		y+=absd(data[cl[1][i]][0],data[cl[1][i]][1],clus[1][0],clus[1][1]);
	}
	total=x+y;
	cout << "\nTotal Cost\t:\t" << total << endl;
}

void kmediod() {
	cout << "\nCentroids\n";
	cout << "\nSr.\t|\t(X,Y)\n";
	for(int i=0;i<k;i++) {
		cout << i << "\t|\t(" << clus[i][0] << "," << clus[i][1] << ")\n";
	}
	c1=c2=0;
	for(int i=0;i<n;i++) {
		float a=maxd(clus[0][0],clus[0][1],data[i][0],data[i][1]);
		float b=maxd(clus[1][0],clus[1][1],data[i][0],data[i][1]);
		if(a<b) {
			cl[0][c1]=i;c1++;
		}
		else {
			cl[1][c2]=i;c2++;
		}
	}
	cout << "\nCluster 1\t:\t";	
	for(int i=0;i<c1;i++) {
		cout << cl[0][i] << "\t";
	}
	cout << "\nCluster 2\t:\t";	
	for(int i=0;i<c2;i++) {
		cout << cl[1][i] << "\t";
	}
	cout << endl;
	cost();
}

void display() {
	cout << "\nEntered Data\n";
	cout << "\nSr.\t|\t(X,Y)\n";
	for(int i=0;i<n;i++) {
		cout << i << "\t|\t(" << data[i][0] << "," << data[i][1] << ")\n";
	}
}

int main() {
	cout << "\n\n\t\t--------------------K-Mediods------------------\t\t\n";
	cout << "\nEnter Number of data\t:\t";
	cin >> n;
	for(int i=0;i<n;i++) {
		cout << "\nEnter (X,Y) Coordinates for ";
		cout << i << "\n";
		cin >> data[i][0];
		cin >> data[i][1];
		data[i][2]=0;
	}
	int p;
	for(int i=0;i<2;i++) {
		cout << "\nEnter " << i << " Cluster Index\t:\t";
		cin >> p;
		data[p][2]=1;
		clus[i][0]=data[p][0];
		clus[i][1]=data[p][1];
	}
	display();
	int q=-1;
	float x1,y1;
	int lk;
	kmediod();
	while(total1!=total) {
		if(total1<total) {
			cout << "\nCentroid replacement rejected\n";
			if(q==0) {
				cl[0][0]=x1;
				cl[0][1]=y1;
			}
			else {
				
				cl[1][0]=x1;
				cl[1][1]=y1;
			}
		}
		total1=total;
		srand(time(0));
		lk=rand()%(10);
		while(data[lk][2]!=0) {
			lk=rand()%(10);
		}
		for(int i=0;i<c1;i++) {
			if(cl[0][i]==lk) {
				q=0;
			}
		}
		for(int i=0;i<c2;i++) {
			if(cl[1][i]==lk) {
				q=1;
			}
		}
		data[lk][2]=1;
		if(q==0) {
			x1=clus[0][0];
			y1=clus[0][1];
			clus[0][0]=data[lk][0];
			clus[0][1]=data[lk][1];
		}
		else {
			x1=clus[1][0];
			y1=clus[1][1];
			clus[1][0]=data[lk][0];
			clus[1][1]=data[lk][1];
		}
		kmediod();
		
	}
	return 0;
}
