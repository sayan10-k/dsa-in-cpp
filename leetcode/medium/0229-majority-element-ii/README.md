# Majority Element II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array of size `n`, find all elements that appear more than `⌊n / 3⌋` times.

 

 **Example 1:** 

```
Input: nums = [3,2,3]
Output: [3]

```

 **Example 2:** 

```
Input: nums = [1]
Output: [1]

```

 **Example 3:** 

```
Input: nums = [1,2]
Output: [1,2]

```

 

 **Constraints:** 

- 1 <= nums.length <= 5 * 104
- -109 <= nums[i] <= 109

 

 **Follow up:**  Could you solve the problem in linear time and in `O(1)` space?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 23.6 MB (beats 94.14%)  
**Submitted:** 2026-10-10T16:33:05.104Z  

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
      int freq1=0,freq2=0;
      int ans1=0,ans2=0;
      for(int i=0; i<nums.size(); i++){

        if(ans1==nums[i]) freq1++;
        else if(ans2==nums[i]) freq2++;


        else if(freq1==0) {
            ans1=nums[i];
            freq1=1;
        }
        else if(freq2==0){
            ans2=nums[i];
            freq2=1;

        }
        
        else{
            freq1--;
            freq2--;
        }

      }
        //check present in arr
        vector<int>vec;
        int feq1=0,feq2=0;
        for(int i=0; i<nums.size(); i++) {
            if(ans1==nums[i]) {
                feq1++;
            }
            else if(ans2==nums[i]) {
                feq2++;
            }
            

        }
        if(feq1>floor(n/3)) {
            vec.push_back(ans1);
        }
        if(feq2>floor(n/3)) {
            vec.push_back(ans2);
        }
      

    

      return vec;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/majority-element-ii/)