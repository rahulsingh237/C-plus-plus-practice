#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q,x,i,y,c;
    string name;
    cin>>q;
    map<string,int>m;
    for(i=0;i<q;i++)
    {
        cin>>y;
        if(y==1)
        {
            cin>>name;
            cin>>x;
            map<string,int>::iterator itr=m.find(name);
            if(itr!=m.end())
            {
                m[name]=m[name]+x;
            }
            else{m.insert(make_pair(name,x));}
        }
        if(y==2)
        {
            cin>>name;
            m.erase(name);
        }
        if(y==3)
        {
            cin>>name;
            cout<<m[name]<<endl;
        }
    }
    return 0;
}



