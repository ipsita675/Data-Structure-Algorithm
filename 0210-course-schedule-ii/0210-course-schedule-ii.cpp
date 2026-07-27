class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>indeg(n);
        for(auto p:pre){
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indeg[i])q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            ans.push_back(v);
            for(auto u:adj[v]){
                indeg[u]--;
                if(indeg[u]==0)q.push(u);
            }
        }

        if(ans.size()!=n)return {};
        return ans;
    }
};