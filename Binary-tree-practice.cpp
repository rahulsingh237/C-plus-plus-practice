#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9+7
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define mini(a, b, c) min(c, min(a, b))
#define mini(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
    }
};

int heightBT(TreeNode* n)
{
    return n==nullptr ? 0:max(heightBT(n->left),heightBT(n->right))+1;
}

int sizeBT(TreeNode* n)
{
    return n==nullptr ? -1:sizeBT(n->left)+sizeBT(n->right)+1;
}

int maximumBT(TreeNode* n)
{
    if(n==nullptr) return -1;

    int l=maximumBT(n->left);
    int r=maximumBT(n->right);

    return max(max(l,r),n->val);
}

bool findBT(TreeNode* n,TreeNode* data)
{
    if(n==nullptr) return false;
    if(n==data) return true;

    return findBT(n->left,data) || findBT(n->right,data);
}

bool roottonode(TreeNode* n, TreeNode* data, vector<TreeNode*>& v)
{
    if(n==nullptr) return false;
    if(n==data){
        v.push_back(n);
        return false;
    }
    bool a=roottonode(n->left,data,v)||roottonode(n->right,data,v);
    if(a) v.push_back(n);
    return a;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> l1;
    vector<TreeNode*> l2;
    
}