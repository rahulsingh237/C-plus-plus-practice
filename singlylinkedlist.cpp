#include<bits/stdc++.h>
using namespace std;

class n
{	
	public:
		int data;
		n* next;
		n(int x)
		{
			data=x;
		}
		
};

class linked
{
	
}

int main()
{
	n* head =NULL;
	n* s=NULL;
	n* t=NULL;
	
	head = new n(1);
	s = new n(2);
	t = new n(3);
	
	head->data=1;
	head->next = s;
	
	//s->data=2;
	s->next=t;
	
	//t->data=3;
	t->next=NULL;
	
	do
	{
		cout<<head->data;
		head=head->next;
	}while(head!=NULL);	
	return 0;
}
