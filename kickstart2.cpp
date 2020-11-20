#include <iostream>
//#include<bits/stdc++.h>
using namespace std;
int main(){
     ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    int t;
    cin>>t;
    while(t--){
       int i=1;
       int s,k,n;
       cin>>n>>k>>s;
       int ti,di,di2,ttl;
       ti=k-1;
       di=k-s;
       di2=n-s+1;
       ttl=ti+di+di2;
       int bk,count=0;
       bk=k;
       if(bk!=1){
       bk--;
       count++;}
       int cal;
       cal=count+n+(k-1);
      
      int ans=min(cal,ttl);
      //cout<<k<<endl;
      cout<<"Case #"<<i++<<":"<<" "<<ans<<endl;}
       
    }
