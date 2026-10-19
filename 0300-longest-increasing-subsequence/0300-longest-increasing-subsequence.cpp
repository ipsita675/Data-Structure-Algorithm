class Solution {
public:
    int memo(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size())return 0;
        if(dp[i][prev+1]!=-1)return 0;

        int len=0;
        if(prev==-1 || nums[i]>nums[prev])len=1+memo(i+1,i,nums,dp);
        len=max(len,memo(i+1,prev,nums,dp));

        return dp[i][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memo(0,-1,nums,dp);
    }
};