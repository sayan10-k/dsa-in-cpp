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