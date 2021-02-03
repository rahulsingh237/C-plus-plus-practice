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


int maxsumTree01(TreeNode* root, int& sum) {
    if(root==nullptr) return 0;
    if(root->left==nullptr && root->right==nullptr) return root->val;
    int l=maxsumTree01(root->left,sum);
    int r=maxsumTree01(root->right,sum);
    if(root->left && root->right)       
    {
        sum=max(sum,l+r+root->val);
        return max(l,r)+root->val;
    }
    return root->left==nullptr ? r+root->val:l+root->val;
}

int maxPathSum(TreeNode* root)
{
    int res=INT_MIN;
    maxsumTree01(root,res);
    return res;
}