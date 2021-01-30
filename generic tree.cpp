#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        vector<node*> children;
};

void display(node* n)
{
    cout<<"["<<n->data<<"] - ";
    for(node* child: n->children)
    {
        cout<<child->data<<" ";
    }
    
    for(node* child:n->children)
    {
        cout<<endl;
        display(child);
    }
}

int sizeTree(node* n)
{
	int s=0;
	for(node* child:n->children)
	{
		int cs=sizeTree(child);
		s=s+cs;
	}
	s=s+1;
	return s;
}

int maxTree(node* n)
{
	int m=INT_MIN;
	for(node* child:n->children)
	{
		int cm=maxTree(child);
		m=max(m,cm);
	}
	m=max(m,n->data);
	
	return m;
}

int heightTree(node* n) //in terms of edges therefore height will be initialised with -1. If it is asked in terms of nodes then initialise height with 0.
{
	int ht=-1;
	for(node* child:n->children)
	{
		int cm=heightTree(child);
		ht=max(ht,cm);
	}
	ht+=1;
	
	return ht;
}

void traversal(node* n)
{
	//area 1 - before going deep into recursion - responsible for preorder
	
	cout<<"Node Pre "<<n->data<<endl;
	for(node* child:n->children){
		
		cout<<"Edge Pre "<<n->data<<"--"<<child->data<<endl; //edge pre order
		traversal(child);
		cout<<"Edge Post "<<n->data<<"--"<<child->data<<endl;//edge post order
	}
	
	//area 2 - coming out of recursion - responsible for post order
	
	cout<<"Node Post "<<n->data<<endl;
}

/*void levelorder(node* n)
{
	deque<node*> q;
	q.push_back(n);
	while(!q.empty())
	{
		q.pop_back();
		cout<<n->data<<"  ";
		for(node* child:n->children){
			q.push_back(child);
		}	
			
	}
	cout<<".";
}*/

int main() {

    int arr[]={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
     int n=sizeof(arr)/sizeof(arr[0]);
    stack<node*> st;
    node* root=nullptr;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1) st.pop();
        else{
            node* t= new node();
            
            t->data=arr[i];
            if(st.size()==0)
            {
                root=t;
            }
            else
            {
                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }
    display(root);
    int k=sizeTree(root);
    cout<<"\n\nTree Size:"<<k;
    
    int q=maxTree(root);
    cout<<"\n\nMaximum Element:"<<q;
    
    int w=heightTree(root);
    cout<<"\n\nHeight of tree(in terms of edges):"<<w<<endl<<endl;    
    
    cout<<"traversal : "<<endl;
    traversal(root);
    
    //cout<<"\n\nLevel order traversal\n";
    //levelorder(root);
    
    return 0;
}
