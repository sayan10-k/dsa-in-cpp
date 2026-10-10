class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n=q.size();
        queue<int>q1;
        for(int i=1; i<=n/2; i++) {
          q1.push(q.front());
          q.pop();
        }
        while(!q1.empty()){
          q.push(q1.front());
          q1.pop();
          q.push(q.front());
          q.pop();
        }
       
        
    }
};