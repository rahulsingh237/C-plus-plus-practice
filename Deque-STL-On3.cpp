#include <iostream>
#include <deque> 
#include <bits/stdc++.h> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> q;
    int c,a[k],m,j=0;
    for(int i=0;n-i>=k;i++)
    {
        for(int j=0;j<k;j++)
        {
            a[j]=arr[i+j];
        }
        m = sizeof(a) / sizeof(a[0]);
        c=*max_element(a,a+m);
        q.push_back(c);
        
    }
    for(int i=0;i<q.size();i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<endl;
    q.clear();
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

