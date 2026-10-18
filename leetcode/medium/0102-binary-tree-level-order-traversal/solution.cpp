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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        if(root==NULL) return {};
        queue<TreeNode*>q;
       
        q.push(root);
        q.push(NULL);
        vector<int>curnode;
         
        while(!q.empty()){
            
           
            TreeNode * curr=q.front();
            q.pop();
            if(curr==NULL){
                
                ans.push_back(curnode);
                curnode.clear();
                if(q.empty()){
                    break;
                }
                q.push(NULL);

            }
            else{
                curnode.push_back(curr->val);
             if(curr->left!=NULL)  {
                 q.push(curr->left);
               }
             if(curr->right!=NULL)  {
                 q.push(curr->right);
               }
             

            }
            

        }
        return ans;
        
    }
};