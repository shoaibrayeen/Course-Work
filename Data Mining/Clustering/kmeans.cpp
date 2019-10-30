#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class kmeans {
	int k,total,c[10];
	float data[10][2],ini[5][2],dist[5][2];
	int cl[5][8];
	public:
		kmeans();
		void input();
		void display();
		void iter1();
		void sort();
		void swap(float,float);
};

kmeans::kmeans() {
	k=total=0;
}

void kmeans::swap(float x,float y) {
	float temp =x;
        x=y;
        y= temp;
}

void kmeans::input() {
	cout << "\nEnter Number of Elements\t:\t";
	cin >> total;
	cout << "\nEnter the Data\n";
	for(int i=0;i<total;i++) {
		cout << "\nEnter coordinates for " << i << "\n";
		cin >> data[i][0];
		cin >> data[i][1]; 
	}
	cout << "\nEnter Number of Clusters\t:\t";
	cin >> k;
	for(int i=0;i<k;i++) {
		int l=-1;
		cout << "\nEnter Serial Number of Cluster  :\t";
		cin >> l;
		ini[i][0]=data[l][0];
		ini[i][1]=data[l][1];
	}
}

void kmeans::display() {
	int i;
	cout << "\nSr.No\t:\tX-cord\t:\tY-cord\n";
	for(i=0;i<total;i++) {
		cout << "   " << i << "\t:\t" << data[i][0] << "\t:\t" << data[i][1];
		cout << endl;
	}
	cout << "\nTotal Number of Cluster\t:\t" << k;
	cout << "\n    Clusters\t:\tX-cord\t:\tY-cord\n";
	for(i=0;i<k;i++) {
		cout << "     " << i << "\t\t:\t" << ini[i][0] << "\t:\t" << ini[i][1];
		cout << endl;
		
	}
}

void kmeans::sort() {
	for (int i = 0; i < k; i++) {
    		for (int j = 0; j < k - i - 1; j++) {
      			if (dist[j][0] > dist[j + 1][0]) {
     				swap(dist[j][0],dist[j+1][0]);
				swap(dist[j][1],dist[j+1][1]);
			}
		}
	}
}

void kmeans::iter1() {
	int i,j;
	for(i=0;i<k;i++) {
		c[i]=0;
	}
	for(i=0;i<total;i++) {
		for(j=0;j<k;j++) {
				dist[j][0]=sqrt(pow((data[i][0]-ini[j][0]),2) + pow((data[i][1]-ini[j][1]),2));
				dist[j][1]=j;	
		}
		sort();
		for(j=0;j<k;j++) {
			if(dist[0][1]==j) {
				int p=c[j];
				cl[j][p]=i;
				++p;
				c[j]=p;
				break;
			}
		}
	}
	float x=0,y=0;
	for(i=0;i<k;i++) {
		for(j=0;j<c[i];j++) {
			x+=data[cl[i][j]][0];
			y+=data[cl[i][j]][1];
		}
		ini[i][0]=(x/c[i]);
		ini[i][1]=(y/c[i]);
	}

	cout << "\n-----------------------Clusters--------------------------------\n";
	for(i=0;i<k;i++) {
		cout << "\nCluster " << i << "\t:\t";
		for(j=0;j<c[i];j++) {
			cout << cl[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\n-----------------------New Means-------------------------\n";
	cout << "\n    Clusters\t:\tX-cord\t:\tY-cord\n";
	for(i=0;i<k;i++) {
		cout << "  " << i << "\t\t:\t" << ini[i][0] << "\t:\t" << ini[i][1] << "\n";
	}
	
}

int main() {
	int tr;
	kmeans o;
	o.input();
	o.display();
	o.iter1();
	return 0;
}
