#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int val) {
        this->val = val;
    }
};

TreeNode* createBST(vector<int>& a, int startindex,int endindex)
{
    if(startindex>endindex)
    int mid=(startindex+endindex)/2;
    TreeNode* node=new TreeNode(a[mid]);

    node->left=createBST(a,startindex,mid-1);
    node->right=createBST(a,mid+1,endindex);
    return node;
}

void predSuccInBST(TreeNode* root,int data)
{
    TreeNode* curr = root;
    TreeNode* pred = NULL;
    TreeNode* succ = NULL;

    bool ispresent = false;

    while(curr!=nullptr)
    {
        if(curr->val == data)
        {
            ispresent=true;
            if(curr->left!=NULL){
                pred=curr->left;
                while(pred->right!=nullptr)
                {
                    pred=pred->right;
                }
            }
            if(curr->right!=NULL){
                succ=curr->right;
                while(succ->left!=NULL)
                {
                    succ=succ->left;
                }
            }
            break;
        }else if(curr->val < data)
        {
            pred=curr;
            curr=curr->right;
        }
        else{
            succ=curr;
            curr=curr->left;
        }
        
    }
}


//510 inorder successor BST ii

TreeNode* inordersuccessor(TreeNode* root)
{
    if(root->right!=nullptr)
    {
        root=root->right;
        while(root->left!=nullptr) root=root->left;
        return root;
    }else{
        while(root!=nullptr){
            if(root->parent !=nullptr && root->parent->left==root) return root->parent;
        }
        root=root->parent;
    }
    return NULL;
}