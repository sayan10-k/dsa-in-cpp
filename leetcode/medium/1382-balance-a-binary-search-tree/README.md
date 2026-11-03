# Balance a Binary Search Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary search tree, return  *a  **balanced**  binary search tree with the same node values*. If there is more than one answer, return  **any of them**.

A binary search tree is  **balanced**  if the depth of the two subtrees of every node never differs by more than `1`.

 

 **Example 1:** 

```
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

```

 **Example 2:** 

```
Input: root = [2,1,3]
Output: [2,1,3]

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- 1 <= Node.val <= 105

## Solution

**Language:** C++  
**Runtime:** 21 ms (beats 23.01%)  
**Memory:** 65.5 MB (beats 72.34%)  
**Submitted:** 2026-11-03T15:29:11.577Z  

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
   TreeNode*  balancedbst1(vector<int>&v,int st,int end) {
      if(st>end) {
         return NULL;
       }
      int mid=st+(end-st)/2;
      TreeNode * curr=new TreeNode(v[mid]);
      curr->left=balancedbst1(v,st,mid-1);
      curr->right=balancedbst1(v,mid+1,end);
      return curr;
   }
    void inorder(TreeNode* root,vector<int>&v) {
       if(root==NULL) return ;
       inorder(root->left,v);
       v.push_back(root->val);
       inorder(root->right,v);
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;
        vector<int>v;
        inorder(root,v);
        TreeNode* ans=balancedbst1(v,0,v.size()-1);
        return ans;
        

        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/balance-a-binary-search-tree/)