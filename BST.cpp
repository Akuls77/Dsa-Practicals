// Beginning with an empty binary search tree, 
// Construct binary search tree by inserting the 
// values in the order given. After constructing a 
// binary tree -
// i. Insert new node, ii. Find number of nodes in 
// longest path from root, iii. Minimum data 
// value found in the tree, iv. Change a tree so 
// that the roles of the left and right pointers are 
// swapped at every node, v. Search a value

#include <iostream>
using namespace std;

class BST
{
	private:
		struct node
		{
			int data;
			node *lc;
			node *rc;
		}*root;
		
	public:
		BST()
		{
			root = NULL;
		}
		
	void create();
	void display();
	void preorder(node *t);
	void search();
};

void BST :: create()
{
	node *temp, *curr;
	int ans;
	
	do
	{
		temp = new node;
		cout<<"Enter data: ";
		cin>>temp->data;
		temp->lc = NULL;
		temp->rc = NULL;
		
		if(root == NULL)
		{
			root = temp;
		}
		else
		{
			curr = root;
			while(1)
			{
				if(temp->data < curr->data)
				{
					if(curr->lc == NULL)
					{
						curr->lc = temp;
						break;
					}
					else
					{
						curr = curr->lc;
					}
				}
				
				else if(temp->data > curr->data)
				{
					if(curr->rc == NULL)
					{
						curr->rc = temp;
						break;
					}
					else
					{
						curr = curr->rc;
					}
				}
			}
		}
		cout<<"Do u want to insert more node(1/0): ";
		cin>>ans;
	}
	while(ans == 1);
}

void BST :: display()
{
	cout<<"Preorder Traversal is: ";
	preorder(root);
}

void BST :: preorder(node *t)
{
	if(t!=NULL)
	{
		cout<< t->data<<"  ";
		preorder(t->lc);
		preorder(t->rc);
	}
}

void BST :: search()
{
	node *t = root;
	int key;
	cout<<"Enter key to be searched: ";
	cin>>key;
	
	while(t!=NULL)
	{
		if(t->data == key)
		{
			cout<<"Key found\n";
			break;
		}
		else if(t->data > key)
		{
			t = t->lc;
		}
		else if(t->data < key)
		{
			t = t->rc;
		}
	}
	if(t==NULL)
	{
		cout<<"Key not found\n";
	}
}

/*void BST :: minvalue(node *t)
{
	while(t->lc!=NULL)
	{	
		t = t->lc;
	}
	cout<<"\nMinimum value is: "<<t->data;
}

void BST :: maxvalue(node *t)
{
	while(t->rc!=NULL)
	{
		t=t->rc;
	}
	cout<<"\nMaximum value is: "<<t->data;
}*/

int main()
{
		BST a;
		int ch;
		while(true)
		{
			cout<<"\n1. Insert nodes\n";
			cout<<"2. Display nodes\n";
			cout<<"3. Search node\n";
			cout<<"4. Exit\n\n";
			cout<<"Enter choice: ";
			cin>>ch;
			
			switch(ch)
			{
				case 1:
					a.create();
					break;
				case 2:
					a.display();
					break;
				case 3:
					a.search();
					break;
				case 4:
					exit(0);
				default:
					cout<<"Invalid choice.";
			}
		}
		return 0;
}
