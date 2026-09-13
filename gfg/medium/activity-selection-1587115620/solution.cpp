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