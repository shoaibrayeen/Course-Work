// C++ program to find unique
// element in matrix
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

// function that calculate unique element
int unique(int mat[R][C], int n, int m)
{
    int maximum = 0, flag = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            // Find maximum element in
            // a matrix
            if(maximum < mat[i][j])
                    maximum = mat[i][j];

    // Take 1-D array of (maximum + 1)
    // size
    int b[maximum + 1] = {0};
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            b[mat[i][j]]++;

    //print unique element
    for(int i = 1; i <= maximum; i++)
        if(b[i] == 1)
            cout << i << " ";
            flag = 1;
            
    if(!flag){
        cout << "No unique element in the matrix";
    }
}

// Driver program
int main()
{
    int mat[R][C] = {{ 1, 2, 3, 20},
                     {5, 6, 20, 25},
                     {1, 3, 5, 6},
                     {6, 7, 8, 15}};
                     
    // function that calculate unique
    // element
    unique(mat, R, C);
    return 0;
}
