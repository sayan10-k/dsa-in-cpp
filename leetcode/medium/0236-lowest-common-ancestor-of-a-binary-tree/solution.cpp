/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) {
            return root;
        }
        TreeNode* ltLCA=lowestCommonAncestor(root->left,p, q);
        TreeNode* rtLCA=lowestCommonAncestor(root->right,p, q);
        if(rtLCA!=NULL && ltLCA!=NULL) {
            return root;
        }
        return ltLCA==NULL?rtLCA:ltLCA;

        
    }
};