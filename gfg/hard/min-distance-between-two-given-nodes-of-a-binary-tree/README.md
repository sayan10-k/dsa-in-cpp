# Min Distance Between Two in Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a binary tree with  **n** nodes and two node values  **a** and  **b**, find the minimum distance between them. The distance is defined as the minimum number of edges between the two nodes.

- It is guaranteed that both nodes exist in the binary tree and all node values are unique.
- If two given nodes are same, return 0.

 **Examples :** 

```
Input:
      
a = 2, b = 3
Output: 2
Explanation: The path between node 2 and node 3 is: 2 -> 1 -> 3.The number of edges in this path is 2, so the minimum distance is 2. 
```

```
Input:

a = 4, b = 7
Output: 4
Explanation: The path between node 4 and node 7 is: 4 -> 2 -> 1 -> 3 -> 7.The number of edges in this path is 4, so the minimum distance is 4.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-28T16:16:07.627Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1)