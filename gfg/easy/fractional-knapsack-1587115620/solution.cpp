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
