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