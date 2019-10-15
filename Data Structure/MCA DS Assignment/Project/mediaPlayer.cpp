//
//  mediaPlayer.cpp
//  Project-DS
//
//  Created by Mohd Shoaib Rayeen on 04/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node {
    string song;
    string album;
    string artist;
    node* next;
    node* prev;
};

class mediaplayer {
    public:
    node* head;
    node* tail;
    mediaplayer();
    void insert();
    void display(node*);
    node *mergeSort(node * , int);
    node *split(node *);
    node *merge_artist(node *, node *);
    node *merge_album(node *, node *);
    node *merge_song(node *, node *);
};

mediaplayer::mediaplayer() {
    head = NULL;
    tail = NULL;
}

void mediaplayer::insert() {
    ifstream myfile ("Songs.txt");
    if (myfile) {
        string line;
        while ( getline (myfile,line) ) {
            int count= 0;
            string song_name = "";
            string album_name = "";
            string artist_name = "";
            for(int i = 0; i < line.length(); ++i) {
                if(count == 0){
                    song_name += line[i];
                }
                else if(count == 1) {
                    album_name += line[i];
                }
                else {
                    artist_name += line[i];
                }
                if(line.substr(i,3).compare(" , ") == 0) {
                    ++count;
                    i = i+2;
                }
            }
            node* newnode = new node;
            newnode->song = song_name;
            newnode->album = album_name;
            newnode->artist = artist_name;
            newnode->next = NULL;
            newnode->prev = NULL;
            if(head == NULL) {
                head = newnode;
                tail = newnode;
            }
            else {
                newnode->prev = tail;
                tail->next = newnode;
                tail = newnode;
            }
        }
        myfile.close();
    }
    else {
        cout << "\nUnable to open file\n";
    }
}
node *mediaplayer::split(node *head)
{
    node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    node *temp = slow->next;
    slow->next = NULL;
    return temp;
}
node *mediaplayer::merge_song(node *first, node *second )
{
    // If first linked list is empty
    if (!first)
        return second;
    
    // If second linked list is empty
    if (!second)
        return first;
    
    // Pick the smaller value
    if (first->song < second->song)
    {
        first->next = merge_song(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge_song(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
node *mediaplayer::merge_album(node *first, node *second )
{
    // If first linked list is empty
    if (!first)
        return second;
    
    // If second linked list is empty
    if (!second)
        return first;
    
    // Pick the smaller value
    if (first->album < second->album)
    {
        first->next = merge_album(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge_album(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
node *mediaplayer::merge_artist(node *first, node *second )
{
    // If first linked list is empty
    if (!first)
        return second;
    
    // If second linked list is empty
    if (!second)
        return first;
    
    // Pick the smaller value
    if (first->artist < second->artist)
    {
        first->next = merge_artist(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge_artist(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
// Function to do merge sort
node *mediaplayer::mergeSort(node *head , int pref)
{
    if (!head || !head->next)
        return head;
    node *second = split(head);
    
    // Recur for left and right halves
    head = mergeSort(head , pref);
    second = mergeSort(second,pref);
    
    // Merge the two sorted halves
    if(pref == 0) {
        return merge_song(head,second);
    }
    else if(pref  == 1 ) {
        return merge_artist(head, second);
    }
    else {
        return merge_album(head, second);
    }
}
void mediaplayer::display(node * head) {
    if(head == NULL ) {
        cout << "\nThere is No Song in Media Player.\n";
        return;
    }
    node* temp = head;
    while(temp != tail ) {
        cout << endl << temp->song << "| " << temp->album << "| " << temp->artist;
        temp = temp->next;
    }
    cout << endl << temp->song << "| " << temp->album << "| " << temp->artist;
    cout << endl << endl;
}
int main() {
    mediaplayer obj;
    obj.insert();
    bool done = true;
    char choice;
    while(done) {
        cout << "\n1.Songs";
        cout << "\n2.Artists";
        cout << "\n3.Albums";
        cout << "\n4.Exit";
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice;
        switch (choice) {
            case '1' :  obj.head = obj.mergeSort(obj.head,0);
                        cout << "\nSongs\n";
                        obj.display(obj.head);
                        break;
            case '2' :  cout << "\nArtists\n";
                        obj.head = obj.mergeSort(obj.head,1);
                        obj.display(obj.head);
                        break;
            case '3' :  cout << "\nAlbums\n";
                        obj.head = obj.mergeSort(obj.head,2);
                        obj.display(obj.head);
                        break;
            case '4' :  done = false;
                        break;
            default:    cout << "\nInvalid Choice\n";
                        break;
        }
    }
    return 0;
}
