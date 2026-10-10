# Interleave the First Half of the Queue with Second Half

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a queue  **q**  of  **even** size, rearrange the queue by interleaving its  **first half** with the **second half**.

 **Interleaving**  is the process of mixing two sequences by alternating their elements while preserving their relative order.
In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and again second element from the first half and then second element from the 2nd half and so on.

 **Examples:** 

```
Input: q = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
Explanation: We place the first element of the first half 2 and after that place the first element of second half 3 and after that repeat the same process one more time so the resulting queue will be [2, 3, 4, 1]
```

```
Input: q = [3, 5]
Output: [3, 5]
Explanation: We place the first element of the first half 3 and first element of the second half 5 so the resulting queue is [3, 5]
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T16:50:21.667Z  

```cpp
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n=q.size();
        queue<int>q1;
        for(int i=1; i<=n/2; i++) {
          q1.push(q.front());
          q.pop();
        }
        while(!q1.empty()){
          q.push(q1.front());
          q1.pop();
          q.push(q.front());
          q.pop();
        }
       
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1)