#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float data[10][2],clus[4][2];
float d[4][10];
int cl[4][10],c[10];
int n,k;

float dist(float x1,float y1, float x2, float y2) {
	float dis=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	return dis;
}
void kmeans() {
	float min,a;
	int ic=0;
	for(int i=0;i<k;i++) {
		c[i]=0;
	}
	for(int i=0;i<n;i++) {
		min=dist(clus[0][0],clus[0][1],data[i][0],data[i][1]);
		for(int j=1;j<k;j++) {	
			a=dist(clus[j][0],clus[j][1],data[i][0],data[i][1]);
			if(a<min) {
				ic=j;
			}
		}
		clus[ic][0]=(clus[ic][0]+data[i][0])/2;
		clus[ic][1]=(clus[ic][1]+data[i][1])/2;
		cl[ic][c[ic]]=i;
		c[ic]=c[ic]+1;
	}
	for(int i=0;i<k;i++) {
		clus[i][0]=0;
		clus[i][1]=0;
	}
	for(int j=0;j<k;j++) {
		for(int i=0;i<c[j];i++) {
			int k=cl[j][i];
			clus[j][0]+=data[k][0];
			clus[j][1]+=data[k][1];
		
		}
		clus[j][0]/=c[j];
		clus[j][1]/=c[j];
	}
	cout << "\nNew Centroids are\n";
	cout << "\nSr.\t|\t(X,Y)\n";
	for(int i=0;i<k;i++) {
		cout << i << setprecision(2) << fixed << "\t|\t(" << clus[i][0] << "," << clus[i][1] << ")\n";
	}
	for(int j=0;j<k;j++) {
		cout << "\nCluster " << j+1 << "\t:\t";	
		for(int i=0;i<c[j];i++) {
			cout << cl[j][i] << "\t";
		}
	}	
	for(int i=0;i<k;i++) {
		c[i]=0;
	}
	
	cout << endl;
}

void display() {
	cout << "\nEntered Data\n";
	cout << "\nSr.\t|\t(X,Y)\n";
	for(int i=0;i<n;i++) {
		cout << i << "\t|\t(" << data[i][0] << "," << data[i][1] << ")\n";
	}
	cout << "\nCentroids\n";
	cout << "\nSr.\t|\t(X,Y)\n";
	for(int i=0;i<k;i++) {
		cout << i << "\t|\t(" << clus[i][0] << "," << clus[i][1] << ")\n";
	}
}

int main() {
		
	cout << "\n\n\t\t--------------------K-Means-Incremental------------------\t\t\n";
	cout << "\nEnter Number of data\t:\t";
	cin >> n;
	for(int i=0;i<n;i++) {
		cout << "\nEnter (X,Y) Coordinates for ";
		cout << i << "\n";
		cin >> data[i][0];
		cin >> data[i][1];
	}
	cout << "\nEnter Number of Clusters\t:\t";
	cin >> k;
	int p;
	for(int i=0;i<k;i++) {
		cout << "\nEnter " << i << " Cluster Index\t:\t";
		cin >> p;
		clus[i][0]=data[p][0];
		clus[i][1]=data[p][1];
	}
	display();
	int i=0;
	while(i<4) {
		kmeans();
		i++;
	}
	return 0;
}
