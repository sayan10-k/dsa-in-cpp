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
    int  height(TreeNode* root){
        if(root==NULL) return 0;
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        return max(leftheight,rightheight)+1;


    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int currdiameter=height(root->left) + height(root->right) +1 -1;
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        return max(currdiameter,max(ld,rd));
    

        
    }
};