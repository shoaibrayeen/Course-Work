#include<iostream>
#include<stdlib.h>
using namespace std;
int tran,minsupp,l1count;
int itemset[10][10]={0},item_size[10]={0},l1[10][2]={0};
int count[10];
//---------------------------------Input----------------------------------------------------------------------//
void input() {
	cout << "\nNumber of Transaction\t\t\t:\t";
	cin >> tran;
	for(int i=0;i<tran;i++) {
		cout<<"\n-----------------------------------------------------------------------------------------------------\n";
		cout<<"\nEnter Number of items for "<<(i+1)<<" transaction\t:\t";
		cin>>item_size[i];
		cout<<"--------------------------------------------------------------------------------------------------------\n";
		for(int j=0;j<item_size[i];j++) {
			cout << "\nEnter itemset for " << (i+1) << " transaction\t\t:\t";
			cin >> itemset[i][j];
		}
	}
	cout << "\nEnter Minimum Support Count\t\t:\t";
	cin >> minsupp;
}

//===========================================Display Input=================================================================//

void display() {
	cout << "\nTransaction\t|\tList of Items\n";
	cout << "\n------------------------------------------------------------------------------------------------------------------\n";
    	for(int i=0;i<tran;i++) {
        	cout<<"\n";
		cout<<"\tT"<<(i+1)<<"\t|\t";
        	for(int j=0;j<item_size[i];j++) {
        	    cout << itemset[i][j] << "  ";
        	}
    	}	
	cout << "\n\n";
}

//-------------------------------------Frequent 1 Itemset--------------------------------------------------------------------//

void item1() {
	int c;
	for(int i=1;i<=5;i++) {
		c=0;
		for(int j=0;j<tran;j++) {
			for(int k=0;k<item_size[j];k++) {
				if(itemset[j][k]==i) {
					c++;
				}
			}
		}
		count[i]=c;
	}
	cout << "\nCandidate 1 Itemset\n----------------------------------------------\n";
	cout << "Items\t|\tSupport Count\n";
	for(int i=1;i<=5;i++) {
		cout << i << "\t|\t" << count[i] << "\n";
	}
	int p=0;
	for(int j=1;j<=5;j++) {
		if(count[j]>=minsupp) {
			l1[p][0]=j;
			l1[p][1]=count[j];
			++p;
			l1count++;
		}
	}

	cout << "\nFrequent 1 Itemset\n----------------------------------------------\n";
	cout << "Items\t|\tSupport Count\n";
	for(int i=0;i<l1count;i++) {
		cout << l1[i][0] << "\t|\t" << l1[i][1] << "\n";
	}	
}

//---------------------------------------------------------Frequent 2 itemset-----------------------------------------------------------//

int l2count,c2count;
int l2[10][3]={0},c2[10][3]={0};

void item2() {	
	int comb=0,each_count=0;
	for(int i=0;i<l1count;i++) {
		for(int j=i+1;j<l1count;j++) {
			c2[comb][0]=l1[i][0];
			c2[comb][1]=l1[j][0];
			++comb;
		}
	}
	for(int i=0;i<comb;i++) {
		int f1=0,f2=0;
		for(int j=0;j<tran;j++) {
			f1=f2=0;
			for(int k=0;k<item_size[j];k++) {
				if(itemset[j][k]==c2[i][0]) {
					f1=1;
				}
				else if(itemset[j][k]==c2[i][1]) {
					f2=1;
				}
				if(f1==1 && f2==1) {
					each_count++;
					f1=f2=0;
				}
			}
		}
		c2[i][2]=each_count;
		each_count=0;
	}
	c2count=comb;
	cout << "\nCandidate 2 Itemset\n";
	cout << "Items\t|\tSupport Count\n";
	for(int i=0;i<comb;i++) {
		cout << c2[i][0] << " , " << c2[i][1] << "\t|\t" << c2[i][2] << "\n";
	}
	int j=0;
	for(int i=0;i<comb;i++) {
		if(c2[i][2]>=minsupp) {
			l2[j][0]=c2[i][0];
			l2[j][1]=c2[i][1];
			l2[j][2]=c2[i][2];
			j++;
			l2count++;
		}
	}
	cout << "\nFrequent 2 Itemset\n";
	cout << "Items\t|\tSupport Count\n";
	for(int i=0;i<l2count;i++) {
		cout << l2[i][0] << " , " << l2[i][1] << "\t|\t" << l2[i][2] << "\n";
	}
}

//--------------------------------------------------------3 itemsets-----------------------------------------------------//

int c3[10][4]={0},l3[10][4]={0},c3count=0,l3count=0;
//For C2 itemset support count//

int check1(int x,int y) {
	for(int i=0;i<c2count;i++) {
        	if(c2[i][0]==x) {
                	if(c2[i][1]==y) {
                        	return c2[i][2];
                        }
		}

        }
                        return -1;
}

void item3() {
	int p=0,q=0,count=0;
	for(int i=0;i<l2count;i++) {
        	for(int j=i+1;j<l2count;j++) {
                	c3[p][0]=l2[i][0];
                	c3[p][1]=l2[i][1];
                	if(l2[j][0]==l2[i][0]) {
                     		int temp;
                        	temp=check1( l2[i][0],l2[i][1]);
                        	if(temp!=-1 && temp>=minsupp); {	
					temp=check1(l2[i][0],l2[j][1]);
                                	if(temp!=-1 && temp>=minsupp) {
						temp=check1(l2[i][1],l2[j][1]);
                                    		if(temp!=-1 && temp>=minsupp) {
							c3[p][2]=l2[j][1];
                                        		++p;
                                    		}
                                	}
                        	}

                    	}
                }
      	}
	c3count=p;
	for(int q=0;q<c3count;q++) {
        	count=0; 
    		int flag1=0,flag2=0,flag3=0;
        	for(int i=0;i<tran;i++) {
            		flag1=0,flag2=0,flag3=0;;
            		for(int j=0;j<item_size[i];j++) {
                		if(itemset[i][j]==c3[q][0]) {
                   			flag1=1;
				}
                		else if(itemset[i][j]==c3[q][1]) {
                    			flag2=1;
				}
                    		else if(itemset[i][j]==c3[q][2]) {
                        		flag3=1;
				}
				if(flag1==1&&flag2==1&&flag3==1) {
					count++;
			                flag1=0;flag2=0;flag3=0;		
        		        }
       			}
	        }
        	c3[q][3]=count;
    	}
	cout << "\nCandidate 3 Itemset\n";
	cout << "Items\t\t|\tSupport Count\n";
	for(int i=0;i<p;i++) {
        	cout << c3[i][0] << " , " << c3[i][1] << " , " << c3[i][2] << "\t|\t" << c3[i][3] << "\n";
	}
	int a=0;
    	int c=0;
    	for(int i=0;i<c3count;i++) {
        	if(c3[i][3]>=minsupp) {
            		l3[a][0]=c3[i][0];
            		l3[a][1]=c3[i][1];
            		l3[a][2]=c3[i][2];
            		l3[a][3]=c3[i][3];
            		a++;
            		c++;
        	}

    	}
	l3count=c;
    	cout << "\nFrequent 3 Itemset\n";
	cout << "Items\t\t|\tSupport Count\n";
	for(int i=0;i<l3count;i++) {
	        cout << l3[i][0] << " , " << l3[i][1] << " , " << l3[i][2] << "\t|\t" << l3[i][3] << "\n";
	}

}



int main() {
	input();
	display();
	item1();
	item2();
	item3();
	return 0;
}
