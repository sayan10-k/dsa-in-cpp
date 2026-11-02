/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root,TreeNode* min,TreeNode* max){
        if(root==NULL) return true;
        if(min!=NULL && min->val>=root->val) return false;
        if(max!=NULL && max->val<=root->val) return false;

        bool LT=helper(root->left,min,root);
        bool RT=helper(root->right,root,max);
        return LT && RT;
        


    }
    bool isValidBST(TreeNode* root) { 
        if(root==NULL) return false;
        TreeNode* min=NULL;
        TreeNode* max=NULL;
        bool ans=helper(root,min,max);
        return ans;


        
    }
};