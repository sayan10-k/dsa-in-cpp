/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    class info{
        public:
        bool isBst;
        int min;
        int max;
        int size;
        info(bool isBst,int min,int max,int size){
            this->isBst=isBst;
            this->min=min;
            this->max=max;
            this->size=size;
            
        }
    };
     int maxbst=0;
    info * largestbst1(Node * root){
        if(root==NULL){
            return new info(true,INT_MAX,INT_MIN,0);
            
        }
        info * leftinfo=largestbst1(root->left);
        info * rightinfo=largestbst1(root->right);
        int currmin=min(root->data,min(leftinfo->min,rightinfo->min));
        int currmax=max(root->data,max(leftinfo->max,rightinfo->max));
        int currsize=leftinfo->size+rightinfo->size+1;
        
        if(leftinfo->isBst && rightinfo->isBst && root->data > leftinfo->max  && root->data < rightinfo->min){
            maxbst=max(currsize,maxbst);
            return new info(true,currmin,currmax,currsize);
            
        }
        
        return new info(false,currmin,currmax,currsize);
        
        
        
    }
    int largestBst(Node *root) {
        
        largestbst1(root);
        return maxbst;
        
        
        
        
        
    }
};