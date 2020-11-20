#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{ 
	if(a==0)
	{
		return b;
	}
	else if(b=0)
	{
		return a;
	}
	else
	{
		return gcd(a%b,b);
	}
}

int lcm(int a, int b)
{	int temp;
	temp=(a/gcd(a,b))*b;
	return(temp);
}
int main()
{ 	
	int a,b,x;
	cin >> a >> b ;
	x=lcm(a,b);
	cout<<x;
	return 0;
}
