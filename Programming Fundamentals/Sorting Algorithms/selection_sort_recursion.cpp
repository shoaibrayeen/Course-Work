#include<iostream>
using namespace std;
int size;
int minIndex(int *list,int lowerBound,int upperBound) {
    /*
    Objective: to find the index of the minimum numbrer of the list
    Input Parameters:
        list: list to be given
        upperBound: upper bound of the list
        lowerBound: lower bound of the list
    Return Value: the index of the minimum numbrer of the list
    */

    //Approach: using recursion

    if (upperBound==lowerBound) {
        return upperBound;
    }
    else if (list[upperBound] > list[lowerBound] ) {
        return minIndex(list,lowerBound,upperBound-1);
    }
    else {
        return minIndex(list,lowerBound+1,upperBound);
    }
}

void selectionSort(int *list , int count = 0 ) {
    /*
    Objective: to sort a list using selection sort algorithm
    Input Parameters:
        list: list to be given
        count: for counting till length of list
    Return Value: sorted List
    */

    //Approach : using function minIndex()
    
    if ( count == size-1) {
	      cout << "\nSorted List\t:\t";	
	      for ( int i = 0 ; i < size ; ++i ) {
		        cout << list[i] << "  ";
	      }
	      cout <<  endl;
    }
    else {
        int minimumIndex=minIndex(list,count,size-1);
	      int temp=list[count];
	      list[count]=list[minimumIndex];
	      list[minimumIndex]=temp;
        selectionSort(list,count+1);
    }
}
    
int main() {

	int list[20];
	cout << "\nEnter Size of Array\t:\t";
	cin >> size;
	cout << "\nEnter Element of Array\n";	
	for ( int i = 0 ; i < size ; ++i) {
		cin >> list[i] ;
	}
	cout << "\nUnsorted List\t:\t";	
	for ( int i = 0 ; i < size ; ++i) {
		cout << list[i] << "  ";
	}
	selectionSort(list);
	return 0;
}
