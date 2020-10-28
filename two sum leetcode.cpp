#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums; int target = 6;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
        vector<int> n;
        for (int i = 0,j=i+1 ; j<=nums.size(); ) {



            if(target == ( nums[i]+nums[j] )){
                 n.push_back(i);
                 n.push_back(j);
                 break;
            }
            if(j == nums.size()){
                i++;
                j=i+1;
                continue;
            }
            j++;
        }
        for(int i=0;i<n.size();i++){
            cout<<n[i];
        }
    return 0;
}
