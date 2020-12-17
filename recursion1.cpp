#include<bits/stdc++.h>
using namespace std;

void inc(int a,int b)
{
	if(a==b+1) return;
	cout<<a;
	inc(a+1,b);
	
}

int main()
{
	int x,y;
	cin>>x>>y;
	inc(x,y);
	return 0;
}
