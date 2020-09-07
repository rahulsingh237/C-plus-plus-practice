#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	cout<<"Enter value of a,b,c : ";
	cin>>a>>b>>c;
	if(a<1||a>100||b<1||b>100||c<1||c>100){
     cout<<"Out of range:-";
     return 0; 
     }
    else if(a+b>c && b+c>a && c+a>b) 
	{
	if( ((c*c) == (b*b) + (a*a)) || ((a*a)==(b*b)+(c*c)) || ((b*b)==(c*c)+(a*a)) )
	{
		cout<<"Right angled triangle\n";
	}
	else if( ((c*c) > (b*b) + (a*a)) || ((a*a)>(b*b)+(c*c)) || ((b*b)>(c*c)+(a*a)) )
	{
		cout<<"Obtuse angled triangle\n";
	}
	else
	{
		cout<<"Acute angled triangle\n";
	}}
	else{
		cout<<"Not a triangle";
	}
	
	return 0;
}
