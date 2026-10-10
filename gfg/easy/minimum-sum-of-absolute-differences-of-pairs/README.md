# Minimum Sum of Absolute Differences of Pairs

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two arrays  **a**  and  **b**  of equal length, pair each element of array  **a**  to an element in array  **b**, such that the  **sum**  of the  **absolute differences** of all the pairs is **minimum** 

 **Examples:** 

```
Input: a = [4, 1, 8, 7], b = [2, 3, 6, 5]
Output: 6
Explanation:
If we take the pairings as (1,2), (4,3), (7,5), and (8,6), the sum will be S = |1 - 2| + |4 - 3| + |7 - 5| + |8 - 6| = 6.
It can be shown that this is the minimum sum we can get.

```

```
Input: a = [4, 1, 2], b = [2, 4, 1]
Output: 0
Explanation: If we take the pairings as (4,4), (1,1), and (2,2), the sum will be S = |4 - 4| + |1 - 1| +|2 - 2| = 0. 
It can be shown that this is the minimum sum we can get.
```

 **Constraints:** 
1 ≤ a.size() == b.size() ≤ 105
0 ≤ a[i] ≤ 104
0 ≤ b[i] ≤ 104

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T16:49:51.752Z  

```cpp
class Solution {
  public:
    int findMinSum(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int minsum=0;
        for(int i=0; i<a.size(); i++) {
            minsum+=abs(a[i]-b[i]);
            
        }
        return minsum;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimum-sum-of-absolute-differences-of-pairs/1)