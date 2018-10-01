//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<stack>
#include<bitstdc++.h>

using namespace std;

int main()
{
    int n,i,j;
    printf("Enter size of array ");
    scanf("%d",&n);
    int input[n],output[n];
    printf("Enter elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&input[i]);
    stack<int> count[10];
    for(i=n-1;i>=0;i--)
        count[input[i]].push(i);
    for(i=0,j=0;i<10;i++)
        while(!count[i].empty())
        {
            output[j++]=input[count[i].top()];
            count[i].pop();
        }
    printf("Sorted array:- \n");
    for(i=0;i<n;i++)
        printf("%d ",output[i]);
    cout << endl;
    return 0;
}
