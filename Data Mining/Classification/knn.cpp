#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int num,d,nbr;
float new1;
float data[20][2]={0};
float diff[20][2]={0};

void swap(float x,float y) {
	float temp =x;
        x=y;
        y= temp;
}

void sort() {
	for (int i = 0; i < num; i++) {
    		for (int j = 0; j < num - i - 1; j++) {
      			if (diff[j][0] > diff[j + 1][0]) {
     				swap(diff[j][0],diff[j+1][0]);
				swap(diff[j][1],diff[j+1][1]);
			}
		}
	}
}

void display() {
	cout << "\nUser entered Data\n";
	cout << "Data : Class\n";
	for(int i=0;i<num;i++) {
		for(int j=0;j<=d;j++) {
			cout << data[i][j] << "\t";
		}
		cout << "\n";
	}
}

void knn() {	
	for(int i=0;i<num;i++) {
		diff[i][0]=abs(data[i][0]-new1);
		diff[i][1]=data[i][1];
	}
	sort();
	int count=1;
	float k;
	if(nbr>1) {
		for(int i=1;i<nbr;i++) {
			if(diff[i][1]==diff[0][1]) {
				count++;
			}
			else {
				k=diff[i][1];
				count--;
			}
		}
	}
	if(count>0) {
		cout << "\nClass of " << new1 << " is\t:\t" << diff[0][1];
	}
	else {
		cout << "\nClass of " << new1 << " is\t\t\t:\t" << k;
	}
	cout << endl;
}


int main() {
	cout << "\nEnter Number of Data\t\t\t:\t";
	cin >> num;
	int j=0;
	for(int i=0;i<num;i++) {
		cout << "\nEnter Data for " << i+1 << " variable\t\t:\t";
		cin >> data[i][0];
		cout << "\nEnter Class for " << i+1 << " variable(0 or 1)\t:\t";
		cin >> j;
		while(j!=0 && j!=1) {
			cout << "\nWrong Class\nPlease Enter Again\n\n";
			cin >> j;
		}
		data[i][1]=j;
	}
	display();
	while(1) {
		cout << "\nEnter New Data to know the class\t:\t";
		cin >> new1;
		cout << "\nEnter Number of Nearest Neighbour\t:\t";
		cin >> nbr;
		display();
		knn();
		cout << "\nPress 1 if want to work on same data\t:\t";
		int l=0;
		cin >> l;
		if(l!=1) {
			break;
		}
	}
	return 0;
}
