class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n,vector<int>(n,0));
        
        for(auto t:trust){
            adj[t[0]-1][t[1]-1]=1;
        }

        int possible=-1;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=adj[i][j];
            }
            if(sum==0){
                possible=i;
            }
        }

        if(possible==-1)return -1;

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=adj[i][possible];
        }

        return (sum == n - 1) ? possible + 1 : -1;
    }
};