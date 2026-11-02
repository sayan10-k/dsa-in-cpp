# Validate Binary Search Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree,  *determine if it is a valid binary search tree (BST)*.

A  **valid BST**  is defined as follows:

- The left subtree of a node contains only nodes with keys strictly less than the node's key.
- The right subtree of a node contains only nodes with keys strictly greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

 

 **Example 1:** 

```
Input: root = [2,1,3]
Output: true

```

 **Example 2:** 

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- -231 <= Node.val <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 8.46%)  
**Memory:** 21.8 MB (beats 71.05%)  
**Submitted:** 2026-11-02T15:31:44.642Z  

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
    bool helper(TreeNode* root,TreeNode* min,TreeNode* max){
        if(root==NULL) return true;
        if(min!=NULL && min->val>=root->val) return false;
        if(max!=NULL && max->val<=root->val) return false;

        bool LT=helper(root->left,min,root);
        bool RT=helper(root->right,root,max);
        return LT && RT;
        


    }
    bool isValidBST(TreeNode* root) { 
        if(root==NULL) return false;
        TreeNode* min=NULL;
        TreeNode* max=NULL;
        bool ans=helper(root,min,max);
        return ans;


        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/validate-binary-search-tree/)