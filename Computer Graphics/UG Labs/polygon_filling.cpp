#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

struct range  {
	int min , max;
};

void draw_line(int , int , int , int);
range min_max (int a[] , int n);
void draw_polygon(double x[] , double y[] , int n);
void fill_polygon(double x[] , double y[] , int n);

int main() {
	int gdriver = DETECT , gmode;
	double x[100] , y[100];
	int n;
	cout<<"Enter the number of coordinates : ";
	cin>>n;
	int i = 0 ;
	while(i<n) {
		cout<<"Enter abscissa of "<<i+1<<" coordinate : ";
		cin>>x[i];
		cout<<"Enter ordinate of "<<i+1<<" first coordinate : ";
		cin>>y[i];
		i++;
	}
	initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
	int errorcode = graphresult();
	if(errorcode != 0)
		cout<<grapherrormsg(errorcode);
	//draw_polygon(x,y,n);
	fill_polygon(x,y,n);
	getch();
	closegraph();
	return 0;
}

void draw_polygon(double x[] , double y[] , int n) {
	for(int i=0;i<n-1;i++) {
		draw_line(x[i],y[i],x[i+1],y[i+1]);
	}
	draw_line(x[n-1],y[n-1],x[0],y[0]);
}
void draw_line(int x1 , int y1 , int x2 , int y2) {
	int dx = x2 - x1 , dy = y2 - y1 , dr = dy , nr = dx , incx , incy;
	if(dx == 0 || dy==0) {
		line(x1,y1,x2,y2);
	}
	else if(abs(dy) > abs(dx)) {
	   incx = dx/abs(dx);
	   incy = dy/abs(dy);
	   int i=0 , sign_nr = incx;
	   while(y1!=y2) {
	       nr += dx;
	       //cout<<nr<<" ";
	       if(abs(nr) > abs(dr) ) {
		    x1=x1+incx;
		    nr = sign_nr*(abs(nr) - abs(dr));
	       }
	       putpixel(x1+1 , y1 , 15);
	       y1=y1+incy;
	       i++;
	   }
	   cout<<i<<" pixels plotted\n";
	}
	else {
	   incx = dx/abs(dx);
	   incy = dy/abs(dy);
	   int i=0 , sign_nr = incy;
	   nr = dy;
	   dr = dx;
	   while(x1!=x2) {
	       nr += dy;
	       //cout<<nr<<" ";
	       if(abs(nr) > abs(dr) ) {
		    y1=y1+incy;
		    nr = sign_nr*(abs(nr) - abs(dr));
	       }
	       putpixel(x1 , y1 , 15);
	       x1=x1+incx;
	       i++;
	   }
	   cout<<i<<" pixels plotted\nLast point plotted : "<<x1<<y1<<endl;
	}
	//setcolor(RED);
	//line(100,100,200,150);
}
struct node {
	double inc_x , y_max , x;
	node * next , * prev;
};
class list {

