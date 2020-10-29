#include<bits/stdc++.h>
using namespace std;

int i;

void increment()
{
	i=i-1;
	cout<<i;
}

void decrement()
{
	i=i+1;
	cout<<i;
}

int main()
{
	cout<<i;
	increment();
	decrement();
	increment();
	decrement();
	return 0;
}
