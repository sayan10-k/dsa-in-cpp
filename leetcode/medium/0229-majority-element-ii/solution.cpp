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