//q14 create display and add delete in file handling
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
class STUD
{
	char rno[10];
	char Name[20];
	char filename[20];
	public:
	STUD()
	{
	   strcpy(filename,"binary.dat");
	}
	void Enter()
	{
		cout<<"\nEnter roll no\t:\t ";
		cin>>rno;
		cout<<"\nEnter Name\t:\t ";
		gets(Name);
	}
	void Display()
	{
		cout<<rno<<" "<<Name<<endl;
	}
	void Create();
	void Add();
	void Delete();
	void File_disp();


};
void STUD::Create()
{
  ofstream f1;
  f1.open(filename);
  if(!f1)
  {
	cout<<"\nError in file creation\n ";
	getch();
	return;
  }
  f1.close();
}
void STUD::File_disp()
{
	ifstream I;
	I.open(filename);
	if(!I)
	{
		cout<<"\nCannot open file\n ";
		getch();
		return;
	}
	char ch[30];
	clrscr();
	cout << "\nContent in File\n";
	while(I)
	{
		I >> ch;
		cout<<ch << endl;;
	}
       I.close();
}
void STUD::Add()
{
   Enter();
   cout<<"\nEntered Data\n ";
   Display();
   ofstream O1;
   O1.open(filename,ios::app);
   O1 << rno;
   O1.put(',');
   O1 << Name;
   O1.put('\n');
   O1.close();
}
void STUD::Delete()
{
	char str[10];
	cout<<"\nEnter roll no to be deleted\n ";
	cin>>str;
	ifstream I1;
	I1.open(filename);
	fstream O;
	O.open("copy.dat", ios::out);
	if(!O)
	{
		cout << "\nError in File Creation\n";
		getch();
		return;
	}
	char ch[30];
	while(I1)
	{
		I1 >> ch;
		int k = 0;
		int flag = 0;
		for( int i = 0; ch[i] != ','; i++ )
		{
			if( ch[i] == str[k] && str[k] != '\0' )
			{
				k++;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if( str[k] != '\0' )
		{
			flag  = 1;
		}
		if( flag == 1 )          //  not matched
		{
			O << ch;
			O.put('\n');
		}
	}
	I1.close();
	O.close();
	remove(filename);
	rename("copy.dat", filename);
}
void main()
{
	STUD obj;
	int ch;
	clrscr();
	while(1)
	{
		cout<<"\n1.Create\n2.Add\n3.Delete\n4.Display\n5.Exit\n ";
		cout<<"\nEnter your choice\n ";
		cin>>ch;
		switch(ch)
		{
			case 1: obj.Create();
				break;
			case 2: obj.Add();
				break;
			case 3: obj.Delete();
				break;
			case 4: obj.File_disp();
				break;
			case 5: exit(0);
			default: cout<<"\nInvalid Choice\n ";
		}
	}


}
