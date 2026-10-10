class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0;
        int end=height.size()-1;
        int maxwater=INT_MIN;
        while(st<end) {
            int heights=min(height[st],height[end]);
            int width=end-st;
            int area=heights*width;

            maxwater=max(maxwater,area);

            if(height[st]<height[end]){
                st++;

            }
            else{
                end--;
            }
            


        }
        return maxwater;
        
    }
};