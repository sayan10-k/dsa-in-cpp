# Implement Stack using Queues

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:

- void push(int x) Pushes element x to the top of the stack.
- int pop() Removes the element on the top of the stack and returns it.
- int top() Returns the element on the top of the stack.
- boolean empty() Returns true if the stack is empty, false otherwise.

 **Notes:** 

- You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
- Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

 

 **Example 1:** 

```
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

```

 

 **Constraints:** 

- 1 <= x <= 9
- At most 100 calls will be made to push, pop, top, and empty.
- All the calls to pop and top are valid.

 

 **Follow-up:**  Can you implement the stack using only one queue?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.1 MB (beats 21.64%)  
**Submitted:** 2026-09-13T15:49:57.412Z  

```cpp
class MyStack {
public:
   queue<int>q1;
   queue<int>q2;


    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        
    }
    
    int pop() {
        if(empty()) return -1;

        
        int top=q1.front();
        q1.pop();
        return top;
        
    }
    
    int top() {
        if(empty()) return -1;
        return q1.front();
        
    }
    
    bool empty() {
        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

---

[View on LeetCode](https://leetcode.com/problems/implement-stack-using-queues/)