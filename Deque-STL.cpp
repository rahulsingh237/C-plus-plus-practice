#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque <int> q ; 
    int count = 0 , i = 0 , max = arr[0] ; 
    while( count != k )
    {
        count++ ; 
        q.push_back(arr[i]);
        if( q.back() > max)
        {
            max = arr[i] ;
        }
        i++ ; 
    }
    cout << max <<" " ;
    while( count++ < n )
    {
        if( q.front() != max )
        {
            q.pop_front();
        }
        else {
            q.pop_front() ;
            max = 0 ; 
            deque <int> :: iterator it;      
            for (it = q.begin(); it != q.end(); ++it) 
            {
                if(*it > max)
                {
                    max = *it ;
                }
            }
                        
        }
        q.push_back(arr[i]);
        if(q.back() > max)
        {
            max = q.back() ;
        }
        i++;
        cout << max << " " ;
    }
    cout << "\n" ;

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
