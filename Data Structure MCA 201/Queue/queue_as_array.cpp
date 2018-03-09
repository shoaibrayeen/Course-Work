//
//  queue_as_array.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 09/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
class queue {
    /*
     objective : class for queue using array
     input parameter : none
     output parameter : none
     approach : using array
     */
    int *arr;       // dynamic array
    int front;      //pointing index of first element of queue
    int rear;       //pointing index of last element of queue
    public :
    queue();
    ~queue();
    void enqueue(int &);
    void dequeue();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    void display();
};

queue :: queue() {
    arr = new int[MAXSIZE];
    front = -1;
    rear = -1;
}
queue :: ~queue() {
    delete[] arr;
}

void queue :: enqueue( int & newValue) {
    if(isEmpty()) {
        front++;
        rear++;
    }
    else  {
        rear++;
    }
    arr[rear]= newValue;
    display();
}

void queue :: dequeue() {
    if(isEmpty()) {
        cout << "\nQueue is Empty.\n";
        return;
    }
    else {
        front++;
        cout << "\nElement dequeued.\n";
        return;
    }
}

int queue :: peek() {
    if(isEmpty()) {
        return -1;
    }
    else {
        return arr[front];
    }
}

int queue:: size() {
    return (rear - front + 1);
    
}

bool queue::isFull() {
    if((rear + 1) == MAXSIZE) {
        return true;
    }
    return false;
}
bool queue::isEmpty() {
    if( front == -1 && rear==-1) {
        return true;
    }
    return false;
}

void queue:: display() {
    cout << "\nQueue Elements\n\n";
    for ( int i = front ; i <= rear ; ++i) {
        cout << " | " << arr[i] ;
    }
    cout << " | ";
}
int main() {
    queue obj;
    int temp;
    while(1) {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Front Element of Queue\n4.Size of Queue\n5.Exit\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        obj.enqueue(temp);
                        break;
            case 2 :    obj.dequeue();
                        obj.display();
                        break;
            case 3 :    temp=obj.peek();
                        if(temp==-1) {
                            cout << "\nQueue is Empty.\n";
                        }
                        else {
                            cout << "\nFront Element of Queue\t:\t" << temp;
                        }
                        break;
            case 4 :    cout << "\nSize of Queue\t:\t" << obj.size();
                        break;
            case 5 :    exit(0);
                        break;
            default:    cout << "\nInvalid Input\n";
        }
    }
    return 0;
}

