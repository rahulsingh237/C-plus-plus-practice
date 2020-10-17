#include<bits/stdc++.h>
#include<vector>
using namespace std;

int minMoves(vector<int> a)
{	int x,y,count=0;
	vector<int>::iterator i;
	vector<int>::iterator d;
	for(auto i=a.begin() ; i!=a.end() ; ++i)
	{for(auto d=a.begin()+1 ; d!=a.end() ; ++d)
	{
	
		if(i==d)
		{	
			a.erase(i);
			a.erase(d);
			count++;
		}
		else if(i!=d)
		{	
			a.erase(i);
			count++;
		}
		else
		{
			break;
		}
	}}
	return count;
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int j=0; j<n; j++)
	{
		cin>>a[j];
	}
	int result;
	result = minMoves(a);
	cout<<result;
	return 0;
}
