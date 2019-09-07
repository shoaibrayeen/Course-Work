//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;
void display(int*a ,int n){
    cout << endl;
    for(int i  = 0;i<n;i++) {
        cout << a[i] <<"\t";
    }
}
void counting_sort(int *A, int N) {
    int K = 0;
    for(int i=0; i<N; i++) {
        K = max(K, A[i]);
    }
    int Aux[K], sortedA[N];
    for(int i=0 ; i<=K; i++) {
        Aux[i] = 0;
    }
    for(int i=0; i<N; i++) {
        Aux[A[i]]++;
    }
    
    int j = 0;
    for(int i=0; i<=K; i++) {
        int tmp = Aux[i];
        /*int temp =0;
        if(tmp !=0) {
            temp = abs(tmp-i);
        }*/
        while(tmp) {
            sortedA[j] = i;
            j++;
            tmp--;
            //temp++;
        }
    }
    cout << "\nCounting Array\n";
    display(Aux,K+1);
    cout <<"\nArray after Sorting\n";
    display(sortedA,N);
}
int main(){
    cout << "\nEnter Size\t:\t";
    int n ;
    cin >> n;
    cout <<"\nEnter Array Element\n";
    int a[n];
    for(int i =0;i<n;i++) {
        cin >>a[i];
    }
    counting_sort(a,n);
    cout << endl;
    return 0;
}
