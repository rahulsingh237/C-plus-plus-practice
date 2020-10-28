#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3]={10000,7000,6000};
	int x,y,z;
	float d;
	
	cin>>x;
	cin>>y;
	
	if(x==1 || x==2 || x==3)
	{
	if(y==1)
	{
		cin>>z;
		if(z==1)
		{
			d=a[x-1]-(0.2*a[x-1]);
			cout<<d<<" INR";
		}
		else if(z==2)
		{
			d=a[x-1]-(0.02*a[x-1]);
			cout<<d<<" INR";
		}
	}
	else
	{
		cout<<"INVALID INPUT";
	}
	}
	else
	{
		cout<<"INVALID INPUT";
	}
}
