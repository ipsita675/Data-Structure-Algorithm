class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool>vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(vis[i])continue;

            queue<int>q;
            q.push(i);
            vis[i]=true;

            int nodes=0;
            int edge=0;

            while(!q.empty()){
                int v=q.front();
                q.pop();

                nodes++;
                edge+=adj[v].size();

                for(int u:adj[v]){
                    if(!vis[u]){
                        vis[u]=true;
                        q.push(u);
                    }
                }
            }

            edge/=2;
            if(edge==nodes* (nodes-1)/2)ans++;
        }

        return ans;
    }
};