	void node_delete(node *l) {
		if(l->next!=NULL)
			l->next->prev = l->prev;
		if(l->prev!=NULL)
			l->prev->next = l->next;
		if(l==first)
			first=l->next;
		else if(l==last)
			last=l->prev;
		delete l;
	}
	public :
	node *first , *last;
	list() {
		first = NULL;
		last = NULL;
	}
	void insert(double x , double y_max , double inc_x) {
		node * temp = new node;
		temp -> inc_x = inc_x;
		temp -> y_max = y_max;
		temp -> x = x;
		temp -> next = NULL;
		temp -> prev = NULL;
		if(first == NULL) {
			last = first = temp;
			return;
		}
		else if(first -> x >= x) {
			temp->next = first;
			first -> prev = temp;
			first = temp;
			return;
		}
		node * p ;
		p = first;
		while(p != NULL && p-> x < x) {
			p=p->next;
		}
		if(p != NULL) {
			temp->prev = p->prev;
			temp->next = p;
			temp->prev->next = temp;
			p->prev = temp;
		}
		else {
			temp -> prev = last;
			last -> next  = temp;
			last = temp;
		}
		/*if(first == NULL) {
			first = last = temp;
		}
		else {
			last -> next = temp;
			temp -> prev = last;
			last = temp;
		}     */
	}
	void remove(double y) {
		node *p = first , *q;
		while(p!=NULL) {
			q = p->next;
			if(p->y_max == y) {
				node_delete(p);
			}
			p = q;
		}

	}
	void display() {
		node * p = first;
		while(p!=NULL) {
			cout<<p->x<<'\t';
			p=p->next;
		}
	}

};
range min_max(double a[] , int n) {
	int min , max , c =0;
	if(n%2==0) {
		if(a[0]>a[1]) {
			min = a[1];
			max = a[0];
		}
		else {
			min = a[0];
			max = a[1];
		}
		c=2;
	}
	else {
		min = max = a[0];
		c=1;
	}
	for(int i = c;i<n;i=i+2) {
		if(a[i+1] > a[i]) {
		       if(max < a[i+1])
				max = a[i+1];
		       if(min > a[i])
				min = a[i];
		}
		else {
			if(min > a[i+1]) {
				min = a[i+1];
			}
			if(max < a[i]) {
				max = a[i];
			}
		}
	}
	range r;
	r.min = min;
	r.max = max;
	return r;
}
void fill_polygon(double x[] , double y[] , int n) {
	range mm ;
	int scanlines;
	mm = min_max(y,n);
	scanlines = mm.max - mm.min;
	list AEL , *bucket;
	bucket = new list[scanlines];
	/*for(int i=0;i<n-1;i++) {
		if(y[i+1]-y[i] != 0) {
			double m = (x[i+1]-x[i])/(y[i+1]-y[i]);
			bucket[y[i]-mm.min].insert(x[i],y[i+1],m);
		}
	}
	cout<<mm.min<<" "<<mm.max<<endl;
	if(y[0]-y[n-1] != 0) {
		double m = (x[0]-x[n-1])/(y[0]-y[n-1]);
		bucket[y[n-1]-mm.min].insert(x[n-1],y[0],m);
	} */
	int i=0;
	if(y[0]<y[n-1] && y[0]<y[1]) {
		double m = (x[0]-x[1])/(y[0]-y[1]);
		bucket[y[0]-mm.min].insert(x[0],y[1],m);
		m = (x[0]-x[n-1])/(y[0]-y[n-1]);
		bucket[y[0]-mm.min].insert(x[0],y[n-1],m);
	}
	else if(y[0]>=y[n-1] && y[0]<y[1]) {
		double m = (x[0]-x[1])/(y[0]-y[1]);
		bucket[y[0]-mm.min].insert(x[0],y[1],m);
	}
	else if(y[0]>=y[1] && y[0]<y[n-1]) {
		double m = (x[0]-x[n-1])/(y[0]-y[n-1]);
		bucket[y[0]-mm.min].insert(x[0],y[n-1],m);
	}

	for(i=1;i<n-1;i++)  {
	      if(y[i]<y[i-1] && y[i]<y[i+1]) {
			double m = (x[i]-x[i+1])/(y[i]-y[i+1]);
			bucket[y[i]-mm.min].insert(x[i],y[i+1],m);
			m = (x[i]-x[i-1])/(y[i]-y[i-1]);
			bucket[y[i]-mm.min].insert(x[i],y[i-1],m);
	      }
	      else if(y[i]>=y[i-1] && y[i]<y[i+1]) {
			double m = (x[i]-x[i+1])/(y[i]-y[i+1]);
			bucket[y[i]-mm.min].insert(x[i],y[i+1],m);
	      }
	      else if(y[i]>=y[i+1] && y[i]<y[i-1]) {
			double m = (x[i]-x[i-1])/(y[i]-y[i-1]);
			bucket[y[i]-mm.min].insert(x[i],y[i-1],m);
	      }
	}
	i=n-1;
	cout<<y[i]<<endl;//y[i]
	if(y[n-1]<y[n-2] && y[n-1]<y[0]) {
			double m = (x[i]-x[0])/(y[i]-y[0]);
			bucket[y[i]-mm.min].insert(x[i],y[0],m);
			m = (x[i]-x[i-1])/(y[i]-y[i-1]);
			bucket[y[i]-mm.min].insert(x[i],y[i-1],m);
	}
	else if(y[n-1]>=y[n-2] && y[n-1]<y[0]) {
			double m = (x[i]-x[0])/(y[i]-y[0]);
			bucket[y[i]-mm.min].insert(x[i],y[0],m);
	}
	else if(y[n-1]>=y[0] && y[n-1]<y[n-2]) {
			double m = (x[i]-x[i-1])/(y[i]-y[i-1]);
			bucket[y[i]-mm.min].insert(x[i],y[i-1],m);
	}
	cout<<"buckets - ";
	for(i=0;i<mm.max-mm.min;i++) {
		if(bucket[i].first!=NULL) {
			cout<<i+mm.min<<" . ";
			bucket[i].display();
			cout<<endl;
		}
	}
	getch();
	int k=0;
	while(k!=(mm.max-mm.min)) {
		if(bucket[k].first != NULL) {
			node *p = bucket[k].first;
			while(p!=NULL) {
				AEL.insert(p->x , p->y_max , p->inc_x);
				p=p->next;
			}
		}
		if(AEL.first!=NULL) {
			AEL.remove(k+mm.min);	//removes all the nodes from AEL where y_max == k
		}
		node *q = AEL.first , *r = q->next;
		while(q!=NULL) {
			line(ceil(q->x),k+mm.min, floor(r->x),k+mm.min);
			q->x = q->x + q->inc_x;
			r->x = r->x + r->inc_x;
			q=r->next;
			if(q!=NULL) {
				if(q->next == NULL) {
					break;
					cout<<"error";
				}
				else
					r = q->next;
			}

		}
		k++;
	}


}
