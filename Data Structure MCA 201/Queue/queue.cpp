#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

class queue {
    public :
    stack <int> s1, s2;
    void enqueue(int &);
    void dequeue();
};


void queue :: enqueue( int & newValue) {
   s1.push(newValue);
}

void queue :: dequeue() {
    if(s1.empty()) {
	cout << "Queue is Empty.\n";
	return;
    }
    while(!s1.empty()) {
	s2.push(s1.top());
	s1.pop();
    }
    cout << "\nPopped Element\t:\t" << s2.top();
    s2.pop();
    while(!s2.empty()) {
	s1.push(s2.top());
	s2.pop();
    }
}


int main() {
    queue obj;
    int temp;
    while(1) {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Exit\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        obj.enqueue(temp);
                        break;
            case 2 :    obj.dequeue();
                        break;
            case 3 :    exit(0);
                        break;
            default:    cout << "\nInvalid Input\n";
        }
    }
    return 0;
}
