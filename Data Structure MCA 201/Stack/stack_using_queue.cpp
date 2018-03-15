#include <iostream>
#include<queue>
using namespace std;
class stack {
  public:
  queue<int> q;
  void push(int);
  void pop();
};

void stack::push(int element) {
    q.push(element);
    
}
void stack::pop() {
    if(q.empty() ) {
        cout<< "\nStack is Empty.\n";
        return;
    }
    int i = 1;
    int temp;
    while ( i < q.size() ) {
        temp = q.front();
        q.pop();
        i++;
        q.push(temp);
    }
    cout << "\nPopped Element\t:\t" << q.front();
    q.pop();
}

int main() {
    stack obj;
    int temp;
    while(1) {
        cout << "\n1.Push\n2.Pop\n3.Exit\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        obj.push(temp);
                        break;
            case 2 :    obj.pop();
                        break;
            case 3 :    exit(0);
                        break;
            default:    cout << "\nInvalid Input\n";
        }
    }
    return 0;
}
