#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s[24]={"Giant-Teddy-Bear","Giraffe","Cat","Mega-Bear","Dog","Lion","Billy-Bear","Besty-Bear","Monkey","Bobby-Bear","Bunny-Rabbit","Benjamin-bear","Kung-Fu-Panda","Brown-Bear","Pink-Bear","Baby-Elephant","Blue-Fish","Hippo","Cute-Pig","Pikachu","Doremon","Tortoise","Cater-Pillar","Candy-Doll"};
	int x=0,b;
	string c;
	
	
	cin>>c;
	for(int i=0;i<24;i++)
	{	
		if(c==s[i])
		{
			s[i]="";
			x++;
			i++;
		}
		if(c!=s[i])
		{	
			b=i+1-x;
			cout<<b<<"."<<s[i]<<" ";
		}
	}
}
