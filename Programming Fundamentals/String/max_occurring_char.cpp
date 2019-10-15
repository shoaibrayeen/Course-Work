#include <iostream>
#include <string>
using namespace std;

char getMaxOccuringChar(string str)
{
    int count[256] = {0};
    int len = str.length();
    for (int i=0; i<len; i++)
        count[str[i]]++;
    
    int max = -1;
    char result ='\0';
    for (int i = 0; i < len; i++) {
        if (max < count[str[i]]) {
            max = count[str[i]];
            result = str[i];
        }
    }
    
    return result;
}
int main() {
    string s1;
    cout << "\nEnter String\t:\t";
    getline(cin,s1);
    cout << "Maximum occurring character is\t:\t" << getMaxOccuringChar(s1) <<"\n";
    return 0;
}
