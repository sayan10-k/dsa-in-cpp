# Heap Sort

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]**. The task is to sort the array elements by Heap Sort.

 **Examples:** 

```
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7, 9.

```

```
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.

```

```
Input: arr[] = [2, 1, 5]
Output: [1, 2, 5]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 5.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-11T12:04:29.769Z  

```cpp
class Solution {
  public:
    void heapify(int i,vector<int>&arr,int n){
        int maxidx=i;
        int lc=i*2+1;
        int rc=i*2+2;
        if(lc<n && arr[lc]  > arr[maxidx]) {
            maxidx=lc;
        }
        if(rc<n && arr[rc]  > arr[maxidx]) {
            maxidx=rc;
        }
        swap(arr[i],arr[maxidx]);
        
        if(i!=maxidx) {
            heapify(maxidx,arr,n);
        }
        
        
    }
    void heapSort(vector<int>& arr) {
        int n= arr.size();
        // code here
        for(int i=n/2-1; i>=0; i--){
            heapify(i,arr,n);
        
        }
        
        for(int i=n-1; i>=0; i--){ 
            swap(arr[0],arr[i]);
            
            heapify(0,arr,i);
        }
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/heap-sort/1)