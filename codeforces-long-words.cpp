#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
	int n,y,i;
	string s,x,z,a,c;
	vector<string> b;
	cin>>n;
	while(i<n)
	{
		cin>>s;
		if(s.size()<11)
		{
			b.push_back(s);
		}
		else
		{
			x=s.at(0);
			y=s.size();
			z=s.at(y-1);
			y=y-2;
			a=to_string(y);
			c=x+a+z;
			b.push_back(c);
		}
		i++;
	}
	for(int i=0;i<b.size();i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
