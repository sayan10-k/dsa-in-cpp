# Subtree of Another Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of` subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

 

 **Example 1:** 

```
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

```

 **Example 2:** 

```
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

```

 

 **Constraints:** 

- The number of nodes in the root tree is in the range [1, 2000].
- The number of nodes in the subRoot tree is in the range [1, 1000].
- -104 <= root.val <= 104
- -104 <= subRoot.val <= 104

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 38.75%)  
**Memory:** 28.8 MB (beats 92.23%)  
**Submitted:** 2026-10-21T07:50:03.585Z  

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
    bool isidentical(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL ) {
            return true;
        }
        if(root1==NULL || root2==NULL ) {
            return false;
        }
        if(root1->val != root2->val ) {
            return false;
        }
        return isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right);


    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL ) {
            return true;
        }
        if(root==NULL || subRoot==NULL ){
            return false;
        }
        if(root->val == subRoot->val ){
            if(isidentical(root,subRoot)){
                return true;

            }

        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot) ;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subtree-of-another-tree/)