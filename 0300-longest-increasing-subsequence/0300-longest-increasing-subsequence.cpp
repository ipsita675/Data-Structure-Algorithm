class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memo(0,-1,n,nums,dp);
    }
    int memo(int i,int prev,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(i==n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int pick=0;
        if(prev==-1 || nums[i]>nums[prev])pick=1+memo(i+1,i,n,nums,dp);
        int notpick=memo(i+1,prev,n,nums,dp);

        return dp[i][prev+1]=max(pick,notpick);
    }
    
};