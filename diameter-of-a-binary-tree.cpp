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

//method-1

int heightBT(TreeNode* root)
{
    return root==nullptr ? -1:max(heightBT(root->left),heightBT(root->right))+1;
}

int diameterOfBinaryTree01(TreeNode* root) {
    if(root==nullptr) return -1;

    int l=diameterOfBinaryTree01(root->left);
    int r=diameterOfBinaryTree01(root->right);

    int lh=heightBT(root->left);
    int rh=heightBT(root->right);

    return max(max(l,r),lh+rh+2);
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