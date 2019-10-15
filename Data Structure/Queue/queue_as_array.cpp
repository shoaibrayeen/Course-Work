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
    //private vairable of class
    int *arr;       // dynamic array
    int front;      //pointing index of first element of queue
    int rear;       //pointing index of last element of queue
    public :
    queue();        //constructor
    ~queue();       //destructor
    void enqueue(int &); 
    void dequeue();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    void display();
};

queue :: queue() {
    /*
     objective : constructor
     input parameter : none
     output parameter : none
     approach : assigning value to variables
     */
    arr = new int[MAXSIZE];
    front = -1;
    rear = -1;
}
queue :: ~queue() {
    /*
     objective : destructor of class
     input parameter : none
     output parameter : none
     approach : deleting dynamic array
     */
    delete[] arr;
}

void queue :: enqueue( int & newValue) {
    /*
     objective : enqueue function 
     input parameter : newValue which has to inserted into queue
     output parameter : none
     approach : inserting element at rear 
     */
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
    /*
     objective : dequeue function
     input parameter : none
     output parameter : none
     approach : removing front element of the queue
     */
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
    /*
     objective : returning front element
     input parameter : none
     output parameter : front element of array
     approach : accessing front element
     */
    if(isEmpty()) {
        return -1;
    }
    else {
        return arr[front];
    }
}

int queue:: size() {
    /*
     objective : counting number of elements in queue
     input parameter : none
     output parameter : size of current queue
     approach : using front and rear , calculating size
     */
    return (rear - front + 1);
    
}

bool queue::isFull() {
    /*
     objective : isFull()
     input parameter : none
     output parameter : true if queue is full.
     approach : camparing with MAXSIZE
     */
    if((rear + 1) == MAXSIZE) {
        return true;
    }
    return false;
}
bool queue::isEmpty() {
    /*
     objective : isEmpty()
     input parameter : none
     output parameter : true if queue is empty
     approach : comparing with rear and front
     */
    if( front == -1 && rear==-1) {
        return true;
    }
    return false;
}

void queue:: display() {
    /*
     objective : displaying elements of queue
     input parameter : none
     output parameter : none
     approach : using iteration from front to rear
     */
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

