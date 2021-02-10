#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
    }
};

TreeNode* createBST(vector<int>& a, int startindex,int endindex)
{
    if(startindex>endindex)
    int mid=(startindex+endindex)/2;
    TreeNode* node=new TreeNode(a[mid]);

    node->left=createBST(a,startindex,mid-1);
    node->right=createBST(a,mid+1,endindex);
    return node;
}