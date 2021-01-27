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
    return 0;
}
