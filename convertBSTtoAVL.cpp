#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    int bal=0;
    int height=0;

    TreeNode(int val) {
        this->val = val;
    }
};

//=============================================================================

void updateheightandbal(TreeNode* root)
{
    if(root==nullptr) return;
    int lh=-1;
    int rh=-1; 

    if(root->left!=nullptr) lh=root->left->height;
    if(root->right!=nullptr) rh=root->right->height;

    root->bal=lh-rh;
    root->height=max(lh,rh)+1;
}

TreeNode* rightRotation(TreeNode* A)
{
    TreeNode* B=A->left;
    TreeNode* bkaright=B->right;

    B->right=A;
    A->left=bkaright;

    B->right=getRotation(A);
    return getRotation(B);
}

TreeNode* leftRotation(TreeNode* A)
{
    TreeNode* B=A->right;
    TreeNode* bkaleft=B->left;

    B->left=A;
    A->right=bkaleft;

    B->left=getRotation(A);
    return getRotation(B);
}

TreeNode* getRotation(TreeNode* root)
{
    if(root->bal>=2)
    {
        if(root->left->bal>=1)
        {
            return rightRotation(root);
        }
        else{
            root->left=leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else{
        if(root->bal<=-2)
        {
            if(root->right->bal<=-1)
            {
                return leftRotation(root);
            }
            else{
                root->right=rightRotation(root->right);
                return leftRotation(root);
            }
        }
    }
}

//=====================================================================

TreeNode* insertintoBST(TreeNode* root,int val)
{
    if(root==nullptr) return new TreeNode(val);

    if(root->left < val) return insertintoBST(root->left,val);
    else if(root->right>val) return insertintoBST(root->left,val);
    else{
        if(root->left==NULL || root->right==NULL)
        {
            return root->left!=nullptr ? root->left:root->right;
        }
    }

}