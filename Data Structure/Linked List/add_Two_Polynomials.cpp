#include<iostream>
using namespace std;

struct node {
	int cof;
	int exp;
	node *next;
};
class poly {
	node *head,*temp,*t;
	public:
		poly() {
			head='\0';
			temp='\0';
		}
		void insert(int c, int e);
		void add();
		void display();
}o1,o2,o3;

void poly::insert(int c,int e) {
	temp=new node;
  	temp->cof=c;
  	temp->exp=e;
  	temp->next=NULL;
  	if( head == NULL) {
		head=temp;
      	}
  	else {
  		t=head;
  	    	while(t->next!=NULL) {
  			t=t->next;
		}
		t->next=temp;	
     	}
    	cout << "\n Polynomial  : ";
    	t=head;
    	cout << "(" << t->cof << "*y^" << t->exp << ")";
    	t=t->next;
  	while( t != NULL) { 
  		cout << "+" << "(" << t->cof << "*y^" << t->exp << ")";
  		t=t->next;
  	}
  	delete t;
}

void poly::add() {
	node* temp;
	node *p,*q,*r;
	p=o1.head;
	q=o2.head;
	while( p != NULL  &&  q != NULL ) {
		temp=new node;
		temp->next=NULL;
		if(p->exp==q->exp) {
			temp->exp=p->exp;
			temp->cof=p->cof+q->cof;
			p=p->next;
			q=q->next;
		}
		else if(p->exp>q->exp) {
			temp->exp=p->exp;
			temp->cof=p->cof;
			p=p->next;
		}
		else {
			temp->exp=q->exp;
			temp->cof=q->cof;
			q=q->next;
		}
		if( head == NULL ) {
			head=temp;
		}
		else {
			r=head;
			while(r->next!='\0')
			r=r->next;
			r->next=temp;
		}
	}
	while( p != NULL ) {
		temp=new node;
		temp->next=NULL;
		temp->cof=p->cof;
		temp->exp=p->exp;
		p=p->next;
		if(head==NULL) {
			head=temp;
		}
		else {
			r=head;
			while(r->next!='\0')
			r=r->next;
			r->next=temp;
		}
		
	}
	while( q != NULL ) {
		temp=new node;
		temp->next=NULL;
		temp->cof=q->cof;
		temp->exp=q->exp;
		q=q->next;
		if(head==NULL) {
			head=temp;
		}
		else {
			r=head;
			while( r->next != '\0' ) {
				r=r->next;
			}
			r->next=temp;
		}
	}
}
void poly::display() {
	cout << "\n Polynomial  : ";
    	node* t=head;
    	cout << "(" << t->cof << "*y^" << t->exp << ")";
    	t=t->next;
  	while(t != NULL) { 
  		cout << "+" << "(" << t->cof << "*y^" << t->exp << ")";
  		t=t->next;
  	}
  	delete t;
}

int main() {
	cout << "\n Add two polynomials   .....!!!!!!!!!!!!!";
	int choice,coef,exp;
	while(1) {
	 	cout << "\n\n\n\t\t\tMenu \n 1. Insert 1st polynomial :";
		cout << "\n 2. Insert 2nd Polynomial : \n 3. Add :";
		cout << "\n 4. Display After Adding :\n 5. Exit :\n Enter Your Choice :";
		cin>>choice;
		switch(choice) {
			case 1	:	cout << "\n Enter Exponent in Decsending order ...........!!!!!!!!!!!";
			       		cout << "\n \n  Enter Coeffiecient :";
			       		cin >> coef;
			       		cout << "\n \n  Enter Exponent :";
			       		cin >> exp;
			       		o1.insert(coef,exp);
			       		break;
			case 2	:	cout << "\n Enter Exponent in Decsending order ...........!!!!!!!!!!!";
			       		cout << "\n \n  Enter Coeffiecient :";
		           		cin >> coef;
			       		cout << "\n \n  Enter Exponent :";
			       		cin >> exp;
			       		o2.insert(coef,exp);
			       		break;
			case 3	:	o3.add();
			        	break;
			case 4	:	o3.display();
			       		break;
			case 5	:	exit(0);
			       		break;
		    	default : 	cout << "\n\n Invalid Choice ";
		}
	}
	return 0;
}
