//to input read and create a file
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	ifstream fin;
	clrscr();
	char filename[20];
	cout<<"\nEnter the filename\t:\t ";
	cin>>filename;
	char str[100];
	strcpy(str,"./shoaib/");
	strcat(str,filename);
	fin.open(str);
	if(!fin)
	{
		cout<<"\nCannot open file\n ";
		getch();
		return;
	}
	ofstream fout;
	fout.open("./shoaib/copy.txt");
	if(!fout)
	{
		cout << "\nError in File Creation\n";
		getch();
		return;
	}
	char ch;
	char temp[20];
	int i = 0;
	while(fin)
	{
		fin.get(ch);
		if( ch == '\n' || ch == ' ' )
		{
			str[i] = '\0';
			if( str[i-1] == 'a' || str[i-1] == 'e' || str[i-1] == 'i' || str[i-1] == 'o' || str[i-1] == 'u' )
			{
			}
			else
			{
				fout.put(ch);
				for( int k = 0; str[k] != '\0'; k++ )
				{
					fout.put(str[k]);
				}
			}
			i = 0;
			str[i] = '\0';
		}
		else
		{
			str[i] = ch;
			i++;
		}
	}
	fout.close();
	fin.close();
	fin.open("./shoaib/copy.txt");
	while(fin)
	{
		fin.get(ch);
		cout << ch;
	}
	getch();

}
