#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int maxRow = 10;
string studentId[maxRow] = {} ;
string studentName[maxRow] = {};
string studentGrade[maxRow]  = {};

void addStudent()
{

    char id[10];
    char name[50];
    char grade[10];
    cout<<endl;
    cin.ignore();
    cout<<"Enter student id: ";
    cin.getline(id,10);
    cout<<"Enter student name: ";
    cin.getline(name,50);
    cout<<"Enter student grade: ";
    cin.getline(grade,10);

    for (int i = 0; i < maxRow; i++)
    {
        if (studentId[i] == "\0")
        {
            studentId[i] = id;
            studentName[i] = name;
            studentGrade[i] = grade;
            cout<<"Student added successfully!"<<endl;
            break;
        }
    }
}



void viewStudent(){
    cout<<endl;
    cout<<"Student ID | "<<setw(10)<<"Student Name | "<<setw(10)<<"Student Grade"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    for (int i = 0; i < maxRow; i++)
    {
        if (studentId[i] != "\0")
        {
            cout<<studentId[i]<<setw(10)<<studentName[i]<<setw(10)<<studentGrade[i]<<endl;
        }
    }
}
void updateStudent(){
    char id[10];
    char name[50];
    char grade[10];
    cout<<endl;
    cin.ignore();
    cout<<"Enter student id to update: ";
    cin.getline(id,10);
    cout<<"Enter student new name: ";
    cin.getline(name,50);
    cout<<"Enter student new grade: ";
    cin.getline(grade,10);
    for (int i = 0; i < maxRow; i++)
    {
        if (studentId[i] == id)
        {
            studentId[i] = id;
            studentName[i] = name;
            studentGrade[i] = grade;
            cout<<"Student updated successfully!"<<endl;
            break;
        }
    }
}
void deleteStudent(){
    char id[10];
    cout<<endl;
    cin.ignore();
    cout<<"Enter student id to delete: ";
    cin.getline(id,10);
    for (int i = 0; i < maxRow; i++)
    {
        if (studentId[i] == id)
        {
            studentId[i] = "\0";
            studentName[i] = "\0";
            studentGrade[i] = "\0";
            cout<<"Student deleted successfully!"<<endl;
            break;
        }
    }
}
void searchStudent(){
    char id[10];
    cout<<endl;
    cin.ignore();
    cout<<"Enter student id to search: ";
    cin.getline(id,10);
    for (int i = 0; i < maxRow; i++)
    {
        if (studentId[i] == id)
        {
            cout<<"Student found!"<<endl;
            cout<<"Student ID | "<<setw(10)<<"Student Name | "<<setw(10)<<"Student Grade"<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            cout<<studentId[i]<<setw(10)<<studentName[i]<<setw(10)<<studentGrade[i]<<endl;
            break;
        }
    }
}

//function to open file
void openFile(){
    ifstream file;
    file.open("student.txt");
    if(file.is_open()){
        cout<<"File is open"<<endl;
    }
    else{
        cout<<"File is not open"<<endl;
    }
}

//function to save and close file
void saveFile(){
    ofstream file;
    file.open("student.txt");
    if(file.is_open()){
        for (int i = 0; i < maxRow; i++)
        {
            if (studentId[i] != "\0")
            {
                file<<studentId[i]<<" "<<studentName[i]<<" "<<studentGrade[i]<<endl;
            }
        }
        file.close();
        cout<<"File saved successfully!"<<endl;
    }
    else{
        cout<<"File is not open"<<endl;
    }
}
int main(){

    int option;
   

do{
    openFile();
    cout<<"MENU"<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. View Student"<<endl;
    cout<<"3. Update Student"<<endl;
    cout<<"4. Delete Student"<<endl;
    cout<<"5. Search Student"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"---------------------------"<<endl;

    cout<<"Enter your option: ";
    cin>>option;

    switch(option){
        case 1:
            addStudent();
            break;
        case 2:
            viewStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            searchStudent();
            break;
        case 6:
            saveFile();
            cout<<"Exiting and saving ..."<<endl;
            break;
        default:
            cout<<"Invalid option"<<endl;
            break;
    }
    
}while(option != 6);

    return 0;
}