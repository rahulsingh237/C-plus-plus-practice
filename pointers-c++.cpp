#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x=5;
	int y=4;
	
	int *a=&x;
	int *b=&y;
	
	cout<<*a<<endl;
	cout<<*b<<endl;
	
	cout<<"\n--------------------------------\n";
	
	*a=*a+*b;
	*b=abs(*a-*b);
	

	
	cout<<*a<<endl;
	cout<<*b<<endl;
	
	cout<<"\n--------------------------------\n";
	x=5;
	y=4;
	
	*a = x;
	*b = y;
	
	int temp=*a+*b;
	*b=abs(*a-*b);
	*a=temp;
	
	cout<<*a<<endl;
	cout<<*b<<endl;
	
	return 0;
}
