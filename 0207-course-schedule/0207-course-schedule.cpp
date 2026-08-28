class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        
        for(auto p:pre){
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            topo.push_back(v);

            for(auto u:adj[v]){
                indeg[u]--;
                if(indeg[u]==0)q.push(u);
            }
        }

        return topo.size()==n;
    }
};