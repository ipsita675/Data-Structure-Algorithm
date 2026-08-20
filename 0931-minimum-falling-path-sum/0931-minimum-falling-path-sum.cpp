class Solution {
public:
    int memo(int i,int j,int n,vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j<0 || j>=n)return 1e9;
        if(i==n-1)return matrix[i][j];
        if(dp[i][j]!=-1e9)return dp[i][j];

        int lf=memo(i+1,j-1,n,matrix,dp);
        int bt=memo(i+1,j,n,matrix,dp);
        int rh=memo(i+1,j+1,n,matrix,dp);

        return dp[i][j]=matrix[i][j]+min({lf,bt,rh});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,memo(0,j,n,matrix,dp));
        }

        return ans;
    }
};