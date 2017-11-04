#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
	node *prev;
};

int size=0;
class dLL {
	node *head,*tail,*temp,*t;
	public:
		dLL() {
			head=NULL;
			tail=NULL;
			temp=NULL;
			t=NULL;
		}
		void insert_sim(int v);
		void insert_beg(int v);
		void insert_pos(int pos,int v);
		void delete_beg();
		void delete_end();
		void delete_pos(int p);
		int search(int v);
		void reverse();
		void display();
};

void dLL::insert_sim(int v) {
	temp=new node;
	temp->data=v;
  	temp->next=NULL;
  	temp->prev=NULL;
  	if( ( head==NULL)  &&  (tail==NULL) ) {
  		head=temp;
  	}
  	else {
  		tail->next=temp;
  		temp->prev=tail;
  	}
  	tail=temp;
  	size++;
}

void dLL::insert_beg(int v) {
	temp=new node;
	temp->data=v;
  	temp->next=NULL;
  	temp->prev=NULL;
	if(head==NULL) {
		tail=temp;
	}
	else {
		head->prev=temp;
		temp->next=head;
	}
	head=temp;
	size++;
}

void dLL::insert_pos(int pos,int v) {
	if(pos<=size && pos>0) {
		
		temp=new node;
  		temp->next=NULL;
  		temp->prev=NULL;
  		temp->data=v;
  		int ct=1;
  		if(pos<=size/2) {
  	    		t=head;
        		while(ct<pos-1) {
  		    		t=t->next;
  		    		ct++;
  	    		}
  	    		temp->next=t->next;
  	    		(t->next)->prev=temp;
  	    		t->next=temp;
  	    		temp->prev=t;
    		}
    		else if(pos>size/2) {
  			t=tail;
  			int pose=size-pos+2;
  	    		while(ct<pose-1) {
  		    		t=t->prev;
  		    		ct++;
  	    		}
			temp->prev=t->prev;
  	    		(t->prev)->next=temp;
  	    		t->prev=temp;
  	    		temp->next=t;
    		}
  	  	size++;
 	}
     	else {
		cout <<" \n Invalid Position ";
	}
}

void dLL::delete_pos(int p) {
	if(p<=size && p>0) {
		if(p==1) {
	   		t=head;
	  		if(head==tail) {
		  		head=NULL;
		  		tail=NULL;
	   		}
	   		else {
		  		head=head->next;
		  		head->prev=NULL;
		  		delete t;
	   		}	
		}
    		else if(p==size) {
			t=tail;
			tail=tail->prev;
			tail->next=NULL;
			delete t;
		}
		else if(p<=size/2) {
			int ct=1;
			t=head;
			while(ct<p) {
				t=t->next;
				ct++;
			}
			node *p,*q;
			p=t->prev;
			q=t->next;
			p->next=q;
			q->prev=p;
			delete t;
		}
		else if(p>size/2) {
			int pe=size-p+1;
			int ct=1;
			t=tail;
			while(ct<pe) {
				t=t->prev;
				ct++;
			}
			node *p,*q;
			p=t->prev;
			q=t->next;
			q->prev=p;
			p->next=q;
			delete t;
		}
       		size--;
	}
	else {
		cout << "\n Invalid position \n ";
	}
}

void dLL::reverse() {
	node *p;
       	t=head;
       	if(head==NULL) {
		cout << "\n List is Empty \n ";
	}
	else {
	   	while(t!=NULL) {
	   		p=t->next;
	   		t->next=t->prev;
	   		t->prev=p;
	   		t=t->prev;
	   	}
	   	p=head;
	   	head=tail;
	   	tail=p;
	}

}

int dLL::search(int v) {
	int ct=1;
	t=head;
	while(t!=NULL) {
		if(t->data==v) {
			return ct;
		}
		else {
			ct++;
			t=t->next;
   	 	}
	}
	return 0;
}

void dLL::display() {
	cout << "\n Data : ";
  	node *t=head;
  	while(t!=NULL) { 
  		cout<<t->data<<"->";
  		t=t->next;
  	}
  	delete t;
    	cout << "\n\n\n  Size of Linked list :" << size;
}
	
int main() {
	int c,v;
	dLL o;
    	while(1) {
    	cout << "\n\n\t     MENU";
     	cout << "\n 1. Insert Linked List-end:";
    	cout << "\n 2. Insert Linked List-beg:";
    	cout << "\n 3. Insert Linked List-Location:";
        cout << "\n 4. Delete Linked List :";
        cout << "\n 5. Reverse Linked List :";
        cout << "\n 6. Search a number : ";
     	cout << "\n 7. Exit:\n ";
  	cout << "\n Enter your Choice : ";
	cin >> c;
    	switch(c) {
    		case 1: cout<<"\n Enter the value :";
    		        cin>>v;
    		        o.insert_sim(v);
    		        o.display();
    		        break;
    		case 2: cout<<"\n Enter the value :";
    		        cin>>v;
    		        o.insert_beg(v);
    		        o.display();
    	           	break;
    		case 3:	int p;
		        cout<<"\n Enter the position: ";
			cin>>p;
			cout<<"\n Enter the value :";
    		        cin>>v;
    		        o.insert_pos(p,v);
    		        o.display();
    		        break;
    		case 4:	cout<<"\n Enter the position :";
    		       	int k;
    		       	cin>>k;
    		       	o.delete_pos(k);
    		       	o.display();
    		       	break;
    		case 5: o.reverse();
    		        o.display();
    		        break;
    		case 6:	cout<<"\n Enter element which you want to search: ";
    		       	cin>>v;
    		       	int c;
    		       	c=o.search(v);
    		       	if(c==0) {
    		       		cout << "\n Element Not Found \n";
			}
    		       	else {
    		       		cout << "\n Element found at " << c << " postion ";
			}
    		       	break;
    		case 7: exit(0);
    		        break;
    		default:cout << "\n Invalid ";
    	}
    }
    	return 0;
}
