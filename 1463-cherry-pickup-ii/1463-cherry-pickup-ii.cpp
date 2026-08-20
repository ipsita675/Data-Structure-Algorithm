class Solution {
public:
    int memo(int r1,int c1,int c2,int rows,int cols,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {

        if(r1>=rows || c1>=cols || c2>=cols || c1<0 || c2<0)return -1e9;
        if(r1==rows-1){
            if(c1==c2)return grid[r1][c1];
            return grid[r1][c1]+grid[r1][c2];
        }
        if(dp[r1][c1][c2]!=-1)return dp[r1][c1][c2];

        int cherries=(c1==c2) ? grid[r1][c1] : grid[r1][c1]+grid[r1][c2];

        int best=-1e9;
        for(int dc1=-1;dc1<=1;dc1++){
            for(int dc2=-1;dc2<=1;dc2++){
                best=max(best,memo(r1+1,c1+dc1,c2+dc2,rows,cols,grid,dp));
            }
        }

        if(best<0)return dp[r1][c1][c2]=-1e9;
        return dp[r1][c1][c2]=cherries+best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<vector<int>>>dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));

        int ans=memo(0,0,cols-1,rows,cols,grid,dp);
        return max(0,ans);
    }
};