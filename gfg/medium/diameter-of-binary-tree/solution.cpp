/* Structure of binary tree Node 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  int ans=0;
    int height(Node* root){
        if(root==NULL) {
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        ans=max(ans,lh+rh);
        return max(lh,rh)+1;
        
        
    }
    int diameter(Node* root) {
        height(root);
        return ans;
        
        // code here
        
    }
};