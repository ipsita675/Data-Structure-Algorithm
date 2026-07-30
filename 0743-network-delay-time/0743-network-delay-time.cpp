class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto t:times){
            adj[t[0]-1].push_back({t[1]-1,t[2]});
        }

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});

        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;

        while(!pq.empty()){
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            if(dist[u]<d)continue;

            for(auto [v,w]:adj[u]){
                if(d+w<dist[v]){
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }

        return ans;
    }
};