# Largest BST Subtree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given the  **root**  of a binary tree, find the size of the largest subtree that is also a Binary Search Tree (BST). A subtree is considered a BST if, for every node in the subtree:

- All nodes in its left subtree have values less than the node's value.
- All nodes in its right subtree have values greater than the node's value.
- The subtree contains no duplicate values.

Return the number of nodes in the largest BST subtree.

 **Note:** The size of a subtree is the total number of nodes it contains.

 **Examples :** 

```
Input: root = [5, 2, 4, 1, 3]

Output: 3
Explanation:The following sub-tree is a BST of size 3

```

```
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-05T18:39:51.040Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/largest-bst/1)