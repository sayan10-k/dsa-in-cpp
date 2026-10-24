class Solution {
  public:
    int countNodes(Node* root) {
        if(root==NULL) {
            return 0;
        }
        int ltc=countNodes(root->left);
        int rtc=countNodes(root->right);
        return ltc+rtc+1;
    }
};