# Activity Selection

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two arrays **start[]** and  **finish[]**, where start[i] and finish[i] represent the start time and finish time of the i-th activity, find the maximum number of activities that a single person can perform.

A person can perform only one activity at a time, and no two selected activities can overlap. If an activity finishes at time x, the next selected activity must start at a time greater than x.

 **Examples:** 

```
Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: One possible selection is activities {0, 1, 3, 4} with time intervals (1, 2), (3, 4), (5, 7), and (8, 9). Each activity starts after the previous one finishes, so a total of 4 activities can be performed.
```

```
Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]
Output: 1
Explanation: Activity 0 finishes at time 20, and activity 2 also starts at time 20. Since the next activity must start after the previous one finishes, they cannot both be selected. Hence, only one activity can be performed.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-13T15:44:14.929Z  

```cpp
class Solution {
  public:
  
    static bool compare(pair<int,int>&p1,pair<int,int>&p2){
     return p1.second < p2.second;
   }
  
  
  
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n=finish.size();
        if(n==0) return 0;
        vector<pair<int,int>>vec(n);
        
        
        for(int i=0; i<finish.size(); i++) {
            vec[i]={start[i],finish[i]};
            
        }
        sort(vec.begin(),vec.end(),compare);
        int firstactivity=vec[0].second;
        
        int ans=1;
        for(int i=1; i<finish.size(); i++) {
            if(firstactivity<vec[i].first){
                firstactivity=vec[i].second;
                ans++;
                
            }
        }
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1)