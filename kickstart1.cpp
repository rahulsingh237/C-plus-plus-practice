#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    vector<int>r;
    int t,n,k,s,count1 = 0, count2 = 0,sum=0,q,ans;
    int re = 1;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        cin >> n >> k >> s;
        if(n>k && k>s)
        {
            count1=k-1;
            sum=re+count1+n;
            v.push_back(sum);
            
            count2=k-s;
            q=n-s+1;
            sum=count2+q+count1;
            r.push_back(sum);
        }
        if(v[i]>r[i])
        {
            ans=r[i];
        }
        else if(v[i]<r[i])
        {
            ans=v[i];
        }
        else if(v[i]==r[i])
        {
            ans=v[i];
        }
        cout<<"Case #"<<i+1<<": "<<ans;
    } 
}
