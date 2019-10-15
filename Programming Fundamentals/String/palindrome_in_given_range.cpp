#include<iostream>
using namespace std;

int isPalindrome(int n)
{
    int rev = 0;
    for (int i = n; i > 0; i /= 10)
        rev = rev*10 + i%10;
    return (n==rev);
}

void countPal(int min, int max)
{
    for (int i = min; i <= max; i++)
        if (isPalindrome(i))
            cout << i << " ";
}

int main()
{
    int min , max;
    cout << "\nEnter Minimum\t:\t";
    cin >> min;
    cout << "\Enter Maximum\t:\t";
    cin >> max;
    countPal( min , max);
    return 0;
}
