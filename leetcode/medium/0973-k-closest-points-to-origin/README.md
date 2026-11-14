# K Closest Points to Origin

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the  **X-Y**  plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the  **X-Y**  plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in  **any order**. The answer is  **guaranteed**  to be  **unique**  (except for the order that it is in).

 

Original
C++
 **Example 1:** 

```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

```

 **Example 2:** 

```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

```

 

 **Constraints:** 

- 1 <= k <= points.length <= 104
- -104 <= xi, yi <= 104

## Solution

**Language:** C++  
**Runtime:** 35 ms (beats 68.09%)  
**Memory:** 73.5 MB (beats 45.01%)  
**Submitted:** 2026-11-14T18:38:34.844Z  

```cpp
class Solution {
public:
    class info{
        public:
        int distsq;
        int row;
        info(int distsq,int row){
            this->distsq=distsq;
            this->row=row;

        }
        bool  operator < (const info & obj) const{
            return this->distsq > obj.distsq;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<info>v;
        vector<pair<int,int>>p;
        for(int i=0; i<points.size(); i++) {
            p.push_back(make_pair(points[i][0],points[i][1]));
        }
        for(int i=0; i<p.size(); i++) {
            long long distsq=(p[i].first * p[i].first)+(p[i].second * p[i].second);
            v.push_back(info(distsq,i));
        }

        priority_queue<info>pq(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0; i<k; i++) {
            ans.push_back(points[pq.top().row]);
            pq.pop();
        }

        return ans;


        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/k-closest-points-to-origin/)