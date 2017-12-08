#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
class node{
	public:
		node(){ next=NULL; }
		T data;
		node* next;
};

template<class T>
class ll{
	public:
		ll() { head=tail=NULL; }
		~ll();
		node<T>* head;
		node<T>* tail;
		void insert(T);
		void isort();
		void display();
};

template<class T>
ll<T>::~ll(){
	node<T>* t=head;
	while(head!=NULL){
	head=head->next;
	delete t;
	t=head;
	}
}

template<class T>
void ll<T>::display(){
	node<T>* t=head;
	cout<<"\n";
	while(t!=NULL){
	cout<<" "<<t->data;
	t=t->next;
	}
}

template<class T>
void ll<T>::insert(T val){
	node<T>* temp=new node<T>;
	temp->data=val;
	if(head==NULL)
		head=tail=temp;
	else{	tail->next=temp;
		tail=temp;
	     }
}

template<class T>
void ll<T>::isort(){
	node<T> *p, *q;
	T key, temp;
	if(head==NULL) return;
	for(p=head->next; p!=NULL; p=p->next){
		q=head;
		key=p->data;
		while(q!=p){
			if(q->data>key){
				temp=q->data;
				q->data=key;
				key=temp;
			}
			q=q->next;
		}
		p->data=key;
	}
}
class bsort{
	public:
		int size;
		float ar[20];
		void binsert();
		void bdisplay();
		void sort();
};

void bsort::binsert(){
	cout<<"Enter the size of array\t:\t";
	cin>>size;
	cout<<"Enter the array elements:\n";
	for(int i=0; i<size; i++){
		cout<<"A["<<i<<"]\t:\t";
		cin>>ar[i];
	}
}

void bsort::bdisplay(){
	cout<<"\n";
	for(int i=0; i<size; i++)
		cout<<" "<<ar[i];
}

void bsort::sort(){
	const int n=10;
	int k;
	int m=0;
	ll<float> ob[n];
	for(int i=0; i<size; i++){
		k=int(ar[i]*n);
		ob[k].insert(ar[i]);
	}
	for(int i=0; i<n; i++)
		ob[i].isort();
	for(int i=0; i<n; i++){
		node<float>* t=ob[i].head;
		while(t!=NULL){
			ar[m++]=t->data;
			t=t->next;
		}
	}
	
}

int main(){
	bsort obj;
	obj.binsert();
	obj.bdisplay();
	obj.sort();
	obj.bdisplay();
	cout<<"\n\n";
	return 0;
}
