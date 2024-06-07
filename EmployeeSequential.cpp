// Company maintains employee information as 
// employee ID, name, designation and salary. Allow 
// user to add, delete information of employee. Display 
// information of particular employee. If employee does 
// not exist an appropriate message is displayed. If it is, 
// then the system displays the employee details. Use 
// index sequential file to maintain the data.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee
{
	int id;
	string name;
	string design;
	float sal;
};

void addemp()
{
	ofstream file("employees23.txt",ios::app);
	Employee emp;
	cout<<"Enter employee id: ";
	cin>>emp.id;
	cout<<"Enter employee name: ";
	cin>>emp.name;
	cout<<"Enter employee deignation: ";
	cin>>emp.design;
	cout<<"Enter employee salary: ";
	cin>>emp.sal;
	file<<emp.id<<" "<<emp.name<<" "<<emp.design<<" "<<emp.sal<<endl;
	file.close();
}

void displayemp()
{
	ifstream file("employees23.txt");
	int ids;
	cout<<"Enter id to be searched: ";
	cin>>ids;
	bool found = false;
	Employee emp;
	while(file>>emp.id>>emp.name>>emp.design>>emp.sal)
	{
		if(emp.id == ids)
		{
			found = true;
			cout<<"Details are\n";
			cout<<"Id: "<<emp.id<<"\n";
			cout<<"Name: "<<emp.name<<"\n";
			cout<<"Designation: "<<emp.design<<"\n";
			cout<<"Salary: "<<emp.sal<<"\n";
		}
	}
	file.close();
	if(!found)
	{
		cout<<"Employee not found!!\n";
	}
}

void delemp()
{
	ifstream file("employees23.txt");
	ofstream filenew("employeestest.txt",ios::app);
	int idd;
	cout<<"Enter id to be deleted: ";
	cin>>idd;
	Employee emp;
	bool dele = false;
	while(file>>emp.id>>emp.name>>emp.design>>emp.sal)
	{
		if(emp.id!=idd)
		{
			filenew<<emp.id<<" "<<emp.name<<" "<<emp.design<<" "<<emp.sal<<endl;
		}
		else
		{
			dele = true;
		}
	}
	
	file.close();
	filenew.close();
	remove("employees23.txt");
	rename("employeestest.txt","employees23.txt");
	if(dele)
	{
		cout<<"Employee record deleted\n";
	}
	else
	{
		cout<<"Employee not found\n";
	}
}

int main()
{
	int ch;
	
	do
	{
		cout<<"1. Add employee\n";
		cout<<"2. Delete employee\n";
		cout<<"3. Display employee\n";
		cout<<"4. Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				addemp();
				break;
				
			case 2:
				delemp();
				break;
				
			case 3:
				displayemp();
				break;
				
			case 4:
				exit(0);
		}
	}
	while(ch!=4);
	return 0;
}
