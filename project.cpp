#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

// ------------- University Management System -------------

class University
{
    private:
        string rollNum, name, subject,  address;
    public:
        University():rollNum(""), name(""), address(""){}
        // ----- Setters (Mutators) ------
        void setRollNum(string roll)
        {
            rollNum = roll;
        }
        void setName(string n)
        {
            name = n;
        }
        void setSubject(string sub)
        {
            subject = sub;
        }
        void setAddress(string add)
        {
            address = add;
        }
        // ----- Getters (Accessors) ------
        string getRollNum()
        {
            return rollNum;
        }
        string getName()
        {
            return name;
        }
        string getSubject()
        {
            return subject;
        }
        string getAddress()
        {
            return address;
        }

};
//----- Function to Add New Student ------
void addStudent(University student)
{
    string rollNum, name, subject, address;
    cout << "Enter Student Roll Number: ";
    cin >> rollNum;
    student.setRollNum(rollNum);

    cout << "Enter Student Name: ";
    cin >> name;
    student.setName(name);

    cout << "Enter Student Subject: ";
    cin  >> subject;
    student.setSubject(subject); // How to make this subject in sturct ?

    cout << "Enter Student Address: ";
    cin >> address;
    student.setAddress(address);

    // Write information in file
    ofstream outFile("test.txt", ios::app);
    
    if(!outFile.is_open())
    {
        cout << "Error in Opening File\n";
    }else{
        outFile << "Student Roll Num is: " << student.getRollNum() << endl;
        outFile << "Student Name is: " << student.getName() << endl;
        outFile << "Student Subjectis: " << student.getSubject() << endl;
        outFile << "Student Address is: " << student.getAddress() << endl;
        outFile << "--------------------\n";
    }

    
    outFile.close();
    cout << "Student Added Successfully..\n";

}
//------ Function to Search On a Student -------
void searchOnStudent()
{
    string rollNum;
    cout << "Enter Student RollNum to Search: ";
    cin >> rollNum;

    // Read roll number from the file & compare between user input

    ifstream inFile("test.txt");
    if( !inFile.is_open() )
    {
        cout <<"Error, File Can't Open!\n";
    }
    string line;
    bool found = false;
    while(getline(inFile, line))
    {
        int data = line.find(rollNum);
        if(data != string::npos)
        {
            cout << line << endl; 
            found = true;
        }
        if(!found)
        {
            cout << "Student Not Found\n";
        }
    }
    inFile.close();
    Sleep(3000);
}
//------ Function Update a Student -------

void updateStudent(University student)
{
    string rollNum;
    cout << "Enter RollNUm of Student: ";
    cin >> rollNum;

    ifstream infile("test.txt");
    ofstream outfile("simple.txt");

    if(!infile.is_open() || !outfile.is_open())
    {
        cout << "Error in Opening File\n";
    }
    string line;
    bool found = 0;
    while (getline(infile, line))
    {
        int pos = line.find(rollNum);
        if(pos != string::npos){
            string address;
            cout << "Enter New Address: ";
            cin >> address;
            student.setAddress(address);

            int newPos = line.find_last_of(':');
            line.replace(newPos + 2, string::npos, student.getAddress()); 
        }
        outfile << line << endl;
        found = true;
    }
    if (!found)
    {
        cout << "Student Not Found!";
    }
    outfile.close();
    infile.close(); 
    cout << "Student Updated Successfuly.\n";
}



int main()
{
    University student;
    
    bool exit = false;
    while(!exit) // !exit == true
    {
        system("cls");
        system("color 3f");
        int val;
        cout << "Welcome to University Management System\n";
        cout << "--------------------------------\n";
        cout << "1- Add New Student\n";
        cout << "2- Search on Student\n";
        cout << "3- Update Data of Student\n";
        cout << "4- Exit\n";
        cout << "Enter Your Choice...";
        cin >> val;

        if (val == 1)
        {
            system("cls");
            addStudent(student);
            Sleep(3000);
        }else if(val == 2)
        {
            system("cls");
            searchOnStudent();
            Sleep(3000);
        }else if(val == 3)
        {
            system("cls");
            updateStudent(student);
            Sleep(3000);
        }else if(val == 4)
        {
            system("cls");
            exit = true;
            cout << "Good Luck\n";
            Sleep(3000);
        }
    }
    return 0;
}
