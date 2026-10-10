class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int>span(arr.size(),0);
        stack<int>st;
        st.push(0);
        span[0]=1;
        for(int i=1; i<arr.size(); i++) {
            int curr=arr[i];
            while(!st.empty() && arr[st.top()]<=curr) {
                st.pop();
            }
            if(st.empty()){
                span[i]=i+1;
            }
            else{
                int prevhigh=st.top();
                span[i]=i-prevhigh;
            }
            
            st.push(i);
        }
        return span;
        
        
    }
};