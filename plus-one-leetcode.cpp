#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
        string a;   
        for(int i=0;i<digits.size();i++)
        {
            string c = to_string(digits[i]);
            a=a+c;
        }
        long long b=stoll(a);
        b=b+1;
        a=to_string(b);  
        
        if(b>8)
        {
        digits.clear();
        for(int i=0;i<a.length();i++)
        {
            char d=a[i];
            int q=d-'0';
		    digits.push_back(q);
        }}
        else
        {
            auto it = digits.end()-1;
            int x = *it + 1;
            digits.pop_back();
            digits.push_back(x);        
        }
        return digits;
    }
int main(){
	vector<int> digits;
	digits.push_back(99);
    auto it = digits.end()-1;
    int x = *it + 1;
    digits.pop_back();
    string a;
    if(x<9 && x>=0) digits.push_back(x);        
    if(x>=9) 
    {
            
        for(int i=0;i<digits.size();i++)
        {
        	string c = to_string(digits[i]);
        	a=a+c;
        }
        int b=stoi(a);
        b=b+1;
        //digits.push_back(b);
        cout<<a;
        //digits.push_back(1);
        //digits.push_back(0);
    }
    return 0;
}

