#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
	if(n==0 || n==1) return 1;
	
	if(n>0) return n*fact(n-1);
}
int main()
{
	int x,y;
	cin>>y;
	x=fact(y);
	cout<<x;
	return 0;
}
