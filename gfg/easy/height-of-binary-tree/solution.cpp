/* Structrue of Binary Tree Node
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
    int height1(Node* root){
        if(root==NULL) return 0;
       int lht=height1(root->left);
       int  rht=height1(root->right);
        return max(lht,rht) +1;
        
    }
    int height(Node* root) {
        // code here
        return height1(root)-1;
    }
};