# Top View of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

- Return the nodes from the leftmost node to the rightmost node.
- If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

 **Examples:** 

```
Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
```

```
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-24T18:33:12.358Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)