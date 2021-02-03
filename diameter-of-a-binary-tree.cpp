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

int diameterOfBinaryTree02(TreeNode* root) {
    if(root==nullptr) return vector<int>(-1,-1);

}

int diameterOfBinaryTree(TreeNode* root) {
    //return diameterOfBinaryTree01(root);
}