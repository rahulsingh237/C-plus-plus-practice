#include<bits/stdc++.h>
using namespace std;

class cse7a{
	protected:
	int x;
	public:
		int sum(int a,int b)
		{
			return a+b;
		}
};

int main()
{
	cse7a deepanshubajaj;
	int a,b,c;
	cin>>a>>b;
	c=deepanshubajaj.sum(a,b);
	cout<<c;
	return 0;
}
