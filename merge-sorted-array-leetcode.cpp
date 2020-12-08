#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(1);
	//vector<int> v;
    int x,m=3,n=3;
    for(auto it = nums1.begin(); it != nums1.end(); ++it)
    {
        if(*it==0)
        {
            nums1.erase(it);
        }
    }
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i];
    }
    /*nums1.resize(m);
    for(int i=0;i<m;i++)
    {
        x=nums2[i];
        nums1.push_back(x);
    }
    /*for(int i=0;i<n;i++)
    {
        x=nums2[i];
        v.push_back(x);
    }
    sort(nums1.begin(),nums1.end());
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i];
    }*/
    return 0;
}
