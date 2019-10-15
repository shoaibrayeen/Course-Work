#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
	node *prev;
};

class cdll {
	node *head,*tail,*temp,*t;
	int size;
	public:
		cdll();
		void insert_beg( int );
		void insert_end( int );
		void delete_pos( int );
		int search(int v);
		void reverse();
		void display();
};

cdll::cdll() {
	head=NULL;
	tail=NULL;
	temp=NULL;
	t=NULL;
	size=0;
}

void cdll::insert_beg(int value) {
	temp=new node;
	temp->data=value;
  	temp->next=NULL;
  	temp->prev=NULL;
	if( head == NULL && tail == NULL ) {
		head=temp;
		tail=temp;
		head->next=head;
		head->prev=head;
	}
	else {
		temp->next=head;
		head->prev=temp;
		temp->prev=tail;
      		tail->next=temp;
      		head=temp;
	}
	cout << "\n Element Successfully Inserted ..!!!!!!!";
	size++;
}

void cdll::insert_end(int value) {
	temp=new node;
	temp->data=value;
  	temp->next=NULL;
  	temp->prev=NULL;
  	if( ( head == NULL )  &&  ( tail == NULL ) ) {
  		head=temp;
  		tail=temp;
  		head->next=head;
		head->prev=head;
  	}
  	else {
  		tail->next=temp;
  		temp->prev=tail;
  		temp->next=head;
	    	head->prev=temp;
	    	tail=temp;
  	}
  	cout << "\n Element Successfully Inserted ...!!!!!!!";
  	size++;
}

void cdll::delete_pos(int pos) {
	if(pos <= size && pos > 0) {
		if( pos == 1 ) {
	    		t=head;
	        	if(head==tail) {
	        		head=NULL;
		       		tail=NULL;
	        	}
	        	else {
	        		head=head->next;
	        		tail->next=head;
		        	head->prev=tail;
		        	delete t;
	       	 	}	
	   	}
    		else if( pos == size ) {
			t=tail;
			tail=tail->prev;
			tail->next=head;
			head->prev=tail;
			delete t;
		}	
		else if( pos <= size/2 ) {
			int count=1;
			t=head;
			while( count < pos ) {
				t=t->next;
				count++;
			}
			node *p,*q;
			p=t->prev;
			q=t->next;
			p->next=q;
			q->prev=p;
			delete t;
		}
		else if( pos > size/2 ) {
			int pos_end=size-pos+1;
			int count=1;
			t=tail;
			while( count < pos_end ) {
				t=t->prev;
				count++;
			}
			node *p,*q;
			p=t->prev;
			q=t->next;
			q->prev=p;
			p->next=q;
			delete t;
		}
		cout << "\n Element Successfully Deleted ........!!!!!!!!!!";
    		size--;
	}
	else {
		cout << "\n\n Invalid position \n ";
	}
}

int cdll::search(int value) {
	if(size==0) {
		cout << "\n\n List is Empty...!!!!";
	    	return -1;
    	}
	else {
		t=head;
  	    	int loc=1;
  	    	if(head->data==value) {
  	    		return loc;
		}
  	    	while(t->next!=head) {
  	    		if(t->data==value) {
  		    		return loc;
			}
  		    	else {
  		    		loc++;
  			    	t=t->next;
  		    	}  
  	    	}
  	    	if(t->next==head && t->data==value) {
  	    		return loc;
		}
  	    	return 0;
	}
}

void cdll::reverse() {
	if(head==NULL || head->next==head) {
		return;
	}
	else {
		node *p;
        	t=head;
	   	while(1) {
	   		p=t->next;
	   		t->next=t->prev;
	   		t->prev=p;
	   	    	t=t->prev;
	   	    	if( t == head ) {
	   	    		break;
			}
	   	}
	   	p=head;
	   	head=tail;
	   	tail=p;
	   	cout << "\n List Successfully Reverse ...!!!!!!!!";
	}
}

void cdll::display() {
	if(head==NULL && tail==NULL) {
		cout << "\n List is Empty.......!!!!!!!!!!!!";
	}
	else {
		cout << "\n List : ";
  	    	t=head;
  	    	while( t != tail ) {
  	    		cout << t->data << "->";
  		    	t=t->next;
  	    	}
  	    	cout << t->data;
	}
    	cout << "\n\n\n  Size of Linked list :" << size;
}	

int main() {
	int choice,value;
	cdll obj;
    	while(1) {
    	cout << "\n\n\t     MENU";
     	cout << "\n 1. Insert Linked List-Beg :";
    	cout << "\n 2. Insert Linked List-End :";
        cout << "\n 3. Delete Linked List-Position  :";
        cout << "\n 4. Search a number : ";
     	cout << "\n 5. Reverse Linked List :";
        cout << "\n 6. Display Linked List :";
	cout << "\n 7. Exit:\n ";
  	cout << "\n Enter your Choice : ";
	cin >> choice;
    	switch(choice) {
    		case 1	:	cout << "\n Enter the value :";
   		        	cin >> value;
    		        	obj.insert_beg(value);
    	           		break;
    		case 2	: 	cout << "\n Enter the value :";
    		        	cin >> value;
    		        	obj.insert_end(value);
    		        	break;
    		case 3	:	cout << "\n Enter the position :";
    		       		cin >> value;
    		       		obj.delete_pos(value);
    		       		break;
    		case 4	:	cout << "\n Enter element which you want to search: ";
    		       		cin>>value;
    		       		int return_value;
    		       		return_value=obj.search(value);
    		       		if( return_value == -1) { 
				}
    		       		else if(return_value == 0) {
    		       			cout << "\n Element Not Found \n";
				}
    		       		else {
    		       		cout << "\n Element found at " << return_value << " postion ";
				}
    		       		break;
    		case 5	:	obj.reverse();
    		        	break;
    	    	case 6	: 	obj.display();
    	            		break;
    		case 7	: 	exit(0);
    		        	break;
    		default	:	cout << "\n\n Invalid Choice ";
    	}
    }
    return 0;
}
