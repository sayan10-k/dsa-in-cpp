# Height of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the  **root** of a binary tree, find the maximum depth of the tree.

 **Note:** The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.

 **Examples:** 

```
Input: root = [12, 8, 18, 5, 11]

Output: 2
Explanation: One of the longest path from the root(node 12) goes through node 8 to node 5, which has 2 edges.
```

```
Input: root = [1, 2, 3, 4, N, 10, 5, N, N, N, N, 6, 7]

Output: 3
Explanation: The longest path from the root(node 1) to a leaf node 6 with 3 edges.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-26T15:03:03.919Z  

```cpp
/* Structrue of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int height1(Node* root){
        if(root==NULL) return 0;
       int lht=height1(root->left);
       int  rht=height1(root->right);
        return max(lht,rht) +1;
        
    }
    int height(Node* root) {
        // code here
        return height1(root)-1;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1)