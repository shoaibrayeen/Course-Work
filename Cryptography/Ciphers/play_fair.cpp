#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char word[20],key[26],code[30];
int n=0,i=0,x=1;
int a=0;
char table[5][5],ptext[50],ctext[50],newPT[50],Dres[50];
void GenKey()
{
	for(int i=0;i<strlen(word);i++)
	{
		if(word[i]=='j')
		   word[i]='i';
	}
	for(int i=0;word[i]!='\0';i++)
	{
		for(int j=i+1;word[j]!='\0';j++)
		{
			if(word[j]==word[i])
		   	{
		   		word[j]=' ';
		   	}
	    	}
	}
	for(int i=0;word[i]!='\0';i++)
	{
		if(word[i]!=' ')
			key[n++]=word[i];
	}
	key[n]='\0';
	n=0;
	for(i=0;key[i]!='\0';i++)
	{
		code[n++]=key[i];
	}
	for(char j='a';j<='z';j++)
	{
		for(int k=0;key[k]!='\0';k++)
		{
			if(key[k]==j || j=='j')
			{
				x=0;
				break;
			}
			else
				x=1;
		}
		if(x==1)
		code[n++]=j;
	}
	code[n]='\0';
}

int main()
{
		int a=0;
		char table[5][5],ptext[50],ctext[50],newPT[50];
		cout<<"\nEnter the key\t:\t";
	    gets(word);
	    GenKey();  
	    for(int i=0;i<5;i++)
	    {
	    	for(int j=0;j<5;j++)
	    	{
	    		table[i][j]=code[a++];
	    	}
	    }
	    cout<<"\nThe playfair table is(by taking i=j)\n";
            for(int i=0;i<5;i++)
	    {
	    	for(int j=0;j<5;j++)
	    	{
	    		cout<<table[i][j]<<"\t";
	    	}
	    	cout<<"\n";
	    }
	    cout<<"\nEnter the Plain Text\t:\t";
	    gets(ptext);
	    cout<<"\nPlain Text in Biwords Form\t:\t";
	    a=0;
	    int n=0;
	    for(int i=0;i<strlen(ptext);i++)
	    {
	    	if(ptext[i]!=' ')
	    	{
	    		newPT[a++]=ptext[i];
	    		n++;
	    	    if(n%2==0)
	    	       newPT[a++]=' ';
	    	}
	    }
	    if(n%2!=0)
	      newPT[a++]='x';
	    newPT[a]='\0';
	    for(int i=0;i<strlen(newPT);i=i+3)
	    {
	    		if(newPT[i]==newPT[i+1])
	    		{
	    			newPT[i+1]='x';
	    		}
	    		else if(newPT[i+1]==' ')
	    		    newPT[i+1]='x';
	    }
	    cout<<endl;
            puts(newPT);
	cout<<endl;
        int i;
        int X1,X2,Y1,Y2;
        for(i=0;i<strlen(newPT);i=i+3)
        {
        	   for(int x=0;x<5;x++)
	           {          
		          for(int y=0;y<5;y++)
		          {
			         if(table[x][y]==newPT[i])
			         {
			             X1=x;Y1=y;
			         }
			         if(table[x][y]==newPT[i+1])
			         {
					     X2=x;Y2=y;
					 }
		          }
	           }
        	if(Y1==Y2)
        	{
        	    ctext[i]=table[(X1+1)%5][Y1];
        	    ctext[i+1]=table[(X2+1)%5][Y1];
        	    ctext[i+2]=' ';
        	    
        	}
        	else if(X1==X2)
        	{
        	    ctext[i]=table[X1][(Y1+1)%5];
        	    ctext[i+1]=table[X2][(Y2+1)%5];
        	    ctext[i+2]=' ';
        	    
        	} 
        	else
        	{
        		ctext[i]=table[X1][Y2];
        		ctext[i+1]=table[X2][Y1];
        		ctext[i+2]=' ';
        	}
        }
	cout<<"\nEncrypted code in Biwords form\t:\t";
        ctext[i-1]='\0';
        puts(ctext);
        cout<<"\n\nThe Encrypted code is\t:\t";
        int cnt=0;
        for(int i=0;i<strlen(ctext);i++)
        {
        	if(ctext[i]!=' ')
        	{
        	   cout<<char(ctext[i]-32);
        	   cnt++;
            }
            if(cnt%5==0)
               cout<<" ";
        }
        for(i=0;i<strlen(ctext);i=i+3)
        {
        	   for(int x=0;x<5;x++)
	           {          
		          for(int y=0;y<5;y++)
		          {
			         if(table[x][y]==ctext[i])
			         {
			             X1=x;Y1=y;
			         }
			         if(table[x][y]==ctext[i+1])
			         {
					     X2=x;Y2=y;
					 }
		          }
	           }
        	if(Y1==Y2)
        	{
        	    Dres[i]=table[(X1+4)%5][Y1];
        	    Dres[i+1]=table[(X2+4)%5][Y1];
        	    Dres[i+2]=' ';
        	    
        	}
        	else if(X1==X2)
        	{
        	    Dres[i]=table[X1][(Y1+4)%5];
        	    Dres[i+1]=table[X2][(Y2+4)%5];
        	    Dres[i+2]=' ';
        	    
        	} 
        	else
        	{
        		Dres[i]=table[X1][Y2];
        		Dres[i+1]=table[X2][Y1];
        		Dres[i+2]=' ';
        	}
        }
        Dres[i-1]='\0';
        for(int q=0;q<i;q++)
        {
        	if(Dres[q]=='x')
        	{
        		if(Dres[q+1]=='\0')
        		   Dres[q]='\0';
        		else 
        		   Dres[q]=Dres[q-1];
        	}
        }
	cout<<endl;
	cout<<"\nDecrypted Code in Biwords form\t:\t";
        puts(Dres);
        
        cout<<"\n\nThe Decrypted code is\t:\t";
        cnt=0;
        for(int i=0;i<strlen(Dres);i++)
        {
        	if(Dres[i]!=' ')
        	{
        	   cout<<char(Dres[i]-32);
        	   cnt++;
            }
            if(cnt%5==0)
               cout<<" ";
        }
        cout<<endl;
        return 0;
}
