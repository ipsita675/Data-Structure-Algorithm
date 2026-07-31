class Solution {
public:
    long long dist(int x,int y){
        return x*x+y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<long long,pair<int,int>>>pq;
        for(auto p:points){
            pq.push({dist(p[0],p[1]),{p[0],p[1]}});
            if(pq.size()>k)pq.pop();
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            auto [x,y]=pq.top().second;
            ans.push_back({x,y});
            pq.pop();
        }

        return ans;
    }
};