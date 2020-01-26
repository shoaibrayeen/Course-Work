//to read a file
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	clrscr();
	char ch;
	ifstream fin;
	char filename[50];
	cout << "\nEnter Filename\t:\t";
	cin >> filename;
	char str[100];
	strcpy(str, "./shoaib/");
	strcat(str,filename);
	fin.open( str);

	ofstream fout;
	fout.open("./shoaib/marks.txt");
	if(!fin)
	{
		cout<<"\ncannot open file "<<endl;
		getch();
		return 0;
	}
	while(fin)
	{
		 fin.get(ch);
		 fout.put(ch);
		 if ( ch == '\n' )
		 {
			cout<<endl;
		 }
		 else
		 {
			cout<<ch;
		 }
	}
	fin.close();
	fout.close();
	getch();
	cout<< "\n";
	return 0;
}
