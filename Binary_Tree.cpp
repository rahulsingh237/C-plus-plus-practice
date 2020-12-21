#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
class binary
{
	public:
		node *root;
		binary()
		{
			root=NULL;
		}
		void addroot(int num)
		{
			node *temp=new node;
			temp->data=num;
			temp->left=NULL;
			temp->right=NULL;
			root=temp;
		}
		void addnode(int num)
		{
			if(root==NULL)
			{
				addroot(num);
			}
			else{
			
			node*temp=new node;
			temp->data=num;
			temp->left=NULL;
			temp->right=NULL;
			node *parent;
			node *ptr;
			ptr=root;
			while(ptr!=NULL)
			{	
				parent=ptr;
				if(num>ptr->data)
				{
					ptr=ptr->right;
				}
				else{
					ptr=ptr->left;
				}
			}
			if(num>parent->data)
			{
				parent->right=temp;
			}
			else
			{
				parent->left=temp;
			}
			}
		}
	
		void display()
		{
			print(root);
		}
		void print(node*ptr)
		{
			if(ptr!=NULL)
			{
				print(ptr->left);
				cout<<ptr->data<<" ";
				print(ptr->right);
			}
		}
		
};
int main()
{
	binary b;
	int n,dat;
	cout<<"\nEnter the number of nodes you want to add in the tree\n";
	cin>>n;
	cout<<"\nEnter the nodes\n";
	for(int i=0;i<n;i++)
	{
		cin>>dat;
		b.addnode(dat);
	}
	b.display();
	return 0;
}
