# Insert at Bottom of Stack

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a stack st containing n integers and an integer x, insert x at the bottom of the stack.

 **Note:**  While displaying the stack, the bottommost element is printed first.

 **Examples :** 

```
Input: st = [4, 3, 2, 1, 8], x = 2
Output: [2, 4, 3, 2, 1, 8]
Explanation: After insertion of 2, the final stack will be [2,4,3,2,1,8].
```

```
Input: st = [5, 3, 1], x = 4
Output: [4, 5, 3, 1]
Explanation: After insertion of 4, the final stack will be [4,5,3,1].
```

 **Constraints:** 
1 ≤ n ≤ 105
0 ≤ x, elements of stack ≤ 109

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T16:23:36.489Z  

```cpp
class Solution {
    void solve(stack<int> &st, int x) {
        
        if (st.empty()) {
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        
        solve(st, x);
        
        st.push(temp);
    }
    
    
  public:
    stack<int> insertAtBottom(stack<int> &st, int x) {
        solve(st,x);
        return st;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1)