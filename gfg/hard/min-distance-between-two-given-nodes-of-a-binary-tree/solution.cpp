/* A binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    Node* Lca(Node* root, int n1, int n2)  {
        if(root==NULL) return NULL;
        
        if(root->data==n1 || root->data==n2) {
            return root;
        }
        Node * lt=Lca(root->left,n1,n2);
        Node * rt=Lca(root->right,n1,n2);
        
        if(lt!=NULL && rt!=NULL) {
            return root;
        }
        return lt==NULL?rt:lt;
        
    }
    int dist_lca_to_n(Node * root,int n) {
        if(root==NULL) return -1;
        
        if(root->data==n) return 0;
        
        int lt=dist_lca_to_n(root->left,n);
        
        if(lt!=-1) {
            return lt+1;
        }
        
        
        int rt=dist_lca_to_n(root->right,n);
        
        if(rt!=-1) {
            return rt+1;
        }
        
        return -1;
        
    }
    
    int findDist(Node* root, int a, int b) {
        if(a==b) return 0;
        Node * lca=Lca(root,a,b);
        int dist1=dist_lca_to_n(lca,a);
        int dist2=dist_lca_to_n(lca,b);
        return dist1+dist2;
        
        
    }
};