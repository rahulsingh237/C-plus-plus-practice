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

//543
//-with heightBT function
//-method1
int diameterOfBinaryTree01(TreeNode* root) {
    if(root==nullptr) return -1;
    int leftTreeDia=diameterOfBinaryTree01(root->left);
    int rightTreeDia=diameterOfBinaryTree01(root->right);

    int leftheight=heightBT(root->left);
    int rightheight=heightBT(root->right);

    return max(max(leftTreeDia,rightTreeDia),leftheight+rightheight+2);
}

//method 2

vector<int> diameterOfBinaryTree02(TreeNode* root) {
    if(root==nullptr) return vector<int>{-1,-1};

    vector<int> l=diameterOfBinaryTree02(root->left);
    vector<int> r=diameterOfBinaryTree02(root->right);

    vector<int> ans(2);
    ans[0]=max(max(l[0],r[0]),l[1]+r[1]+2);
    ans[1]=max(l[1],r[1])+1;
    return ans;    
}

//Method 3

int maxdia=0;

int diameterOfBinaryTree03(TreeNode* root)
{
    if(root==nullptr) return -1;

    int l=diameterOfBinaryTree03(root->left);
    int r= diameterOfBinaryTree03(root->right);

    maxdia=max(maxdia,l+r+2);
    return max(l,r)+1;
}

//or
int diameterOfBinaryTree03(TreeNode* root, vector<int>& ans)
{
    if(root==nullptr) return -1;
    int l=diameterOfBinaryTree03(root->left,ans);
    int r=diameterOfBinaryTree03(root->right,ans);

    ans[0]=max(ans[0],l+r+2);
    return max(l,r)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    //return diameterOfBinaryTree01(root);
    //return diameterOfBinaryTree02(root)[0];
    //return maxdia;
    vector<int> a(1);
    diameterOfBinaryTree03(root,a);
    return a[0];
}
//112,113

//112
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==nullptr) return false;
    if(root->left==nullptr && root->right==nullptr) return targetSum-root->val==0;
    return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
}

//113 ---------/////------DOUBT------\\\\\\-------
void pathsum(TreeNode* root, int targetSum,vector<vector<int>>& res, vector<int>& s)
{
    if(root==nullptr) return;

    if(root->left==nullptr && root->right==nullptr)
    {
        if(targetSum-root->val==0)
        {
            s.push_back(root->val);
            res.push_back(s);
            s.pop_back();
        }
        return;
    }
    s.push_back(root->val);
    pathsum(root->left,targetSum-root->val,res,s);
    pathsum(root->left,targetSum-root->val,res,s);
    s.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum){
    vector<vector<int>> res;
    vector<int> s;
    return res;
}



////////////////////////////////////////////////////////////////////////

// 04/02/2021

//leetcode 124(watch video for this),437,98
