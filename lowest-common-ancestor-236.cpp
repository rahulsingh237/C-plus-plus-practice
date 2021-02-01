#include<bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:

bool roottonode(TreeNode* n,TreeNode* d,vector<TreeNode*>&v)
{
    if(n==NULL) return false;
    if(n==d){
        v.push_back(n);
        return true;
    }
    bool res=roottonode(n->left,d,v) || roottonode(n->right,d,v);
    if(res)
    {
        v.push_back(n);
    }
    return res;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> l1;
    vector<TreeNode*> l2
    TreeNode* LCA = NULL;
    roottonode(root,p,l1);
    roottonode(root,q,l2);

    int i=l1.size()-1;
    int j=l2.size()-1;

    while(i>=0 && j>=0)
    {
        if(l1[i]!=l2[j]) break;
        LCA = l1[i];
        i--;
        j--;
    }

    return LCA;
}
};