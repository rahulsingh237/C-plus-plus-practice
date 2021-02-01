#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
    }
};

int sizeBT(TreeNode* n)
{
    return n==nullptr ? 0:sizeBT(n->left)+sizeBT(n->right)+1;
}

int heightBT(TreeNode* n)
{
    return n==nullptr ? -1:max(heightBT(n->left),heightBT(n->right))+1;
}

int maximumBT(TreeNode* n)
{
    if(n==nullptr) return -1;

    int l=maximum(n->left);
    int r=maximum(n->right);

    return max(max(l,r),n);
}

bool find(TreeNode* n, int data)
{
    if(n==nullptr) return false;
    if(n->val==data) return true;

    return find(n->left,data) || find(n->right,data);
}

bool roottonode(TreeNode* n, TreeNode* data, vector<TreeNode*>& v)
{
    if(n==nullptr) return false;
    if(n==data){
        v.push_back(n);
        return true;
    }
    bool res=roottonode(n->left,data,v) || roottonode(n->right,data,v);
    if(res)
    {
        v.push_back(n);
    }
    return res;
}