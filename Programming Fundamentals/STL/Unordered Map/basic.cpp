#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, int> map;
    map['a'] = 10;
    map['b'] = 20;
    map['c'] = 30;
    
    // Traversing an unordered map
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
    return 0;
}
