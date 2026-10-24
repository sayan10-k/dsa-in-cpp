/* 
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
}; */

class Solution {
  public:
    vector<int> topView(Node *root) {
       queue<pair<Node*,int>>q;
       q.push(make_pair(root,0));
       map<int,int>m;
       while(!q.empty()) {
           pair<Node*,int> curr=q.front();
           q.pop();
           if(m.count(curr.second)==0) {
               m[curr.second]=curr.first->data;
               
           }
           if(curr.first->left!=NULL){
               pair<Node*,int>left1=make_pair(curr.first->left,curr.second-1);
               q.push(left1);
           }
           if(curr.first->right!=NULL){
               pair<Node*,int>right1=make_pair(curr.first->right,curr.second+1);
               q.push(right1);
               
               
           }
       }
       vector<int>ans;
       for(const auto& it:m) {
           ans.push_back(it.second);
           
       }
       return ans;
        
    }
};