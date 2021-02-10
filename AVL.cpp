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
//=================================================================================

void updateheightandbal(TreeNode* root)
{
    if(root==nullptr) return;

    int lh = -1;
    int rh = -1;

    if(root->left==nullptr) lh=root->left->height;
    else rh=root->right->height;

    root->bal=lh-rh;
    root->height=max(lh,rh)+1;
}

TreeNode* leftrotation(TreeNode* A)
{
    TreeNode* B=A->right;
    TreeNode* bkaleft=B->left;

    B->left=A;
    A->right=bkaleft;

    updateheightandbal(A);
    updateheightandbal(B);

    return B;
}

TreeNode* rightrotation(TreeNode* A)
{
    TreeNode* B=A->left;
    TreeNode* bkaright=B->right;

    B->right=A;
    A->left=bkaright;

    updateheightandbal(A);
    updateheightandbal(B);

    return B;
}

TreeNode* getRotation(TreeNode* root)
{
    if(root->bal>=2)
    {
        if(root->left->bal>=1)
        {
            rightrotation(root);
        }else{ //lr
            root->left=leftrotation(root->left);
            return rightrotation(root);
        }
    }
    else if(root->bal<=-2)
    {
        if(root->right->val<=-1)
        {
            leftrotation(root);
        }else{
            root->right=rightrotation(root->right);
            return leftrotation(root);
        }
    }

    return root;
}

//basic BST========================================================================

TreeNode* insertIntoBST(TreeNode* root,int val)
{
    if(root==nullptr) return new TreeNode(val);

    if(val>root->val) return insertIntoBST(root->right,val);
    else if(val<root->val) return insertIntoBST(root->left,val);

    return root;
}

int maxEle(TreeNode* root)
{
    TreeNode* curr=root;
    while(curr->right!=nullptr)
    {
        curr=curr->right;
    }
    return curr->val;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    if(root->val>key) root->left=deleteNode(root->left,key);
    else if(root->val<key) root->right=deleteNode(root->right,key);
    else{
        if(root->left==nullptr || root->right==nullptr) return root->left!=nullptr ? root->left : root->right;

        int maxValue=maxEle(root->left);
        root->val=maxValue;

        root->left = deleteNode(root->left,maxValue);
    }
}