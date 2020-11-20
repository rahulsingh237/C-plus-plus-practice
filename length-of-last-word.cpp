		
#include<bits/stdc++.h>
using namespace std;

int main()
{		string s="b a  ";
		vector <string> tokens; 
        stringstream check1(s); 
        string intermediate; 

        while(getline(check1, intermediate, ' ')) 
        { 
            tokens.push_back(intermediate); 
        } 

        intermediate=tokens[tokens.size()-1];
        return intermediate.length();
    }
