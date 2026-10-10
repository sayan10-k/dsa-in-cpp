# Fractional Knapsack

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two arrays,  **val[]** and  **wt[]** , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

 **Examples :** 

```
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

```

```
Input: val[] = [500], wt[] = [30], capacity = 10
Output: 166.670000
Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T16:19:19.847Z  

```cpp
class Solution {
  public:
   static bool compare(pair<double,int>p1, pair<double,int>p2){
       return p1.first > p2.first;
       
   }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        int m=wt.size();
        if(n!=m) return 0.0;
        
        
        
        vector<pair<double,int>>ratio(n,make_pair(0.0,0));
        for(int i=0; i<val.size(); i++) {
            double r=val[i] / (double) wt[i];
            ratio[i]=make_pair(r,i);
        }
        
        sort(ratio.begin(),ratio.end(),compare);
        double ans=0.0;
        
        for(int i=0; i<val.size(); i++) {
            int idx=ratio[i].second;
            
            if(capacity>=wt[idx]){
                ans+=val[idx];
                capacity=capacity-wt[idx];
                
            }
            else{
                ans+=ratio[i].first * capacity;
                capacity=0;
                break;
            }
            
        }
        return ans;
        
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)