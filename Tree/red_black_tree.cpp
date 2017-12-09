#include<iostream>
#include<cstdlib>
using namespace std;
int d=0;
//--------------------------------------------node()-----------------------------------------------
class node{
	public:
		node(){ left=right=parent=NULL; color='R'; }
		int key;
		char color;
		node* left;
		node* right;
		node* parent;
};
//------------------------------------------rbt----------------------------------------------------
class rbt{
	public:
		rbt(){ nil=new node; nil->left=nil->right=nil->parent=NULL; nil->color='B'; root=nil; }
	//	~rbt();
		void del(node*);
		node* root;
		node* nil;
		void LR(node*);
		void RR(node*);
		void inorder(node*);
		void insert(int);
		void ins_fixup(node*);
		node* search(int);
		void deletion(node*);
		void del_fixup(node*);
		node* successor(node*);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~del~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void rbt::del(node* r){
	if(r==nil) return;
	del(r->left);
	del(r->right);
	delete r;
	//cout<<++d<<"\n";
	return;
}
//---------------------------------------------successor-------------------------------------------
node* rbt::successor(node* t){
	t=t->right;
	while(t->left!=nil) t=t->left;
	return t;
}
//----------------------------------------------rotations------------------------------------------
void rbt::LR(node* x){
	node* y=x->right;
	x->right=y->left;
	if(y->left!=nil)
		y->left->parent=x;
	y->parent=x->parent;
	if(x->parent==nil)
		root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else	x->parent->right=y;
	y->left=x;
	x->parent=y;
}

void rbt::RR(node* x){
	node* y=x->left;
	x->left=y->right;
	if(y->right!=nil)
		y->right->parent=x;
	y->parent=x->parent;
	if(x->parent==nil)
		root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else
		x->parent->right=y;
	y->right=x;
	x->parent=y;
}
//------------------------------------------------inorder----------------------------------------------------------
void rbt::inorder(node* r){
	if(r==nil) return;
	inorder(r->left);
	cout<<" |"<<r->key<<" "<<r->color<<"| ";
	inorder(r->right);
}
//----------------------------------------------search-------------------------------------------------------------
node* rbt::search(int val){
	node* t=root;
	while(t!=nil && t->key!=val){
		if(val<t->key) t=t->left;
		else t=t->right;
	}
	return t;
}
//---------------------------------------insertions------------------------------------------------
void rbt::insert(int val){
	node* temp=new node;
	temp->key=val;
	temp->left=temp->right=temp->parent=nil;
	if(root==nil){ root=temp; }
	else{
		node* p=root;
		node* q;
		while(p!=nil){
			q=p;
			if(val<=p->key) p=p->left;
			else		p=p->right;
		}
		if(val<q->key)	q->left=temp;
		else		q->right=temp;
		temp->parent=q;
	}
	ins_fixup(temp);
}

void rbt::ins_fixup(node* z){
	while(z->parent->color=='R'){
		if(z->parent==z->parent->parent->left){
			node* y=z->parent->parent->right;
			if(y->color=='R'){
				z->parent->color=y->color='B';
				z->parent->parent->color='R';
				z=z->parent->parent;
			}
			else{
				if(z==z->parent->right){
					z=z->parent;
					LR(z);
				}
				z->parent->color='B';
				z->parent->parent->color='R';
				RR(z->parent->parent);
			}
		}
		else{
			node* y=z->parent->parent->left;
			if(y->color=='R'){
				z->parent->color=y->color='B';
				z->parent->parent->color='R';
				z=z->parent->parent;
			}
			else{
				if(z==z->parent->left){
					z=z->parent;
					RR(z);
				}
				z->parent->color='B';
				z->parent->parent->color='R';
				LR(z->parent->parent);
			}
		}
	}
	root->color='B';
}
//----------------------------------------------deletion------------------------------------
void rbt::deletion(node* z){
	char clr;
	node* x;
	if(z->left==nil && z->right==nil){								//z has no child
		clr=z->color;
		if(z==root){ delete z; root=nil; return; }
		else if(z==z->parent->left){ z->parent->left=nil; }
		else { z->parent->right=nil; }
		nil->parent=z->parent;
		x=nil;
		delete z;
	}
	else if(z->left!=nil && z->right==nil){								//z ha no right child
		x=z->left;
		if(z==root){ root=root->left; root->parent=nil; delete z; root->color='B'; return; }
		else if(z==z->parent->left){ z->parent->left=x; }
		else { z->parent->right=x; }
		x->parent=z->parent;
		clr=z->color;
		delete z;
	}
	else if(z->left==nil && z->right!=nil){								//z has no left child
		x=z->right;
		if(z==root){ root=root->right; root->parent=nil; delete z; root->color='B'; return; }
		else if(z==z->parent->left){ z->parent->left=x; }
		else { z->parent->right=x; }
		x->parent=z->parent;
		clr=z->color;
		delete z;
	}
	else{												//z has both childs
		node* y=successor(z);
		z->key=y->key;
		x=y->right;
		if(y==y->parent->left) { y->parent->left=x; }
		else { y->parent->right=x; }
		x->parent=y->parent;
		clr=y->color;
		delete y;
	}
	if(clr=='B')
		del_fixup(x);
}
void rbt::del_fixup(node* x){
	while(x!=root && x->color=='B'){
		if(x==x->parent->left){
			node* w=x->parent->right;
			if(w->color=='R'){
				w->color='B';
				x->parent->color='R';
				LR(x->parent);
				w=x->parent->right;
			}
			if(w->left->color=='B' && w->right->color=='B'){
				w->color='R';
				x=x->parent;
			}
			else{
				if(w->right->color=='B'){
					w->left->color='B';
					w->color='R';
					RR(w);
					w=x->parent->right;
				}
				w->color=x->parent->color;
				x->parent->color='B';
				w->right->color='B';
				LR(x->parent);
				x=root;
			}
		}
		else{
			node* w=x->parent->left;
			if(w->color=='R'){
				w->color='B';
				x->parent->color='R';
				RR(x->parent);
				w=x->parent->left;
			}
			if(w->left->color=='B' && w->right->color=='B'){
				w->color='R';
				x=x->parent;
			}
			else{
				if(w->left->color=='B'){
					w->right->color='B';
					w->color='R';
					LR(w);
					w=x->parent->left;
				}
				w->color=x->parent->color;
				x->parent->color='B';
				w->left->color='B';
				RR(x->parent);
				x=root;
			}
		}
	}
	x->color='B';
}
//---------------------------------------------------main()---------------------------------
int main(){
	rbt obj;
	int ch, n;
	node* t;
	do{
		cout<<"\n\nInorder Traversal\t:\t";
		if(obj.root==obj.nil)cout<<"Empty.";
		else { obj.inorder(obj.root); cout<<"\nROOT = "<<obj.root->key; }
		cout<<"\n\n1.Insertion.\n2.Deletion.\n3.Search a node.\n4.Exit.\t";
		cin>>ch;
		if(ch==1){
			cout<<"Enter elements or -1 to stop.\n";
			cin>>n;
			while(n!=-1){
				obj.insert(n);
				cin>>n;
			}
		}
		else if(ch==2){
			cout<<"Enter the value to be deleted\t:\t";
			cin>>n;
			t=obj.search(n);
			if(t==obj.nil)cout<<"The value "<<n<<" is not present in the tree.";
			else obj.deletion(t);
		}
		else if(ch==3){
			cout<<"Enter the value to be searched\t:\t";
			cin>>n;
			t=obj.search(n);
			if(t==obj.nil) cout<<"The number "<<n<<" is not present in the tree.";
			else cout<<"The number "<<n<<" is present and its color is "<<t->color<<".";
		}
		else if(ch==4) { }
		else cout<<"Invalid option.";
	}while(ch!=4);
	obj.del(obj.root);
	delete obj.nil;
	return 0;
}
