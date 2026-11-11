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