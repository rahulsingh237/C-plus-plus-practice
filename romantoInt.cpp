#include<bits/stdc++.h>
using namespace std;

    int value(char a)
    {
        if(a=='I')
            return 1;
        if(a=='V')
            return 5;
        if(a=='X')
            return 10;
        if(a=='L')
            return 50;
        if(a=='C')
            return 100;
        if(a=='D')
            return 500;
        if(a=='M')
            return 1000;
        
        return -1;
    }
    int romanToInt(string s) {
        int x=0,y,z;
        
        for(int i=0;i<s.length();i++)
        {
            y=value(s[i]);
            
            if((i+1)<s.length())
            {  z=value(s[i+1]);
                
                if(y>=z)
                    x=x+y;
                else
                {   
                    x=x+z-y;
                    i++;
                }
            }
            else{
                x=x+y;
                i++;
            }   
        }
        return x;
    }
    
    int main()
    {
    	string s="III";
    	int x=0;
    	x=romanToInt(s);
    	cout<<x;
	}
