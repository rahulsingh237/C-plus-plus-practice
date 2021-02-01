//31 jan 2021 level up pep coding


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

    int l=maximumBT(n->left);
    int r=maximumBT(n->right);

    return max(max(l,r),n->val);
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

vector<TreeNode*> roottonode(TreeNode* n, TreeNode* data)
{
    if(n==nullptr){
        vector<TreeNode*> v;
        return v;
    }
    if(n==data)
    {
        vector<TreeNode*> bes;
        bes.push_back(n);
        return bes;
    }
    vector<TreeNode*> l=roottonode(n->left,data);
    if(l.size()>0)
    {
        l.push_back(n);
        return l;
    }

    vector<TreeNode*> r=roottonode(n->right,data);
    if(r.size()>0)
    {
        r.push_back(n);
        return r;
    }
    return vector<TreeNode*>();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> l1;
    vector<TreeNode*> l2;

    roottonode(root,p,l1);
    roottonode(root,q,l2);

    int i=l1.size()-1;
    int j=l2.size()-1;

    TreeNode* lca=NULL;

    while(i>=0 && j>=0)
    {
        if(l1[i]!=l2[j]) break;
        lca=l1[i];
        i--;
        j--;
    }
    return lca;
}

//--------------------------------------------------------------------------------------------------

void printKDown(TreeNode* node, TreeNode* block, int depth, vector<int>& ans) {
    if (node == nullptr || depth < 0 || node == block)
        return;

    if (depth == 0) {
        ans.push_back(node->val);
        return;
    }

    printKDown(node->left, block, depth - 1, ans);
    printKDown(node->right, block, depth - 1, ans);
}
//863 leetcode
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    
    vector<TreeNode*> v;
    roottonode(root, target, v);

    vector<int> ans;
    TreeNode* blockNode = nullptr;

    for (int i = 0; i < v.size(); i++) {
        printKDown(v[i], blockNode, K - i, ans);
        blockNode = v[i];
    }
    return ans;
}

int rootToNodeDistance(TreeNode* node, TreeNode* data) {
    if (node == nullptr)
        return -1;
    if (node == data)
        return 0;

    int lans = rootToNodeDistance(node->left, data);
    if (lans != -1)
        return lans + 1;

    int rans = rootToNodeDistance(node->right, data);
    if (rans != -1)
        return rans + 1;

    return -1;
}

//https://www.geeksforgeeks.org/burn-the-binary-tree-starting-from-the-target-node/