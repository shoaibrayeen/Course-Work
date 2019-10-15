//
//  object_read_write.cpp
//  Project-DS
//
//  Created by Mohd Shoaib Rayeen on 17/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//class student to read and write student details
class temp {
private:
    string data;
public:
    void getData() {
        cout<<"Enter data\t:\t";
        getline(cin,data);
    }
    
    void showData() {
        cout << "\nData\t:\t" << data <<endl;
    }
};

int main()
{
    temp obj;
    
    fstream file;
    
    //open file in write mode
    file.open("test.txt",ios::out | ios::app);
    if(!file)
    {
        cout<<"Error in creating file.."<<endl;
        return 0;
    }
    
    //write into file
    obj.getData();    //read from user
    long pos = file.tellp();
    file.write((char*)&obj,sizeof(obj));    //write into file
    
    file.close();   //close the file
    cout<<"\nFile saved and closed succesfully."<<endl;
    
    //re open file in input mode and read data
    //open file1
    //again open file in read mode
    file.open("test.txt",ios::in);
    if(!file){
        cout<<"Error in opening file..";
        return 0;
    }
    //read data from file
    file.seekp(pos , ios::beg);
    
    file.read((char*)&obj,sizeof(obj));
    
    //display data on monitor
    obj.showData();
    //close the file
    file.close();
    
    return 0;
}
