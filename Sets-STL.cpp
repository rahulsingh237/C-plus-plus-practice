#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int x,q,y,i,d;
    cin>>q;
    set<int>s; 
    for(i=0;i<q;i++)
    {
        cin>>y;
        if(y==1)
        {
            cin >> d;
            s.insert(d);
        }
        else if(y==2)
        {
            cin >> d;
            s.erase(d);
        }
        else if(y==3)
        {
            cin>>d;
            set<int>::iterator itr=s.find(d);
            if(itr!=s.end()){
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
    
    return 0;
}
