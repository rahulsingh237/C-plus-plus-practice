#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,x,q;
    cin>>n;
    vector<int> v;
    vector<int>:: iterator it;
    vector<int> a;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    
    for(i=0;i<q;i++)
    {
        it=lower_bound(v.begin(), v.end(), a[i]);
        if(a[i]==v[(it-v.begin())])
        {
            cout<<"Yes "<<(it-v.begin())+1<<endl;
        }
        else
        {
            cout<<"No "<<(it-v.begin())+1<<endl;
        }
    }
    return 0;
}

