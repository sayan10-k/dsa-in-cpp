# Delete N After Every M in Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a linked list, delete  **n**  nodes after skipping  **m**  nodes of a linked list until the last of the linked list.

 **Examples:** 

```
Input: head: 9 -> 1 -> 3 -> 5 -> 9 -> 4 -> 10 -> 1, n = 1, m = 2

Output: 9 -> 1 -> 5 -> 9 -> 10 -> 1

Explanation: Deleting 1 node after skipping 2 nodes each time, we have list as 9 -> 1 -> 5 -> 9 -> 10 -> 1.
```

```
Input: head: 1 -> 2 -> 3 -> 4 -> 5 -> 6, n = 1, m = 6

Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

Explanation: After skipping 6 nodes for the first time, we will reach of end of the linked list, so, we will get the given linked list itself.
```

 **Constraints** :
1 <= size of linked list <= 104
1 <= n, m <= size of linked list

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T16:23:16.288Z  

```cpp
/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class Solution {
  public:
    void linkDelete(Node* head, int n, int m) {
        if (!head || m <= 0) return;
        
            Node* temp = head;
            
            while (temp != nullptr) {
                // Skip M-1 nodes
                for (int i = 1; i < m && temp != nullptr; i++){
                    temp = temp->next;
                    
                }
                
                if (temp == nullptr) return;
                // Delete N nodes
                
                Node* end = temp->next;
                
                for (int i = 0; i < n && end != nullptr; i++) {
                    Node* toDelete = end;
                    end = end->next;
                    delete toDelete;
                }
                temp->next = end;
                temp = end;
            }
        

        
        
        
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1)