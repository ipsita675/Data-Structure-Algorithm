class DSU{
public:
    vector<int>par;
    vector<int>rank;

    DSU(int n){
        for(int i=0;i<=n;i++){
            par.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int x){
        if(x==par[x])return x;
        return par[x]=find(par[x]);
    }

    bool union_rank(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px==py)return false;
        if(rank[px]>rank[py])par[py]=px;
        else if(rank[px]<rank[py])par[px]=py;
        else{
            par[px]=py;
            rank[py]++;
        }

        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);
        for(auto e:edges){
            if(!dsu.union_rank(e[0],e[1]))return e;
        }

        return {};
    }
};