#include<iostream>
#include<conio.h>
using namespace std;

struct node {
	char data;
	node* next;
};

class stack {
	public:
		node* top;
		stack();
		void push(char);
		char pop();
};

stack::stack() {
	top=NULL;
}

void stack::push(char ch) {
	node* temp=new node;
	temp->data=ch;
	temp->next=NULL;
	if(top==NULL) {
		top=temp;
	}
	else {
		temp->next=top;
		top=temp;
	}
	
}

char stack::pop() {
	if(top!=NULL) {
		node* t=top;
		char ch=top->data;
		top=top->next;
		delete t;
		return ch;
	}
}

int main() {
	cout<<"\n Add large integer ...............!!!!!!!!!!!!!!!!!!!!";
	stack num1,num2,ans;
	int sum=0;
	int c=0;
	char ch;
	ch='0';
	int n1,n2;
	cout<<"\nEnter First Large Number.\t";
	ch=getche();
	while(ch!=13) {
		num1.push(ch);
		ch=getche();
	}
	ch='0';
	cout<<"\nEnter Second Large Number.\t";
	ch=getche();
	while(ch!=13) {
		num2.push(ch);
		ch=getche();
	}
	while(num1.top!=NULL&&num2.top!=NULL) {
		n1=int(num1.pop())-48;
		n2=int(num2.pop())-48;
		sum=n1+n2+c;
		c=sum/10;
		sum=sum%10;
		ch=char(sum+48);
		ans.push(ch);
	}
	while(num1.top!=NULL) {
		n1=int(num1.pop())-48;
		sum=n1+c;
		c=sum/10;
		sum=sum%10;
		ch=char(sum+48);
		ans.push(ch);
	}
	while(num2.top!=NULL) {
		n2=int(num2.pop())-48;
		sum=n2+c;
		c=sum/10;
		sum=sum%10;
		ch=char(sum+48);
		ans.push(ch);
	}
	if(c==1) {
	ch=char(c+48);
	ans.push(ch);
    	} 
	cout<<"\n\nThe Answer Is :\t";
	while(ans.top!=NULL) {
		cout<<ans.pop();
	}
	getch();
	return 0;
}
