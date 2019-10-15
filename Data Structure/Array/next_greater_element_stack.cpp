#include<iostream>
#include<stack>
using namespace std;
void printNGE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    for (int i=1; i<n; i++)
    {
        int next = arr[i];
 
        if (!s.empty())
        {
            int element = s.top();
            s.pop();
            while (element < next)
            {
                cout << element << " --> " << next
                     << endl;
                if (s.empty() == true)
                   break;
                element = s.top();
                s.pop();
            }
            if (element > next)
                s.push(element);
        }
        s.push(next);
    }
    while (s.empty() == false)
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

int main()
{
    int arr[] = {11, 13, 21, 3,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
