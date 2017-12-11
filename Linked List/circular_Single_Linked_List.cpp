#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

class csll {
	node *head , *temp , *T;
	int size;
	public:
		csll();
		void insert_beg(int);
		void insert_end(int);
		void delete_pos(int);
		int search(int);
		void reverse();
		void display();
};

csll::csll() {
	head=NULL;
  	temp=NULL;
  	T=NULL;
	size=0;
}

void csll::insert_beg(int value) {
	temp=new node;
  	temp->data=value;
  	temp->next=NULL;
  	if(head==NULL) {
  		head=temp;
	    	head->next=head;
  	}
    	else {
    		T=head;
  	    	while(T->next!=head) {
  	  	     T=T->next;
		}
  	    	T->next=temp;
        	temp->next=head;
  	    	head=temp;
    	}
    	cout << "\n Element Successfully Inserted ..!!!!!!!";
  	size++;
}

void csll::insert_end(int value) {
	temp=new node;
  	temp->data=value;
  	temp->next=NULL;
    	if(head==NULL) {
    		head=temp;
	    	head->next=head;
    	}
  	else {
  		T=head;
  	    	while(T->next!=head) {
  			T=T->next;
		}
		T->next=temp;	
		temp->next=head;
    	}
    	cout << "\n Element Successfully Inserted ..!!!!!!!";
  	size++;
}

void csll::delete_pos(int pos) {
	if( pos <= size && pos > 0 ) {
		int count=1;
		if( pos == 1 ) {
  	        	if(head->next==head) {
  	        		delete head;
  	        		head=NULL;
  	        	}
  	        	else {
  	        		T=head;
  	        		while(T->next!=head) {
  	                 		T=T->next;
				}
  	            		T->next=head->next;
  	            		T=head;
  	            		head=head->next;
  	            		delete T;
  	        	}
  	    	}
        	else if(pos <= size) {
        		T=head;
    	    		node *p=T->next;
    	    		while( count < ( pos - 1 ) ) {
    	    			T=T->next;
    		    		p=T->next;
    		    		count++;
    	    		}
    			T->next=p->next;
    			delete p;
        	}
        	cout << "\n Element Successfully Deleted ........!!!!!!!!!!";
        	size--;
    	}
	else {
		cout << "\n\n Invalid Size \n";
	}
}

int csll::search(int value) {
	if(size==0) {
		cout << "\n\n List is Empty...!!!!";
	    	return -1;
    	}
	else {
		T=head;
  	    	int loc=1;
  	    	if(head->data==value) {
  	    		return loc;
		}
  	    	while(T->next!=head) {
  	    		if(T->data==value) {
  		    		return loc;
			}
  			else {
  		    		loc++;
  				T=T->next;
  			}  
  	    	}
  	    	if( T->next == head && T->data == value ) {
  	    		return loc;
		}
  	    	return 0;
	}
}

void csll::reverse() {
	node *p,*q;
    	if(head == NULL) {
		cout << "\n\n List is Empty ................!!!!!!!!!!!!!!!!\n ";
        	return;
    	}
	else {
		T=head;
		p=T->next;
		q=p->next;
		while( p != head) {
           		p->next=T;
            		T=p;
            		p=q;
            		q=q->next;
        	} 
        	head->next=T;
        	head=T;
        	cout << "\n\n List Successfully Reverse ...!!!!!!!!";
	}
}

void csll::display() {
  	if(head==NULL) {
		cout << "\n\n List is Empty....!!!!!!!";
	}
	else {
		cout << "\n\n List : ";
		T=head;
  	    	while(T->next!=head) {
  	    		cout << T->data << "->";
  		    	T=T->next;
  	    	}
  	    	cout << T->data;
	}  	cout << "\n\n Size of List :" << size;
}

int main() {
    int choice,value;
    csll obj;
    while(1) {
    	cout << "\n\n\t     MENU";
     	cout << "\n 1. Insert Linked List-Beg:";
    	cout << "\n 2. Insert Linked List-End:";
    	cout << "\n 3. Delete Linked List-Position :";
    	cout << "\n 4. Search a number :";
	cout << "\n 5. Reverse of Linked List :";
     	cout << "\n 6. Display Linked List:";
     	cout << "\n 7. Exit ";
    	cout << "\n Enter your Choice : ";
	cin >> choice;
    	switch(choice) {
       		case 1	:	cout << "\n Enter the element : ";
			       	cin >> value;
				obj.insert_beg(value);
     	           		break;
     	    	case 2	:	cout << "\n Enter the element : ";
			       	cin >> value;
				obj.insert_end(value);
       	           		break;
     	    	case 3	:	cout << "\n Enter Postion of element which you eant to delete : ";
				cin >> value;
				obj.delete_pos(value);
     	           		break;
     	    	case 4	:	cout << "\n Enter the element which you want to search : ";
     	           		cin>>value;
     	           		int location;
     	           		location=obj.search(value);
     	           		if( location == -1) {  
				}
     	           		else if( location == 0 ) {
     	           			cout << "\n Element not found ";
     	           		}
				else {
     	           			cout << "\n Elemnet found at " << location << " position ";
     	           		}
     	           		break;
     	    	case 5	:	obj.reverse();
    	           		break;     	           
    	    	case 6	:	obj.display();
    	           		break;
            	case 7	:	exit(0);
			       	break;    	    
    	    	default	:	cout << "\n Invalid Choice\n ";
    	}
    }
    return 0;
}
