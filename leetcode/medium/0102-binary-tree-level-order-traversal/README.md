# Binary Tree Level Order Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, return  *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

 

 **Example 1:** 

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

```

 **Example 2:** 

```
Input: root = [1]
Output: [[1]]

```

 **Example 3:** 

```
Input: root = []
Output: []

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 2000].
- -1000 <= Node.val <= 1000

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 32.38%)  
**Memory:** 17 MB (beats 71.97%)  
**Submitted:** 2026-10-18T07:24:37.111Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal/)