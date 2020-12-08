#include <bits/stdc++.h>
using namespace std;

bool isUgly(int num) {
    if(num==0) return false;
    while(num%2==0) num/=2;
    while(num%3==0) num/=3;
    while(num%5==0) num/=5;
    if(num==1) return true;
    else return false;
}

int main()
{
	int n;
	cin>>n;
	if(isUgly(n)==1) cout<<"Given Number is an ugly number";
	else cout<<"Given Number is not an ugly number";
	return(0);
}
