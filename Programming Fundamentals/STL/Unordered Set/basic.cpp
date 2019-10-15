#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<char> temp;
    temp.insert('a');
    temp.insert('b');
    temp.insert('c');
    temp.insert('d');
    
    char key = 'b';
    if (temp.find(key) == temp.end()) // return end if not found
        cout << "Not found";
    else
        cout << "Found ";
    return 0;
}
