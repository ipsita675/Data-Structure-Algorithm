class Solution {
public:
    //r1+c1=c2+r2
    int memo(int r1,int c1,int c2,int n,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {
        int r2=r1+c1-c2;

        if(r1>=n || c1>=n || r2<0 || r2>=n || c2>=n)return -1e9;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)return -1e9;

        if(r1==n-1 && c1==n-1)return grid[r1][c1];
        if(dp[r1][c1][c2]!=-1)return dp[r1][c1][c2];

        int cherries=(r1==r2 && c1==c2) ? grid[r1][c1] : grid[r1][c1]+grid[r2][c2];

        int dd=memo(r1+1,c1,c2,n,grid,dp);
        int dr=memo(r1+1,c1,c2+1,n,grid,dp);
        int rd=memo(r1,c1+1,c2,n,grid,dp);
        int rr=memo(r1,c1+1,c2+1,n,grid,dp);

        int best_next=max({dd,dr,rd,rr});
        if(best_next<0)return dp[r1][c1][c2]=-1e9;

        return dp[r1][c1][c2]=cherries+best_next;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));

        int ans=memo(0,0,0,n,grid,dp);
        return max(0,ans);
    }
};