// Read the marks obtained by students of second year 
// in an online examination of particular subject. Find 
// out maximum and minimum marks obtained in that 
// subject. Use heap data structure. Analyze the 
// algorithm.

#include <iostream>
using namespace std;

void minheap(int arr[], int i)
{
	int parent = (i-1)/2;
	int curr = i;
	while(parent>=0 && arr[parent] > arr[curr])
	{
		swap(arr[parent], arr[curr]);
		curr = parent;
		parent = (curr-1)/2;
	}
}

void maxheap(int arr[], int i)
{
	int parent = (i-1)/2;
	int curr = i;
	while(parent>=0 && arr[parent] < arr[curr])
	{
		swap(arr[parent], arr[curr]);
		curr = parent;
		parent = (curr-1)/2;
	}
}

void accept()
{
	int n, ch;
	int a[20];
	cout<<"\nEnter the number of students: ";
	cin>>n;
	cout<<"Enter the marks of students: ";
	for (int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	do
	{
		cout<<"\n1. Create Minheap\n";
		cout<<"2. Create Maxheap\n";
		cout<<"3. Exit\n\n";
		cout<<"Enter choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				for(int i=1; i<n; i++)
				{
					minheap(a,i);
				}
				cout<<"Minheap after inserting is: ";
				for(int i=0; i<n; i++)
				{
					cout<<a[i]<<" ";
				}
				cout<<"\nMinimum marks of student is: "<<a[0]<<"\n";
				break;
				
			case 2:
				for(int i=1; i<n; i++)
				{
					maxheap(a,i);
				}
				cout<<"Maxheap after inserting is: ";
				for(int i=0; i<n; i++)
				{
					cout<<a[i]<<" ";
				}
				cout<<"\nMaximum marks of student is: "<<a[0]<<"\n";
				break;
				
			case 3:
				exit(0);
		}
	}
	while(ch!=3);
}


int main()
{
	accept();
	return 0;
}
