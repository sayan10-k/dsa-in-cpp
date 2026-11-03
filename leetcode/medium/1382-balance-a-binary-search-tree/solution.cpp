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
   TreeNode*  balancedbst1(vector<int>&v,int st,int end) {
      if(st>end) {
         return NULL;
       }
      int mid=st+(end-st)/2;
      TreeNode * curr=new TreeNode(v[mid]);
      curr->left=balancedbst1(v,st,mid-1);
      curr->right=balancedbst1(v,mid+1,end);
      return curr;
   }
    void inorder(TreeNode* root,vector<int>&v) {
       if(root==NULL) return ;
       inorder(root->left,v);
       v.push_back(root->val);
       inorder(root->right,v);
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;
        vector<int>v;
        inorder(root,v);
        TreeNode* ans=balancedbst1(v,0,v.size()-1);
        return ans;
        

        
    }
};