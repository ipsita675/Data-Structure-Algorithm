class Solution {
public:
    int memo(int i,int j,int m, int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        if(i==m-1 && j==n-1)return 1;
        if(i==m || j==n)return 0;
        
        if(obstacleGrid[i][j])return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int down=memo(i,j+1,m,n,dp,obstacleGrid);
        int right=memo(i+1,j,m,n,dp,obstacleGrid);

        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])return 0;

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memo(0,0,m,n,dp,obstacleGrid);
    }
};