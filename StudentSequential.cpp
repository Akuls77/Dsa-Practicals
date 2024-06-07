// Department maintains a student information. 
// The file contains roll number, name, division 
// and address. Allow user to add, delete 
// information of student. Display information of 
// particular employee. If record of student does 
// not exist an appropriate message is displayed. If 
// it is, then the system displays the student 
// details. Use sequential file to maintain the data.

#include<iostream>
#include<fstream>
using namespace std;

class Student{
    struct st{
        int rollno;
        char name[10];
    }s;
    public:
    void create();
    void display();
    void search();
    void modify();
    void deleterecord();
};

void Student::create(){
    int ans;
    ofstream out;
    out.open("student.txt",ios::app|ios::binary);
    do{
    cout<<"Enter name of student : ";
    cin>>s.name;
    cout<<"Enter roll number of student : ";
    cin>>s.rollno;
    out.write((char*)&s,sizeof(s));

    cout<<"Do you want to enter more record ? ";
    cin>>ans;
    }while(ans==1);
    out.close();
}

void Student::display(){
    ifstream in;
    in.open("student.txt",ios::in|ios::binary);
    while(in.read((char*)&s,sizeof(s))){
        cout<<s.rollno<<"\t"<<s.name<<"\t";
    }
    in.close();
}

void Student::search(){
    ifstream in;
    in.open("student.txt",ios::in|ios::binary);
    int key;
    cout<<"Enter the rollno of the student to be searched : ";
    cin>>key;
    int flag=0;
    while(in.read((char*)&s,sizeof(s))){
        if(s.rollno==key){
            cout<<"Record is present ";
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Record not present ";

    }
}

int main(){
    Student stud;
    int ch;
    do{
        cout<<"\n --------------Student Database----------";
        cout<<"\n1.Add student";
        cout<<"\n2.Display Details ";
        cout<<"\n3.Search";
        cout<<"\n4.Exit";
        cout<<"\nEnter choice : ";
        cin>>ch;

    switch(ch){
        case 1:
        stud.create();
        cout<<"\nRecord created successfully ";
        break;

        case 2:
        cout<<"\nRecords are : ";
        stud.display();
        break;
        case 3:
        stud.search();
        break;
        case 4:
        exit(0);
    }
    }while(ch!=4);
    return 0;
}