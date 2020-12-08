#include<bits/stdc++.h>
using namespace std;

int main() {
        int count = 0;
        string s;
        cin>>s;
        int i=s.size()-1;
        while(s[i] == ' ' && i>=0)
        {
            i--;
        }
        while(s[i] != ' ' && i>=0)
        {
            count++;
            i--;
        }

        cout<<count;
        return 0;
    }
