# Reverse a Stack

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a stack  **st[].**  You have to reverse the stack.

 **Note:** The input array represents the stack from bottom to top (last element is the top). The output is displayed by printing elements from top to bottom after reversal.

 **Examples:** 

```
Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

```

```
Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: After reversing, the elements of stack are in opposite order.

```

 **Constraints:** 
1 ≤ st.size() ≤ 100
0 ≤ stack element ≤ 100

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T16:51:54.939Z  

```cpp
class Solution {
    void pushatbottom(stack<int> &st,int x){
        if(st.empty()) {
            st.push(x);
            return ;
        }
        int temp=st.top();
        st.pop();
        pushatbottom(st,x);
        st.push(temp);
        
        
    }
  public:
    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return ;
        }
        int temp=st.top();
        st.pop();
        reverseStack(st);
        pushatbottom(st,temp);
        
        
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/reverse-a-stack/1)