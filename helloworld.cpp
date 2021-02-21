#include<bits/stdc++.h>
using namespace std;


int main(){
    int a=5,b=6; 
    int *p=&a;
    cout<<"a="<<a<<endl;
    cout<<"&a="<<&a<<endl;
    cout<<"p"<<p<<endl;
    cout<<"*p"<<*p;
    return 0;
}
//a=3
cout<<a;
int change(int a)
{
    int x=6;
    a=x;
    return a;
}
cout<<a;

//*   p = *p

//       *p=&a;
//      /      \ 
//   p=&a     *p = a;
//    ||         ||
//p=0x6ffe0c    *p=5
int fact(int n){
if(n>=1) return n*fact(n-1);
else return 1;