//to apply concepts of file handling
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
void count(char* str)
{

	ifstream fin;
	fin.open( str);
	if(!fin)
	{
	   cout<<"\nCannot open file\n";
	   getch();
	   return 0;

	int count_upper=0;
	int count_digit=0;
	int count_words=0;
	int count_lines=0;
	char ch;
	while(fin)
	{
		fin.get(ch);

		if(ch == '\n')
		{
			count_lines++;
			count_words++;
		}
		else if( ch >= 'A'&& ch <= 'Z' )
		{
			// count_char++;
			count_upper++;
		}
		else if(ch >= '0' && ch <= '9')
		{
		       //	count_char++;
			count_digit++;
		}
		else if(ch == ' ')
		{

			count_words++;

		}

	}
	count_lines++;
	count_words++;
	cout 	<< count_upper << "\t"
		<< count_digit << "\t"
		<< count_words << "\t"
		<< count_lines << "\n";
       fin.close();

}
void count_chars(char* str)
{
	ifstream fin;
	fin.open( str);
	if(!fin)
	{
	   cout<<"\nCannot open file\n";
	   getch();
	   return 0;

 int count_char=0;
 char ch;
 while(fin)
	{
		fin.get(ch);
		if( ch != '\n' )
		{
			count_char++;

		}

	}
	cout<<count_char<<endl;
	fin.close();
}
int main()
{
	clrscr();
	char filename[50];
	cout << "\nEnter Filename\t:\t";
	cin >> filename;
	char str[100];
	strcpy(str, "./shoaib/");
	strcat(str,filename);
	}
	count(str);
	//fin.close();
	//fin.open(str);
       //	fin.seekg(1,ios::beg);
	count_chars(str);
       //	fin.close();

	getch();

	cout<< "\n";
	return 0;
}
