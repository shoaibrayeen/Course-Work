#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
int *a,*b,*d,c[2]={1,1},*q,*r,size,sizea;
void Start()
{
        system("clear");
        cout<<"\t\t\t\tCyclic Redundancy Check (NOISY)\n\n";
}
void dXor(int *a,int *b,int n,int sizea)
{ 
  for(int i=0;i<size;i++)
  {
      if(a[i] == b[i])
      {
	a[i] = 0;
      }
      else
      {
	a[i] = 1;
      }
  }
 
}
void errorIntro()
{
	int error = rand()%3;
	int errortime;
	if(error == 0)
	{
	  cout<<"\nSingle Bit Error is introduced.";
	  errortime = 1;
	}
	else if(error == 1)
	{
	  cout<<"\nDouble Bit Error is introduced.";
	  
	  errortime = 2;
	}
	else if(error==2)
	{
	  cout<<"\nBurst Error is introduced.";
	  errortime = rand()%size;
	}
	for(int i=0;i<errortime;i++)
	{
	    int place = rand()%size;
	    if(a[place] == 0)
	      a[place] = 1;
	    else if(a[place] == 1)
	      a[place] =0;
	}
}
int Xor(int *a,int *b,int n,int sizea)
{       
        int cntr,m=0;
        for(cntr=0;a[cntr]==0;cntr++);
            
        cntr++;
        int k=0;
        while((cntr)<(n-sizea+1)){
                for(int i=0;i<sizea;i++)
                {
                    if(a[cntr+i]==b[i])
                        a[cntr+i]=0;
                    else if(a[cntr+i]!=b[i])
                        a[cntr+i]=1;
                }
                for(cntr=0;a[cntr]==0;cntr++);
                
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i] == 0)
                m = 0;
            else if(a[i] == 1)
	    {
	      m = 1;
	      return m;
	    }
	  
	}
	return 0;
}
void enterGP()
{
        cout<<"\nEnter the size of the Generating Polynomial.";
        cin>>sizea;
        if(sizea<2)
        {
            cout<<"\nSize of the Generating Polynomial is less than 2.";
            cout<<"\nEnter Again.";
            enterGP();
        }
        else    
        {
            a = new int [sizea];
            q = new int [sizea];
            cout<<"\nEnter Generating Polynomial :";
            for(int i=0;i<sizea;i++)
            {
                cin>>a[i];
                q[i]=a[i];
            }
            if(a[0] == 0 && a[sizea-1] == 0)
            {       
                    system("clear");
                    cout<<"\nGenerating Polynomial is not valid.";
                    enterGP();
            }
            else if(Xor(q,c,sizea,2))
            {
                    system("clear");
                    cout<<"\nGenerating Polynomial is not valid.";
                    enterGP();
            }
        }
}
void reciever()
{
  
    if(Xor(b,a,size,sizea))
    {
      cout<<"\nTransmitted Frame doesn't containes Error in it.";
    }
    else 
    { 
      cout<<"\nTransmitted Frame containes Error in it.";     
    }
}
void physicalLayer()
{
    errorIntro();
    reciever();
}
void sender()
{   
    
    enterGP();
    
      
    int tst = sizea-1;
    for(int i = sizea-1 ; i >= 0; i--)
    {
      if(a[i] == 0){
	tst = tst;
      }
      else 
      {
	tst = i;
	i = 0;
      }
    }
    int size1;
    cout<<"\nEnter the size of the frame bits :";
    cin>>size1;
    size=size1+tst;
   
    cout<<"\nEnter the frame bits :";
    b = new int [size];
    d = new int [size];
    for(int i=0;i<size1;i++){ cin>>b[i]; d[i] = b[i];}
    for(int i=size1;i<size;i++) { b[i]=0; d[i] = b[i];}
   
    if(Xor(b,a,size,sizea))
    {
      dXor(d,b,size,size);
      cout<<"\nSended Frame Bit is :";
      for(int i=0;i<size1;i++) cout<<d[i];
      cout<<endl;
      physicalLayer();
    }
    else 
    { 
      physicalLayer();
    }
}
int main()
{   
        srand(time(NULL));
        Start();
        sender();
	
        return 0;
    
}
