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
**Runtime:** 1 ms (beats 39.34%)  
**Memory:** 28.9 MB (beats 67.18%)  
**Submitted:** 2026-10-24T14:52:37.700Z  

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
    
        bool lt= isidentical(root1->left,root2->left);
        bool rt=isidentical(root1->right,root2->right);
        return lt && rt;


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
        bool lst=isSubtree(root->left,subRoot);
        bool rst=isSubtree(root->right,subRoot) ;
        return lst || rst;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subtree-of-another-tree/)