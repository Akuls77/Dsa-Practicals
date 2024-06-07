// Convert given binary tree into threaded binary 
// tree. Analyze time and space complexity of the 
// algorithm.

#include <iostream>
using namespace std;

class BTT
{
	private:
		struct node
		{
			int data;
			node *lc;    //* means lc is pointer to node and -> means we can access members of node
			node *rc;
			int lf;
			int rf;
		}*root, *header;
		
	public:
		BTT()
		{
			root = NULL;
			header = NULL;
		}
	
	void create();
	void preorder();
};

void BTT :: create()
{
	node *temp, *curr;
	int ans;
	
	header = new node;
	header->lc = header;
	header->rc = header;
	
	do
	{
		temp = new node;
		cout<<"Enter data: ";
		cin>>temp->data;
		temp->lf = 0;
		temp->rf = 0;
		
		if(root == NULL)
		{
			root = temp;
			header->lc = root;
			root->lc = header;
			root->rc = header;
		}
		
		else
		{
			curr = root;
			while(1)
			{
				if(temp->data < curr->data)
				{
					if(curr->lf == 0)
					{
						temp->lc = curr->lc;
						temp->rc = curr;
						curr->lc = temp;
						curr->lf = 1;
						break;
					}
					else
					{
						curr = curr->lc;
					}
				}
				
				if(temp->data > curr->data)
				{
					if(curr->rf == 0)
					{
						temp->rc = curr->rc;
						temp->lc = curr;
						curr->rc = temp;
						curr->rf = 1;
						break;
					}
					else
					{
						curr = curr->rc;
					}
				}
			}
		}
		cout<<"Do u want to insert one more node(1/0): ";
		cin>>ans;
	}
	while(ans==1);
}

void  BTT :: preorder()
{
	node *t = new node;
	if(root==NULL)
	{
		cout<<"BTT is empty.";
	}
	else
	{
		t=root;
		while(t!=header)
		{
			cout<<t->data<<"   ";
			if(t->lf==1)
			{
				t=t->lc;
			}
			else
			{
				while(t->rf==0)
				{
					t=t->rc;
					if(t==header)
					{
						break;
					}
				}
				t=t->rc;
			}
		}
	}
}

int main()
{
	BTT a;
	int ch;
	while(true)
	{
		cout<<"\n1. Create Binary Threaded Tree\n";
		cout<<"2. Display BTT in preorder traversal\n";
		cout<<"3. Exit\n\n";
		cout<<"Enter choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				a.create();
				break;
			case 2:
				cout<<"Preorder traversal is: ";
				a.preorder();
				break;
			case 3:
				exit(0);
				
			default:
				cout<<"Invalid choice.";
		}
	}
	return 0;
}
