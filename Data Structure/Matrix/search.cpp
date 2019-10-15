#include<stdio.h>

/* Searches the element x in mat[][]. If the
 element is found, then prints its position
 and returns true, otherwise prints "not found"
 and returns false */
int search(int mat[4][4], int n, int x)
{
    int i = 0, j = n-1;  //set indexes for top right element
    while ( i < n && j >= 0 )
    {
        if ( mat[i][j] == x )
        {
            printf("%d Found at %d, %d\n",x , i, j);
            return 1;
        }
        if ( mat[i][j] > x )
            j--;
        else //  if mat[i][j] < x
            i++;
    }
    
    printf("\n%d is not available in the matrix\n" , x);
    return 0;  // if ( i==n || j== -1 )
}

// driver program to test above function
int main()
{
    printf("\nMatrix Index starts at 0 , 0\n");
    int mat[4][4] = { {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };
    search(mat, 4, 50);
    return 0;
}
