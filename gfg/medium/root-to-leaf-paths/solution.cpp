/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void helper(Node * root,vector<vector<int>>&ans,vector<int>&v){
      if(root==NULL ) return ;
      v.push_back(root->data);
      if(root->left==NULL && root->right==NULL) {
         ans.push_back(v);
         v.pop_back();
         return;
       }
       
      helper(root->left,ans,v);
      helper(root->right,ans,v);
      v.pop_back();

    }
    vector<vector<int>> paths(Node* root) {
        if(root==NULL) return {};
        vector<vector<int>>ans;
        vector<int>v;
        helper(root,ans,v);
        return ans;
        
    }
};