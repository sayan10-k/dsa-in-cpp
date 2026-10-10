# Decode String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there will not be input like `3a` or `2[4]`.

The test cases are generated so that the length of the output will never exceed `105`.

 

 **Example 1:** 

```
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

```

 **Example 2:** 

```
Input: s = "3[a2[c]]"
Output: "accaccacc"

```

 **Example 3:** 

```
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

```

 

 **Constraints:** 

- 1 <= s.length <= 30
- s consists of lowercase English letters, digits, and square brackets '[]'.
- s is guaranteed to be a valid input.
- All the integers in s are in the range [1, 300].

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.8 MB (beats 9.34%)  
**Submitted:** 2026-10-10T16:24:03.677Z  

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<string>mainstack;
        stack<int>numberst;
        
        
        for(int i=0; i<s.length(); i++) {
            char ch=s[i];
            if(ch>='0'  && ch<='9') {
                int ans=0;
                while(i<s.length() && s[i]>='0'  && s[i]<='9') {
                    ans=ans*10 + (s[i] - '0');
                    i++;

                }
                numberst.push(ans);
                i--;
            }
            else if(ch!=']'){
                mainstack.push(string(1,ch));

            }
            else{//closing
                string ans="";
                

                while(!mainstack.empty() && mainstack.top() != "["){
                    ans=mainstack.top() + ans;
                    mainstack.pop();
                }
                mainstack.pop();
                

                int number=numberst.top();
                numberst.pop();
                string repatedstring="";
                while(number>0) {
                    repatedstring=repatedstring + ans;
                    number--;
                }
                mainstack.push(repatedstring);

                
                
                
            }

        }

        string res="";
        while(!mainstack.empty()) {
            res= mainstack.top() + res;
            mainstack.pop();
        }
        return res;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/decode-string/)