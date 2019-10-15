#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readpointer(string data ,long pos = 0) {
    fstream file;
    file.open("test.txt",ios::in );
    if(!file){
        cout<<"Error in opening file..";
        return;
    }
    cout << "\nFile's Data\n";
    file.seekp(pos , ios::beg);
    cout << "\nCurrent Pointer\t:\t " << file.tellp();
    cout << endl << data ;
    /*
     for printing whole file
    while ( getline (file , data) ) {
        cout << "\nCurrent Pointer\t:\t " << file.tellp();
    }
    */
    file.close();
    cout << endl;
}
void writepointer(string data) {
    fstream file;
    file.open("test.txt",ios::out | ios::app);
    if(!file)
    {
        cout<<"Error in creating file.."<<endl;
        return;
    }
    //read values from kb
    cout<<"Enter data\t:\t";
    getline(cin,data);
    //write into file
    long pos = file.tellg();
    cout<<"Current position is: "<< file.tellp() << endl;
    file << data << endl;
    //print the position
    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;
    readpointer(data , pos);
}
int main()
{
    string data;
    writepointer(data);
    return 0;
}
