/* Dynamic Programming implementation of LCS problem */
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
void lcs( char *X, char *Y, int m, int n )
{
	int L[m+1][n+1];
 	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
         			L[i][j] = 0;
       			else if (X[i-1] == Y[j-1])
         			L[i][j] = L[i-1][j-1] + 1;
       			else
         			L[i][j] = max(L[i-1][j], L[i][j-1]);
     		}
   	}
 	int index = L[m][n];
	char lcs[index+1];
   	lcs[index]='\0';
	int i=m, j=n;
   	while (i>0  &&  j>0)
   	{
      		if (X[i-1]==Y[j-1])
   	   	{
          		lcs[index-1]=X[i-1];
          		i--; j--; index--;
      		}
      		else if (L[i-1][j]>L[i][j-1])
         		i--;
      		else
         		j--;
   	}
	cout<<"\n1st String\t\t:\t"<<X<<"\n2nd string\t\t:\t"<<Y<<"\nLCS is \t\t\t:\t"<<lcs<<"\nLength of LCS is\t:\t"<<strlen(lcs);
}
int main()
{
	system("clear");
	char X[20];
	char Y[20];
	cout<<"\nEnter 1st String : ";
  	cin>>X;
	cout<<"\nEnter 2nd String : ";
	cin>>Y;
	int m = strlen(X);
	int n = strlen(Y);
	lcs(X, Y, m, n);
	cout<<"\n\n\n";
	return 0;
}
